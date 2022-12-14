/*--------------------------------------------------------------
All content © 2022 DigiPen (USA) Corporation, all rights reserved.
File Name: main.cpp
Project: GAM100
Author: Hankyung Lee, Bada Kim, Minchan Cho, Donghyeok Hahm
-----------------------------------------------------------------*/

// penguinz r kool

#include <iostream>
#include <fstream>
#include <sstream>
#include <doodle/doodle.hpp>
#include "assets.h"
#include "player.h"
#include "map.h"
#include "shot.h"
#include "enemy.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600
#define WINDOW_TITLE	"hamburger"

int tile_size = 25;
int* p_tile_size = &tile_size;
Map map = Map();

Player player(WINDOW_WIDTH / 2, 50);
Player* p_player = &player;

Enemy enemy;
Enemy* p_enemy = &enemy;


double previousTime = 0;
double currentTime = doodle::ElapsedTime;

const Shot_sprites shot_sprites;
const Player_sprites player_sprites;
const Map_tiles map_tiles;

const Map_tiles* p_map_tiles = &map_tiles;

std::vector<Shot*> shots_fired;

int main() {
	enemy.player = p_player;
	std::cout << "Penguin" << std::endl;

	doodle::create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
	doodle::set_window_title(WINDOW_TITLE);
	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);

	map.update();

	doodle::set_callback_key_pressed(push_button);
	doodle::set_callback_key_released(release_button);

	while (!doodle::is_window_closed()) {
		doodle::update_window();
		doodle::clear_background(255); // placeholder for bg (will be replaced with map())

		doodle::draw_image(p_map_tiles->background, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

		map.draw(p_map_tiles->tile2, *p_tile_size);


		p_player->update_sprite();
		p_player->update_position();
		p_player->update_shot_direction();
		p_player->shoot();
		p_player->collision_check();
		p_player->display();

		p_enemy->draw();
		p_enemy->check_alive();
		p_enemy->player_spot();
		p_enemy->apply_physics();
		p_enemy->get_player();
		

		for (int i = 0; i < shots_fired.size(); i++) {
			shots_fired[i]->display();
			shots_fired[i]->update_position();
			shots_fired[i]->update_state();
		}
	}

	return 0;
}