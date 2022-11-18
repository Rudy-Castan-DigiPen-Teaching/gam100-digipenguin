/*--------------------------------------------------------------
All content © 2022 DigiPen (USA) Corporation, all rights reserved.
File Name: map.cpp
Project: GAM100
Author: Bada Kim
-----------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <doodle/doodle.hpp>
#include "assets.h"
#include "map.h"

void Map::update() {

	std::ifstream world_maptile;
	world_maptile.open("assets/scripts/map0.txt");

	std::string tileline;

	while (getline(world_maptile, tileline)) {
		std::stringstream data;
		data << tileline;

		std::vector<int> row;

		while (data >> mapdata) {
			//std::cout << mapdata << " ";
			row.push_back(mapdata);
		}

		//std::cout << std::endl;
		world_map.push_back(row);
	}

	world_maptile.close();

}

void Map::draw(const doodle::Image &img, int &tile_size) {
	for (int y = 0; y < world_map.size(); y++) {
		for (int x = 0; x < world_map[y].size(); x++) {
			//std::cout << world_map[y][x] << ",";

			switch (world_map[y][x]) {
			case 1:
				doodle::draw_image(img, x * tile_size, y * tile_size, tile_size, tile_size);
				//map.draw(p_map_tiles->tile2, x, y, *p_tile_size);
				break;
			}
		}
	}
	//doodle::draw_image(img, x * tile_size, y * tile_size, tile_size, tile_size);
	//doodle::draw_rectangle(x * 100, y * 100, 100, 100);
}