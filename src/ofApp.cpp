//
//  ofApp.cpp
//
//  Created by クワシマ・ユウキ on 2021/04/26.
//

#include "ofApp.h"

void ofApp::setup(){
    fluid = Fluid();
    fluid.setup();
}

float detectDistance = 80;

void ofApp::update() {
//    fluid.update();
    
    //正規化 original
    for (int b = 0; b < birds.size(); b++) {
        birds[b].vel = birds[b].vel.normalize() * 0.5;
    }
    
    //pos
    for (int i = 0; i < birds.size(); i++) {
        vector<int> indexes;
        for (int j = 0; j < birds.size(); j++) {
            if (birds[i].pos.distance(birds[j].pos) < detectDistance && i != j) {
                indexes.push_back(j);
            }
        }
        if (indexes.size() == 0) continue;
        ofVec2f averagePos = ofVec2f(0, 0);
        for (int j = 0; j < indexes.size(); j++) {
            averagePos += birds[indexes[j]].pos;
        }
        averagePos.x /= (float)indexes.size();
        averagePos.y /= (float)indexes.size();
        
        birds[i].vel = (averagePos - birds[i].pos).normalize();
    }
    
    //正規化 original
    for (int b = 0; b < birds.size(); b++) {
        birds[b].vel = birds[b].vel.normalize() * 0.5;
    }
    
    //rad
    for (int i = 0; i < birds.size(); i++) {
        vector<int> indexes;
        for (int j = 0; j < birds.size(); j++) {
            if (birds[i].pos.distance(birds[j].pos) < detectDistance && i != j) {
                indexes.push_back(j);
            }
        }
        if (indexes.size() == 0) continue;
        ofVec2f averageVel = ofVec2f(0, 0);
        for (int j = 0; j < indexes.size(); j++) {
            averageVel += birds[indexes[j]].vel;
        }
        averageVel.x /= (float)indexes.size();
        averageVel.y /= (float)indexes.size();
        
        birds[i].vel = averageVel.normalize();
    }
    
    //正規化 original
    for (int b = 0; b < birds.size(); b++) {
        birds[b].vel = birds[b].vel.normalize() * 0.5;
    }
    
    //dist
    for (int i = 0; i < birds.size(); i++) {
        vector<int> indexes;
        for (int j = 0; j < birds.size(); j++) {
            if (birds[i].pos.distance(birds[j].pos) < 15 && i != j) {
                indexes.push_back(j);
            }
        }
        if (indexes.size() == 0) continue;
        for (int j = 0; j < indexes.size(); j++) {
            birds[i].vel += (birds[i].pos - birds[indexes[j]].pos).normalize() * 0.3;
        }
    }
    
    //正規化 original
//    for (int b = 0; b < birds.size(); b++) {
//        birds[b].vel = birds[b].vel.normalize() * 0.5;
//    }
    
    
    for (int b = 0; b < birds.size(); b++) {
        if (birds[b].pos.x > 950) {
            birds[b].vel.x -= 0.2;
        }
        if (birds[b].pos.x < 50) {
            birds[b].vel.x += 0.2;
        }
        if (birds[b].pos.y > 950) {
            birds[b].vel.y -= 0.2;
        }
        if (birds[b].pos.y < 50) {
            birds[b].vel.y += 0.2;
        }
        
        
        
        if (birds[b].pos.x > 980) {
            birds[b].vel.x -= 20;
        }
        if (birds[b].pos.x < 20) {
            birds[b].vel.x += 20;
        }
        if (birds[b].pos.y > 980) {
            birds[b].vel.y -= 20;
        }
        if (birds[b].pos.y < 20) {
            birds[b].vel.y += 20;
        }
    }
    
    
    // 移動
    for (int b = 0; b < birds.size(); b++) {
        birds[b].pos += birds[b].vel;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //
    for (int b = 0; b < deleters.size(); b++) {
        deleters[b].vel = deleters[b].vel.normalize() * 0.5;
    }
    
    //pos
    for (int i = 0; i < deleters.size(); i++) {
        vector<int> indexes;
        for (int j = 0; j < deleters.size(); j++) {
            if (deleters[i].pos.distance(deleters[j].pos) < detectDistance && i != j) {
                indexes.push_back(j);
            }
        }
        if (indexes.size() == 0) continue;
        ofVec2f averagePos = ofVec2f(0, 0);
        for (int j = 0; j < indexes.size(); j++) {
            averagePos += deleters[indexes[j]].pos;
        }
        averagePos.x /= (float)indexes.size();
        averagePos.y /= (float)indexes.size();
        
        deleters[i].vel = (averagePos - deleters[i].pos).normalize();
    }
    
    //正規化 original
    for (int b = 0; b < deleters.size(); b++) {
        deleters[b].vel = deleters[b].vel.normalize() * 0.5;
    }
    
    //rad
    for (int i = 0; i < deleters.size(); i++) {
        vector<int> indexes;
        for (int j = 0; j < deleters.size(); j++) {
            if (deleters[i].pos.distance(deleters[j].pos) < detectDistance && i != j) {
                indexes.push_back(j);
            }
        }
        if (indexes.size() == 0) continue;
        ofVec2f averageVel = ofVec2f(0, 0);
        for (int j = 0; j < indexes.size(); j++) {
            averageVel += deleters[indexes[j]].vel;
        }
        averageVel.x /= (float)indexes.size();
        averageVel.y /= (float)indexes.size();
        
        deleters[i].vel = averageVel.normalize();
    }
    
    //正規化 original
    for (int b = 0; b < deleters.size(); b++) {
        deleters[b].vel = deleters[b].vel.normalize() * 0.5;
    }
    
    //dist
    for (int i = 0; i < deleters.size(); i++) {
        vector<int> indexes;
        for (int j = 0; j < deleters.size(); j++) {
            if (deleters[i].pos.distance(deleters[j].pos) < 15 && i != j) {
                indexes.push_back(j);
            }
        }
        if (indexes.size() == 0) continue;
        for (int j = 0; j < indexes.size(); j++) {
            deleters[i].vel += (deleters[i].pos - deleters[indexes[j]].pos).normalize() * 0.3;
        }
    }
    
    //正規化 original
//    for (int b = 0; b < birds.size(); b++) {
//        birds[b].vel = birds[b].vel.normalize() * 0.5;
//    }
    
    
    for (int b = 0; b < deleters.size(); b++) {
        if (deleters[b].pos.x > 950) {
            deleters[b].vel.x -= 0.2;
        }
        if (deleters[b].pos.x < 50) {
            deleters[b].vel.x += 0.2;
        }
        if (deleters[b].pos.y > 950) {
            deleters[b].vel.y -= 0.2;
        }
        if (deleters[b].pos.y < 50) {
            deleters[b].vel.y += 0.2;
        }
        
        
        
        if (deleters[b].pos.x > 980) {
            deleters[b].vel.x -= 20;
        }
        if (deleters[b].pos.x < 20) {
            deleters[b].vel.x += 20;
        }
        if (deleters[b].pos.y > 980) {
            deleters[b].vel.y -= 20;
        }
        if (deleters[b].pos.y < 20) {
            deleters[b].vel.y += 20;
        }
    }
    
    
    // 移動
    for (int b = 0; b < deleters.size(); b++) {
        deleters[b].pos += deleters[b].vel;
    }
    
    
    
    for (int i = 0; i < NUM; i++) {
        fluid.prev_density[i] =0;
    }
    for (int b = 0; b < birds.size(); b++) {
        int index = fluid.getPos(int(birds[b].pos.x / 10.0), int(birds[b].pos.y / 10.0));
        fluid.prev_density[index] = 10;
        printf("%d\n", index);
    }
    for (int b = 0; b < deleters.size(); b++) {
        int index = fluid.getPos(int(deleters[b].pos.x / 10.0), int(deleters[b].pos.y / 10.0));
        fluid.prev_density[index] = -10;
        printf("%d\n", index);
    }
    
    fluid.update();
    
}

void ofApp::draw(){
    ofSetColor(0, 0, 0, 0);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    fluid.drawDensity();
    fluid.drawVelocity();
    ofNoFill();
    for (int b = 0; b < birds.size(); b++) {
        birds[b].drawBird();
    }
    for (int b = 0; b < deleters.size(); b++) {
        ofSetColor(0, 255, 255);
        ofDrawCircle(deleters[b].pos.x, deleters[b].pos.y, 3);
    }
    ofFill();
}

void ofApp::keyPressed(int key){
    if (key == 'b') {
        Bird bird = Bird();
        bird.pos = ofVec2f(ofRandom(100, 900), ofRandom(100, 900));
        bird.vel = ofVec2f(ofRandom(-3, 3), ofRandom(-3, 3));
        birds.push_back(bird);
    }
    if (key == 'd') {
        Bird bird = Bird();
        bird.pos = ofVec2f(ofRandom(100, 900), ofRandom(100, 900));
        bird.vel = ofVec2f(ofRandom(-3, 3), ofRandom(-3, 3));
        deleters.push_back(bird);
    }
}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){
    fluid.isMousePressed = true;
    if (button == 0) fluid.isLeftButton = true;
    if (button == 2) fluid.isLeftButton = false;
}

void ofApp::mouseReleased(int x, int y, int button){
    fluid.isMousePressed = false;
}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}
 
void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
