#include <iostream>
#include <fstream> 
#include <doodle/doodle.hpp>
#include "assets.h"
#include "map.h"


void Map::update() {

}



void Map::draw(doodle::Image img, int x, int y, int tile_size) {

	doodle::draw_image(img, x * tile_size, y * tile_size, tile_size, tile_size);
	//doodle::draw_rectangle(x * 100, y * 100, 100, 100);
}