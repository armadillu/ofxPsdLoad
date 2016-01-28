//
//  ofxPsdLoad.h
//  BaseApp
//
//  Created by Oriol Ferrer Mesià on 27/1/16.
//
//

#pragma once

#include "ofMain.h"

class ofxPsdLoad {

  public:
	static void loadPSD(const string &path, ofPixels &pixels);
	static void loadPSD(const string &path, ofTexture &tex);
	static void removeWhiteMatte(ofPixels &p);
};

