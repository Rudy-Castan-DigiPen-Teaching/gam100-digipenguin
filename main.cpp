// penguinz r kool

#include <iostream>
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
	std::cout << "Penguin" << std::endl;

	doodle::create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
	doodle::set_window_title(WINDOW_TITLE);
	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);

	while (!doodle::is_window_closed()) {
		doodle::update_window();
		doodle::clear_background(255); // placeholder for bg (will be replaced with map())

		doodle::draw_image(p_map_tiles->background, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
		for (int x = 0; x < map_render_area_width; x++) {
			for (int y = 0; y < map_render_area_height; y++) {
				int* p_maptile = &map.render_area[y][x];
				if (*p_maptile == 1) {
					map.draw(p_map_tiles->tile2, x, y, *p_tile_size);
				}
			}
		}

		p_player->update_sprite();
		p_player->update_position();
		p_player->update_shot_direction();
		p_player->shoot();
		p_player->collision_check();
		p_player->display();

		p_enemy->draw();
		p_enemy->check_alive();
		p_enemy->apply_physics();


		for (int i = 0; i < shots_fired.size(); i++) {
			shots_fired[i]->display();
			shots_fired[i]->update_position();
			shots_fired[i]->update_state();
		}
	}

	return 0;
}