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
#include <string>
#include "ofMain.h"
#endif /* Voronoi_hpp */
const int NUM_POINTS = 200;
class Voronoi{
public:
    ofShader & load(string name, ofFbo & image);
    void uniform();
private:
    ofShader shader;
    ofPixels pixels;
    float       _vertices[NUM_POINTS*2];
    float       _colors[NUM_POINTS*3];
};