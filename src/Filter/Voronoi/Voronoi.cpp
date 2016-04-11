#include "Voronoi.hpp"
ofShader & Voronoi::load(string name, ofFbo & image){
    shader.load("", "shader/Voronoi.frag");
    
    //voronoi
    image.readToPixels(pixels);
    for (int i=0; i<NUM_POINTS; i++) {
        _vertices[i*2] = ofRandomuf();
        _vertices[i*2+1] = ofRandomuf();
        ofColor c = pixels.getColor(_vertices[i*2]*ofGetWidth(), _vertices[i*2+1]*ofGetHeight());
        
        _colors[i*3] = c.r/255.;
        _colors[i*3+1] = c.g/255.;
        _colors[i*3+2] = c.b/255.;
    }

    
    return shader;
}
void Voronoi::uniform(){
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform1i("NUM_POINTS", NUM_POINTS);
    shader.setUniform2fv("verts", _vertices, NUM_POINTS);
    shader.setUniform3fv("colors", _colors, NUM_POINTS);

}