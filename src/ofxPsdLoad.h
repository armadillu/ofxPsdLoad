//
//  ofxPsdLoad.h
//  BaseApp
//
//  Created by Oriol Ferrer Mesià on 27/1/16.
//
//

#ifndef __BaseApp__ofxPsdLoad__
#define __BaseApp__ofxPsdLoad__

#include "ofMain.h"

class ofxPsdLoad{

public:
	
	static void loadPSD(string path, ofPixels & pixels);
	static void loadPSD(string path, ofTexture & tex);
	static void removeWhiteMatte(ofPixels &p);

};

#endif /* defined(__BaseApp__ofxPsdLoad__) */
