#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofEnableAlphaBlending();
	ofSetBackgroundAuto(true);
	ofSetBackgroundColor(ofColor::black);

	exportScreen.allocate(ofGetWidth(), ofGetHeight(), ofImageType::OF_IMAGE_COLOR);

	size = 1;
	rotation = 0;

	posX = size * 2;
	posY = size * 2;
	
	numOfCircles = 600000;

	circlesArray.resize(numOfCircles);



	for (int i = 0; i < numOfCircles; i++)
	{


		if (posX > ofGetWidth())
		{
			posX = 0;
			posY += size * 2;


		}

		ofColor temp;

		circlesArray[i].x = posX;
		circlesArray[i].y = posY;
		circlesArray[i].size = ofRandom(1.0, 4.0);
		

		posX += size * 2;

	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (int i = 0; i < numOfCircles; i++)
	{
		/*
		top to bottom gradient
		ofSetColor(ofMap(i, 0, numOfCircles, 0, 255));
		*/

		/*
		top left to bottom right gradient
		ofSetColor(ofMap(circlesArray[i].x + circlesArray[i].y, 0, ofGetWidth() + ofGetHeight(), 0, 255));
		*/

		/*
		height and width dependant B and G channels
		ofSetColor(ofMap(circlesArray[i].x + circlesArray[i].y, 0, ofGetWidth() + ofGetHeight(), 0, 255), circlesArray[i].x, circlesArray[i].y);
		*/

		//if(circlesArray[i].x < ofGetWidth() / 2) ofSetColor(ofMap(circlesArray[i].x + circlesArray[i].y, 0, ofGetWidth() + ofGetHeight(), 0, 255), circlesArray[i].x, circlesArray[i].y);
		
		/*
		BlueGreen Gradient
			if (circlesArray[i].x < ofGetWidth() / 2) ofSetColor(ofMap(circlesArray[i].x + circlesArray[i].y, 0, ofGetWidth() + ofGetHeight(), 0, 255), ofMap(ofGetHeight() - circlesArray[i].y, 0, ofGetHeight(), 255, 0), ofMap(ofGetWidth() - circlesArray[i].x, 0, ofGetWidth(), 255, 0), 200);
			if (circlesArray[i].x > ofGetWidth() / 2) ofSetColor(ofMap(circlesArray[i].x + circlesArray[i].y, 0, ofGetWidth() + ofGetHeight(), 0, 255), ofMap(ofGetHeight() - circlesArray[i].y, 0, ofGetHeight(), 255, 0), ofMap(ofGetWidth() - circlesArray[i].x, 0, ofGetWidth(), 255, 0), 200);


		*/


		if (circlesArray[i].x + circlesArray[i].y < ofGetWidth() + ofGetHeight())
		{
			ofSetColor(ofMap(circlesArray[i].x + circlesArray[i].y, 0, ofGetWidth() + ofGetHeight(), 0, 255), circlesArray[i].x, circlesArray[i].y);

			ofPushMatrix();

			ofRotateDeg(rotation);
			ofDrawCircle(circlesArray[i].x, circlesArray[i].y, circlesArray[i].size);
			rotation++;
			if (rotation > 360) rotation = 0;

			ofPopMatrix();

		}

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == ' ')
	{
		exportScreen.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		exportScreen.saveImage("testImg.png", ofImageQualityType::OF_IMAGE_QUALITY_BEST);
	}
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

void ofApp::drawNewCircles(int amountOfCircles)
{
	numOfCircles = amountOfCircles;
	circlesArray.clear();
	circlesArray.resize(amountOfCircles);

	resetCircles();



}

void ofApp::resetCircles()
{
	circlesArray.resize(numOfCircles);

	for (int i = 0; i < numOfCircles; i++)
	{

		size = 20;

		if (posX > ofGetWidth())
		{
			posX = 0;
			posY += size * 2;


		}

		ofColor temp;

		circlesArray[i].x = posX;
		circlesArray[i].y = posY;
		circlesArray[i].size = size;

		circlesArray[i].colour.r = ofRandom(0, 255);
		circlesArray[i].colour.g = ofRandom(0, 255);
		circlesArray[i].colour.b = ofRandom(0, 255);


		posX += size;

	}
}
