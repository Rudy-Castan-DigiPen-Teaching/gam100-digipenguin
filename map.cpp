/*--------------------------------------------------------------
All content © 2022 DigiPen (USA) Corporation, all rights reserved.
File Name: map.cpp
Project: GAM100
Author: Bada Kim
-----------------------------------------------------------------*/

#include <iostream>
#include <fstream> 
#include <doodle/doodle.hpp>
#include "assets.h"
#include "map.h"

void Map::update() {

}

void Map::draw(const doodle::Image &img, int &x, int &y, int &tile_size) {
	doodle::draw_image(img, x * tile_size, y * tile_size, tile_size, tile_size);
	//doodle::draw_rectangle(x * 100, y * 100, 100, 100);
}