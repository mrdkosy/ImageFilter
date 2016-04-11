//
//  Filter.hpp
//  ImageFilter
//
//  Created by 厚木麻耶 on 2016/04/11.
//
//

#ifndef Filter_hpp
#define Filter_hpp

#include <stdio.h>
#include <string>
#include "YumeKawa.hpp"
#include "Voronoi.hpp"

class Filter{
public:
    vector<ofShader> &  load(string imageName, ofFbo & image);
    void draw(int filterNmber);
private:
    vector<ofShader> shader;
    string _imageName;
    ofFbo _image;
    //filter
    YumeKawa yumekawa;
    Voronoi voronoi;
};
#endif /* Filter_hpp */