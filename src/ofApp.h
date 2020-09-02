#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void drawNewCircles(int amountOfCircles);
		void resetCircles();
		
		int numOfCircles;

		struct Circle
		{
			int x;
			int y;
			int size;
			ofColor colour;
		};

		int posX = 0;
		int posY = 0;
		int size;

		int rotation;

		ofColor colour;
		
		vector<Circle> circlesArray;

		ofImage exportScreen;


};
