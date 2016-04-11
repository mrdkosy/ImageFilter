uniform vec2 u_resolution;
uniform sampler2DRect inputImageTexture;
uniform vec2 vignetteCenter;
uniform vec3 vignetteColor;
uniform float vignetteStart;
uniform float vignetteEnd;

void main() {
    vec2 uv = gl_FragCoord.xy;
    vec4 sourceImageColor = texture2DRect(inputImageTexture, uv);
    //    gl_FragColor = vec4(sourceImageColor);
    
    float d = distance(uv/u_resolution.xy, vec2(vignetteCenter.x, vignetteCenter.y));
    float percent = smoothstep(vignetteStart, vignetteEnd, d);
    vec3 _mix = mix(sourceImageColor.rgb, vignetteColor, percent);
    float alpha = sourceImageColor.a;
    gl_FragColor = vec4(_mix, alpha);
}
