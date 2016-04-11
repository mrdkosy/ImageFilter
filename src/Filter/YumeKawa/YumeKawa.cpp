#include "YumeKawa.hpp"

ofShader & YumeKawa::load(){
    
    shader.load("", "shader/yumekawa.frag");
    vignetteCenter = ofVec2f(0.5, 0.5);
    vignetteColor = ofVec3f(1, 1, 1);
    vignetteStart = 0.3;
    vignetteEnd = 0.75;
    
    hsv_s = 1.40;
    hsv_v = 1.45;
    
    return shader;
}
void YumeKawa::uniform(string name, ofFbo & fbo){
    
    shader.setUniformTexture(name, fbo.getTexture(), 1);
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform2f("vignetteCenter", vignetteCenter);
    shader.setUniform3f("vignetteColor", vignetteColor);
    shader.setUniform1f("vignetteStart", vignetteStart);
    shader.setUniform1f("vignetteEnd", vignetteEnd);
    shader.setUniform1f("hsv_s", hsv_s);
    shader.setUniform1f("hsv_v", hsv_v);
    
}
