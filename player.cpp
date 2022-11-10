#include "player.h"
#include "shot.h"
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

void Player::shoot() {
	if (doodle::KeyIsPressed && doodle::Key == doodle::KeyboardButtons::Z) {
		new Shot(this->x, this->y, this->shot_type, this->shot_direction);
	}
}

void Player::update_sprite() {
	switch (this->sprite_direction) {
	default:
		// image_assets.placeholder 
		// image_assets need to be declared in both player and main.cpp
		//how to declare it only in main cpp and use it in other source files? 
	}
}

void Player::collision_check() {

}

void Player::draw() {
	doodle::draw_image(this->sprite, this->x, this->y);
}