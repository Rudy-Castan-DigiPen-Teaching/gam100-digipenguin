// penguinz r koolest

#include <iostream>
#include <doodle/doodle.hpp>
#include "assets.h"
#include "player.h"
#include "shot.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600
//#define WINDOW_HEIGHT   600
#define WINDOW_TITLE	"hamburger"

Image_assets image_assets;

Player player(WINDOW_WIDTH / 2, 50);
Player* p_player = &player;

std::vector<Shot*> shots_fired;


int main() {
	std::cout << "Penguin" << std::endl;

	doodle::create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
	doodle::set_window_title(WINDOW_TITLE);
	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);

	while (!doodle::is_window_closed()) {
		doodle::update_window();
		doodle::clear_background(255); // placeholder for bg (will be replaced with map())

		player.update_position();
		player.jump();
		player.draw();
		
	}

	return 0;
}