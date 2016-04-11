//
//  Filter.cpp
//  ImageFilter
//
//  Created by 厚木麻耶 on 2016/04/11.
//
//

#include "Filter.hpp"
vector<ofShader> &  Filter::load(string imageName, ofFbo & image){
    _imageName = imageName;
    _image = image;
    shader.push_back(yumekawa.load());
    shader.push_back(voronoi.load(imageName, image));
    
    return shader;
    
}
void Filter::draw(int filterNmber){
    switch (filterNmber) {
        case 0:
            yumekawa.uniform(_imageName, _image);
            break;
        case 1:
            voronoi.uniform();
            break;
            
    }
}
