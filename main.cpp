// penguinz r koolest

#include <iostream>
#include <doodle/doodle.hpp>
#include "assets.h"
#include "player.h"
#include "map.h"
#include "shot.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600
//#define WINDOW_HEIGHT   600
#define WINDOW_TITLE	"hamburger"

int tile_size = 25;
Map map = Map();

Player player(WINDOW_WIDTH / 2, 50);
//Player* p_player = &player;

double previousTime = 0;
double currentTime = doodle::ElapsedTime;

Shot_sprites shot_sprites;
Player_sprites player_sprites;
Map_tiles map_tiles;

std::vector<Shot*> shots_fired;

int main() {
	std::cout << "Penguin" << std::endl;

	doodle::create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
	doodle::set_window_title(WINDOW_TITLE);
	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);

	while (!doodle::is_window_closed()) {
		doodle::update_window();
		doodle::clear_background(255); // placeholder for bg (will be replaced with map())

		for (int x = 0; x < map_render_area_width; x++) {
			for (int y = 0; y < map_render_area_height; y++) {
				int maptile = map.render_area[y][x];
				if (maptile == 0) {
					map.draw(map_tiles.tile, x, y, tile_size);
				}
				else {
					map.draw(map_tiles.tile2, x, y, tile_size);
				}
			}
		}

		player.update_sprite();
		player.update_position();
		player.update_shot_direction();
		player.shoot();
		player.collision_check();
		player.display();

		for (int i = 0; i < shots_fired.size(); i++) {
			shots_fired[i]->display();
			shots_fired[i]->update_position();
			shots_fired[i]->update_state();
		}
	}

	return 0;
}