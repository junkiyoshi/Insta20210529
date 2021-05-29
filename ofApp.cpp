#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
	ofNoFill();

	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));

	// X
	ofBeginShape();
	for (int y = 120; y <= 340; y += 1) {

		auto x = ofMap(ofNoise(noise_seed.y, (((y + 340) * 0.5 + ofGetFrameNum()) * 0.01)), 0, 1, -100, 100);

		ofVertex(x, y);
	}
	ofEndShape();

	ofBeginShape();
	for (int y = -120; y >= -340; y -= 1) {

		auto x = ofMap(ofNoise(noise_seed.y, (((y + 240 + 340) * 0.5 + ofGetFrameNum()) * 0.01)), 0, 1, -100, 100);

		ofVertex(x, y);
	}
	ofEndShape();

	// Y
	ofBeginShape();
	for (int x = 120; x <= 340; x += 1) {

		auto y = ofMap(ofNoise(noise_seed.x, (((x + 340) * 0.5 + ofGetFrameNum()) * 0.01)), 0, 1, -100, 100);

		ofVertex(x, y);
	}
	ofEndShape();

	ofBeginShape();
	for (int x = -120; x >= -340; x -= 1) {

		auto y = ofMap(ofNoise(noise_seed.x, (((x + 240 + 340) * 0.5 + ofGetFrameNum()) * 0.01)), 0, 1, -100, 100);

		ofVertex(x, y);
	}
	ofEndShape();

	// Z
	ofBeginShape();
	for (int p = 120; p <= 340; p += 1) {

		auto z = ofMap(ofNoise(noise_seed.z, (((p + 340) * 0.5 + ofGetFrameNum()) * 0.01)), 0, 1, -100, 100);

		ofVertex(p, p, z);
	}
	ofEndShape();

	ofBeginShape();
	for (int p = -120; p >= -340; p -= 1) {

		auto z = ofMap(ofNoise(noise_seed.z, (((p + 240 + 340) * 0.5 + ofGetFrameNum()) * 0.01)), 0, 1, -100, 100);

		ofVertex(p, p, z);
	}
	ofEndShape();

	ofFill();
	ofSetColor(255);
	auto location = glm::vec3(
		ofMap(ofNoise(noise_seed.y, (460 * 0.5 + ofGetFrameNum()) * 0.01), 0, 1, -100, 100), 
		ofMap(ofNoise(noise_seed.x, (460 * 0.5 + ofGetFrameNum()) * 0.01), 0, 1, -100, 100),
		ofMap(ofNoise(noise_seed.z, (460 * 0.5 + ofGetFrameNum()) * 0.01), 0, 1, -100, 100)
		);
	ofDrawSphere(location, 5);

	for (int i = 1; i < 10; i++) {

		ofSetColor(ofMap(i, 1, 10, 255, 0));
		auto log = glm::vec3(
			ofMap(ofNoise(noise_seed.y, (460 * 0.5 + ofGetFrameNum() - i * 3) * 0.01), 0, 1, -100, 100),
			ofMap(ofNoise(noise_seed.x, (460 * 0.5 + ofGetFrameNum() - i * 3) * 0.01), 0, 1, -100, 100),
			ofMap(ofNoise(noise_seed.z, (460 * 0.5 + ofGetFrameNum() - i * 3) * 0.01), 0, 1, -100, 100));
		ofDrawSphere(log, 5);
	}

	ofNoFill();
	ofSetColor(64);
	ofSetLineWidth(1);
	ofDrawBox(180);

	ofDrawLine(glm::vec3(location.x, 120, 0), location);
	ofDrawLine(glm::vec3(location.x, -120, 0), location);

	ofDrawLine(glm::vec3(120, location.y, 0), location);
	ofDrawLine(glm::vec3(-120, location.y, 0), location);

	ofDrawLine(glm::vec3(120, 120, location.z), location);
	ofDrawLine(glm::vec3(-120, -120, location.z), location);

	ofSetColor(255);
	ofSetLineWidth(0.5);
	ofDrawLine(glm::vec2(-100, -120), glm::vec2(100, -120));
	ofDrawLine(glm::vec2(-100, 120), glm::vec2(100, 120));

	ofDrawLine(glm::vec2(120, -100), glm::vec2(120, 100));
	ofDrawLine(glm::vec2(-120, -100), glm::vec2(-120, 100));

	ofDrawLine(glm::vec2(-100, -340), glm::vec2(100, -340));
	ofDrawLine(glm::vec2(-100, 340), glm::vec2(100, 340));

	ofDrawLine(glm::vec2(340, -100), glm::vec2(340, 100));
	ofDrawLine(glm::vec2(-340, -100), glm::vec2(-340, 100));

	ofDrawLine(glm::vec3(340, 340, -100), glm::vec3(340, 340, 100));
	ofDrawLine(glm::vec3(120, 120, -100), glm::vec3(120, 120, 100));

	ofDrawLine(glm::vec3(-340, -340, -100), glm::vec3(-340, -340, 100));
	ofDrawLine(glm::vec3(-120, -120, -100), glm::vec3(-120, -120, 100));

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}