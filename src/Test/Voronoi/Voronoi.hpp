//
//  Voronoi.hpp
//  ImageFilter
//
//  Created by 厚木麻耶 on 2016/04/11.
//
//

#ifndef Voronoi_hpp
#define Voronoi_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Voronoi_hpp */
const int NUM_POINTS = 200;
class Voronoi: public ofBaseApp{
public:
    void setup();
    void draw();
    void keyPressed(int key){};
    
    ofShader shader;
    ofImage inputImage;
    ofPixels pixels;
    ofFbo inputImageTexture;
    ofVec4f imagePositionSize;
    float       _vertices[NUM_POINTS*2];
    float       _colors[NUM_POINTS*3];

};