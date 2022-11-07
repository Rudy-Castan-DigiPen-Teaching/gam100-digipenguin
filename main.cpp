// penguinz r kooler

#include <iostream>
#include <doodle/doodle.hpp>
#include "player.h"
#include "shot.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   400
#define WINDOW_TITLE	"hamburger"

int main() {
	std::cout << "Penguin" << std::endl;

	doodle::create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
	doodle::set_window_title(WINDOW_TITLE);
	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);

	while (!doodle::is_window_closed) {
		// game
	}

	return 0;
}