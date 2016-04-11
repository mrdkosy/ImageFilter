uniform vec2 u_resolution;
uniform int NUM_POINTS;
uniform vec2 verts[2*200];
uniform vec3 colors[3*200];

void main(){
    vec2 coord = gl_FragCoord.xy/u_resolution.xy;
    //    vec4 sourceImageColor = texture2DRect(image, coord);
    //    vec2 coord = gl_TexCoord[0].xy;
    
    float dist = 1e10;
    vec3 color = vec3(1.0, 0.0, 0.0);
    for (int i = 0; i < NUM_POINTS; i++) {
        float newdist = distance(verts[i], coord);
        if (newdist < dist) {
            if (dist - newdist < 0.01) {
                float d = dist - newdist;
                color = mix(vec3(0.), colors[i], d/0.01);
            }
            else {
                color = colors[i];
            }
            dist = newdist;
        }
    }
    gl_FragColor = vec4(color, 1.0);
    
    
}
