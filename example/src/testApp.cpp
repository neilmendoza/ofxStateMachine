#include "testApp.h"
#include "RedState.h"
#include "GreenState.h"

//--------------------------------------------------------------
void testApp::setup(){
	// setup shared data
	stateMachine.getSharedData().counter = 0;
	stateMachine.getSharedData().lastUpdate = ofGetElapsedTimeMillis();
	stateMachine.getSharedData().font.loadFont("vag.ttf", 50);
	
	// initialise state machine
	stateMachine.addState<RedState>();
	stateMachine.addState<GreenState>();
	stateMachine.changeState("green");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("Mouse click changes state", 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}