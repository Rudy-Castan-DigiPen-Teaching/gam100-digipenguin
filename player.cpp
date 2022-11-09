#include "player.h"
#include <doodle/doodle.hpp>

void Player::update_position() {
	if (doodle::KeyIsPressed) { 
		if (doodle::Key == doodle::KeyboardButtons::Left) {
			this->x -= this->x_speed;
		}
		if (doodle::Key == doodle::KeyboardButtons::Right) {
			this->x += this->x_speed;
		} 
		if (doodle::Key == doodle::KeyboardButtons::Space) {
			this->is_jumping = true;
		}
	}
}

void Player::jump() {
	this->y_acceleration = this->jump_power;
	while (is_jumping && !this->is_touching_floor) {
		this->y += this->y_acceleration;
		this->y_acceleration -= this->y_friction;
		if (this->y < 50) { // check if touching floor; will be replaced after map is done (check each map tile)
			this->is_touching_floor = true;
		}
	}
	this->is_jumping = false;
}

void Player::update_sprite() {

	}

void Player::collision_check() {

}

void Player::draw() {
	doodle::draw_image(this->sprite, this->x, this->y);
}