#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(60);
    
    
    //set image
    loadImage("img/thumb_IMG_0497_1024.jpg");
    
    //include filter
    shader = filter.load( "inputImageTexture", inputImageTexture);
    filterNumber = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw filter image
    shader[filterNumber].begin();
    filter.draw(filterNumber);
    ofSetColor(255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader[filterNumber].end();
    
    //fps
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //filter changed
    if(key == ' '){
        filterNumber = (filterNumber+1)%shader.size();
    }
}
//--------------------------------------------------------------
void ofApp::loadImage(string filename){
    
    ofVec4f imagePositionSize;
    ofImage inputImage;
    
    inputImage.load(filename);
    
    inputImageTexture.allocate(ofGetWidth(), ofGetHeight());
    inputImageTexture.begin();
    float x = inputImage.getWidth()/ofGetWidth();
    float y = inputImage.getHeight()/ofGetHeight();
    if(x < y){
        float x = inputImage.getWidth()/y;
        imagePositionSize.set(ofGetWidth()/2-x/2, 0, x, ofGetHeight());
        inputImage.draw(imagePositionSize.x, imagePositionSize.y, imagePositionSize.z, imagePositionSize.w);
    }else{
        float y = inputImage.getHeight()/x;
        imagePositionSize.set(0, ofGetHeight()/2-y/2, ofGetWidth(), y);
        inputImage.draw(imagePositionSize.x, imagePositionSize.y, imagePositionSize.z, imagePositionSize.w);
    }
    inputImageTexture.end();
    
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}
