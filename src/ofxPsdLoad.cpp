//
//  ofxPsdLoad.cpp
//  BaseApp
//
//  Created by Oriol Ferrer Mesià on 27/1/16.
//
//

#include "ofxPsdLoad.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PSD // we only need PSD loading
#include "../lib/stb/stb_image.h"
#undef STB_IMAGE_IMPLEMENTATION

void ofxPsdLoad::loadPSD(const string &filePath, ofPixels &pixels) {

	string path = ofToDataPath(filePath, true);
	int w;
	int h;
	int comp;
	unsigned char *psdPix = stbi_load(path.c_str(), &w, &h, &comp, STBI_rgb_alpha);

	pixels.allocate(w, h, comp);
	memcpy(pixels.getData(), psdPix, w * h * comp);
	removeWhiteMatte(pixels);
	delete psdPix;
}

void ofxPsdLoad::loadPSD(const string &filePath, ofTexture &tex) {

	ofPixels pixels;
	loadPSD(filePath, pixels);
	tex.loadData(pixels);
}

void ofxPsdLoad::removeWhiteMatte(ofPixels &pixels) {

	int total = pixels.getWidth() * pixels.getHeight();

	for(int i = 0; i < total; ++i) {
		const int k = i * 4;
		const unsigned char a = pixels.getData()[k + 3];
		if(a) {
			const float na = a / 255.0f; // normalized alpha
			const float ina = 1.0f - na; // inverse normalized alpha
			const unsigned char r = pixels.getData()[k + 0];
			const unsigned char g = pixels.getData()[k + 1];
			const unsigned char b = pixels.getData()[k + 2];
			pixels.getData()[k + 0] = (r - 255.0f * ina) / na;
			pixels.getData()[k + 1] = (g - 255.0f * ina) / na;
			pixels.getData()[k + 2] = (b - 255.0f * ina) / na;
		}
	}
}