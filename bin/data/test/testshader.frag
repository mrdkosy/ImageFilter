uniform sampler2DRect inputImageTexture;
uniform vec2 u_resolution;
uniform vec2 vignetteCenter;
uniform vec3 vignetteColor;
uniform float vignetteStart;
uniform float vignetteEnd;
uniform float hsv_s;
uniform float hsv_v;

vec3 Hue( float hue ){
    vec3 rgb = fract(hue + vec3(0.0,2.0/3.0,1.0/3.0));
    rgb = abs(rgb*2.0-1.0);
    return clamp(rgb*3.0-1.0,0.0,1.0);
}

vec3 HSVtoRGB( vec3 hsv ){
    return ((Hue(hsv.x)-1.0)*hsv.y+1.0) * hsv.z;
}

vec3 RGBtoHSV ( vec3 c ){
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));
    
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    
    float h = abs(q.z + (q.w - q.y) / (6.0 * d + e));
    float s = d / (q.x + e)*hsv_s;
    float v = q.x*hsv_v;
    return vec3(h, s, v);
}

vec3 whiteSpread( vec3 w ){
    float level = .9;
//    if( min(w.r, min(w.g, w.b) ) > level ) return vec3(1.0);
    if( w.r > level) return vec3(1.0, w.g, w.b);
    else return w;
}

void main(){
    vec2 uv = gl_FragCoord.xy;
    vec4 sourceImageColor = texture2DRect(inputImageTexture, uv);
    //端を白く
    float d = distance(uv/u_resolution.xy, vec2(vignetteCenter.x, vignetteCenter.y));
    float percent = smoothstep(vignetteStart, vignetteEnd, d);
    vec3 _mix = mix(sourceImageColor.rgb, vignetteColor, percent);
    
    //画像の色合いをはっきり
    _mix = HSVtoRGB( RGBtoHSV( _mix ) );
//    _mix = whiteSpread(_mix);
    float alpha = sourceImageColor.a;
    gl_FragColor = vec4(_mix, alpha);
}


