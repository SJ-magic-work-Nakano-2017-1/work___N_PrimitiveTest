/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/
char targetIP[] = "10.7.189.7";


/************************************************************
************************************************************/

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowShape(600, 400);
    
	ofSetVerticalSync(false);
    ofSetFrameRate(60);
	
    //at first you must specify the Ip address of this machine
    artnet.setup("10.0.0.2"); //make sure the firewall is deactivated at this point
	
	/********************
	********************/
	for(int i = 0; i < DMX_SIZE; i++){
		data[i] = 0;
	}
	
	/********************
	********************/
	ofColor initColor = ofColor(0, 0, 0, 255);
	ofColor minColor = ofColor(0, 0, 0, 0);
	ofColor maxColor = ofColor(255, 255, 255, 255);
	
	/********************
	********************/
	gui.setup();
	gui.add(color.setup("color", initColor, minColor, maxColor));
}

//--------------------------------------------------------------
void ofApp::update(){
	#define MODE__GUI_TO_LED0	0
	#define MODE__ALL			1
		#define MODE MODE__GUI_TO_LED0
		
	const int NUM_LEDS = 100;
	
	ofColor CurrentColor = color;
	
	
#if (MODE == MODE__GUI_TO_LED0)
	int LedId = 0;
	
	set_dataArray(LedId, CurrentColor);
	
#elif(MODE == MODE__ALL)
	for(int i = 0; i < NUM_LEDS; i++){
		set_dataArray(i, CurrentColor);
	}
	
#else
	// nothing.
#endif
}

//--------------------------------------------------------------
void ofApp::set_dataArray(int id, ofColor CurrentColor){
/*
	const int NUM_ITEMS_IN_CH = 6;
	
	
	data[NUM_ITEMS_IN_CH * id + 0] = CurrentColor.a;
	data[NUM_ITEMS_IN_CH * id + 1] = CurrentColor.r;
	data[NUM_ITEMS_IN_CH * id + 2] = CurrentColor.g;
	data[NUM_ITEMS_IN_CH * id + 3] = CurrentColor.b;
	
	data[NUM_ITEMS_IN_CH * id + 4] = 0; // W
	data[NUM_ITEMS_IN_CH * id + 5] = 1; // Strobe. 1-9:open
*/

	//
	// for Nakano SumMall
	// 
	const int NUM_ITEMS_IN_CH = 3;
	
	data[NUM_ITEMS_IN_CH * id + 0] = CurrentColor.r;
	data[NUM_ITEMS_IN_CH * id + 1] = CurrentColor.g;
	data[NUM_ITEMS_IN_CH * id + 2] = CurrentColor.b;
}

//--------------------------------------------------------------
void ofApp::exit(){
	for(int i = 0; i < DMX_SIZE; i++){
		data[i] = 0;
	}
    artnet.sendDmx(targetIP, data, DMX_SIZE);
}

//--------------------------------------------------------------
void ofApp::draw(){
	/********************
	********************/
	ofBackground(30);
	
	/********************
	********************/
    // list nodes for sending
    // with subnet / universe
	// artnet.sendDmx("10.0.0.149", 0xf, 0xf, testImage.getPixels(), 512);
    artnet.sendDmx(targetIP, data, DMX_SIZE);
	
	/********************
	********************/
	gui.draw();
	
	/********************
	********************/
	printf("%5.1f\r", ofGetFrameRate());
	fflush(stdout);
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
