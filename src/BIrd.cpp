//
//  BIrd.cpp
//  one
//
//  Created by クワシマ・ユウキ on 2021/10/05.
//

#include "BIrd.hpp"


void Bird::drawBird() {
    ofSetColor(255, 255, 0);
    ofDrawCircle(pos.x, pos.y, 5);
}
