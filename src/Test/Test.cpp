#include "Test.hpp"

void Test::setup(){
    shader.load("", "testshader.frag");
    inputImage.load("img/FullSizeRender 10.jpg");
    vignetteCenter = ofVec2f(0.5, 0.5);
    vignetteColor = ofVec3f(.75, .75, .75);
    vignetteStart = 0.35;
    vignetteEnd = 0.65;
    
    gui.setup();
    isDraw = true;
    //init, min, max
    gui.add(hsv_s.setup("hsv s: ", 1.40, 1.0, 3.0));
    gui.add(hsv_v.setup("hsv v: ", 1.45, 1.0, 3.0));
    
    //image
    inputImageTexture.allocate(ofGetWidth(), ofGetHeight());
    inputImageTexture.begin();
    float x = inputImage.getWidth()/ofGetWidth();
    float y = inputImage.getHeight()/ofGetHeight();
    if(x < y){
        float x = inputImage.getWidth()/y;
        imagePositionSize.x = ofGetWidth()/2-x/2;
        imagePositionSize.y = 0;
        imagePositionSize.z = x;
        imagePositionSize.w = ofGetHeight();
        inputImage.draw(imagePositionSize.x, imagePositionSize.y, imagePositionSize.z, imagePositionSize.w);
    }else{
        float y = inputImage.getHeight()/x;
        imagePositionSize.x = 0;
        imagePositionSize.y = ofGetHeight()/2-y/2;
        imagePositionSize.z = ofGetWidth();
        imagePositionSize.w = y;
        inputImage.draw(imagePositionSize.x, imagePositionSize.y, imagePositionSize.z, imagePositionSize.w);
    }
    inputImageTexture.end();

}

void Test::draw(){
    
    shader.begin();
    shader.setUniformTexture("image", inputImageTexture.getTexture(), 1);
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform2f("vignetteCenter", vignetteCenter);
    shader.setUniform3f("vignetteColor", vignetteColor);
    shader.setUniform1f("vignetteStart", vignetteStart);
    shader.setUniform1f("vignetteEnd", vignetteEnd);
    shader.setUniform1f("hsv_s", hsv_s);
    shader.setUniform1f("hsv_v", hsv_v);
    
    ofSetColor(255, 255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    
    if (isDraw) {
        gui.draw();
    }

}
void Test::keyPressed(int key){
    if(key == 'h'){
        isDraw = !isDraw;
    }
}