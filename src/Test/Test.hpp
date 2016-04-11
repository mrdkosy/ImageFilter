//
//  Test.hpp
//  ImageFilter
//
//  Created by 厚木麻耶 on 2016/04/10.
//
//

#ifndef Test_hpp
#define Test_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxGui.h"

#endif /* Test_hpp */

class Test: public ofBaseApp{
public:
    void setup();
    void draw();
    void keyPressed(int key);
    ofShader shader;
    ofImage image;
    ofImage inputImage, saveImage;
    ofFbo inputImageTexture;
    ofVec2f vignetteCenter;
    ofVec3f vignetteColor;
    ofVec4f imagePositionSize;
    float vignetteStart;
    float vignetteEnd;
    
    ofxPanel gui;
    ofxFloatSlider hsv_s, hsv_v;
    bool isDraw;
    
};