//
//  YumeKawa.hpp
//  ImageFilter
//
//  Created by 厚木麻耶 on 2016/04/11.
//
//

#ifndef YumeKawa_hpp
#define YumeKawa_hpp

#include <stdio.h>
#include <string>
#include "ofMain.h"
#endif /* YumeKawa_hpp */
class YumeKawa{
public:
    ofShader & load();
    void uniform(string name, ofFbo & fbo);
    
private:
    ofShader shader;
    ofVec2f vignetteCenter;
    ofVec3f vignetteColor;
    float vignetteStart;
    float vignetteEnd;
    
    float hsv_s, hsv_v;


};