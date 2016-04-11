//
//  Voronoi.cpp
//  ImageFilter
//
//  Created by 厚木麻耶 on 2016/04/11.
//
//

#include "Voronoi.hpp"
void Voronoi::setup(){
    ofBackground(255);
    shader.load("", "Voronoi.frag");
    inputImage.load("img/thumb_P3130064_1024.jpg");
    
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
    
    //voronoi
    inputImageTexture.readToPixels(pixels);
    for (int i=0; i<NUM_POINTS; i++) {
        _vertices[i*2] = ofRandomuf();
        _vertices[i*2+1] = ofRandomuf();
//        _colors[i*3] = ofRandomuf();
//        _colors[i*3+1] = ofRandomuf();
//        _colors[i*3+2] = ofRandomuf();
        
        ofColor c = pixels.getColor(_vertices[i*2]*ofGetWidth(), _vertices[i*2+1]*ofGetHeight());

        _colors[i*3] = c.r/255.;
        _colors[i*3+1] = c.g/255.;
        _colors[i*3+2] = c.b/255.;
    }
    
}

void Voronoi::draw(){
    
    shader.begin();
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform1i("NUM_POINTS", NUM_POINTS);
    shader.setUniform2fv("verts", _vertices, NUM_POINTS);
    shader.setUniform3fv("colors", _colors, NUM_POINTS);
    ofSetColor(255, 255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    
}





