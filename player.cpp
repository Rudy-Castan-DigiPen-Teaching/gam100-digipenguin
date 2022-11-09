#include "player.h"
#include <doodle/doodle.hpp>

void Player::update_position() {
	if (doodle::KeyIsPressed) { // left and right movements
		if (doodle::Key == doodle::KeyboardButtons::Left) {
			this->x -= this->speed;
		}
		if (doodle::Key == doodle::KeyboardButtons::Right) {
			this->x += this->speed;
		}
		if (doodle::Key == doodle::KeyboardButtons::Down) {
			this->y -= this->speed;
		}
		if (doodle::Key == doodle::KeyboardButtons::Up) {
			this->y += this->speed;
		}
	}
}

void Player::update_sprite() {

	}

void Player::collision_check() {

}

void Player::draw() {
	doodle::draw_image(this->sprite, this->x, this->y);
}