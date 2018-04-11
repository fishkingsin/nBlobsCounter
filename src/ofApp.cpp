#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("HelveticaNeue.ttc", 72);
    cout << "listening for osc messages on port " << PORT << "\n";
    receiver.setup(PORT);
    nBlobs = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        if(m.getAddress() == "/cvtracker/nBlobs"){
            nBlobs = m.getArgAsInt32(0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(0);
    ofSetColor(255);
    string nBlobsString = ofToString(nBlobs);
    ofRectangle rect = font.getStringBoundingBox(nBlobsString, 0, 0);
    float x = ofGetWidth()*0.5-rect.width*0.5;
    float y = ofGetHeight()*0.5-rect.height*0.5;
    font.drawString(nBlobsString, x, y);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
