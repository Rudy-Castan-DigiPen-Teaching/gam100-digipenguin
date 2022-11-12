/*/--------------------------------------------------------------
All content © 2022 DigiPen(USA) Corporation, all rights reserved.
File Name : player.cpp
Project: GAM100
Author : Donghyeok Hahm(donghyeok.hahm), Hnakyung Lee
---------------------------------------------------------------- */


#include "player.h"
#include "shot.h"
#include "enum.h"
#include <iostream>
#include <doodle/doodle.hpp>


//make bool array
bool array_move[3] = { false, false, false }; // { left, right, jump(Z key)}

Player::Player(double _x, double _y) {
	this->x = _x;
	this->y = _y;
	this->sprite = player_sprites.player_sprite_placeholder;
}

/*
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
*/

void Player::jump() {

	if (this->standing == true) {
		this->y_velocity -= playerJumpHeight;
		//^^ if timer set finished -> y_velocity -= player_jump_height * dt(deltatime)?
		this->standing = false;
	}
}

void Player::update_position() {
	//block height value (change to platform height)

	//std::cout << standing << std::endl;

	if (this->y < -height) {

		this->standing = true;
	}



	if (!doodle::KeyIsPressed) {

		array_move[0] = false;
		array_move[1] = false;
		array_move[2] = false;

		std::cout << "clear" << std::endl;

	}


	else if (true) {

		if (doodle::KeyIsPressed && doodle::Key == doodle::KeyboardButtons::Left) {
			array_move[0] = true;
			std::cout << "Left" << std::endl;
		}

		else if (doodle::KeyIsPressed && doodle::Key == doodle::KeyboardButtons::Right) {
			array_move[1] = true;
			std::cout << "Right" << std::endl;
		}

		else if (doodle::KeyIsPressed && doodle::Key == doodle::KeyboardButtons::Z) {
			array_move[2] = true;
			std::cout << "Zump" << std::endl;
		}
	}

	if (array_move[0] == true && array_move[2] == true) { //left jump

		jump();
		this->x -= playerSpeed;

		std::cout << "left jumpppppppppppppppppppppppppppppppppppppppppppp" << std::endl;
	}

	else if (array_move[2] == true && array_move[1] == true) { //right jump

		jump();
		this->x += playerSpeed;

		std::cout << "right jumpppppppppppppppppppppppppppppppppppppppppppp" << std::endl;
	}




	else if (array_move[0] == true && this->x > 0) {
		this->x -= playerSpeed;
	}

	else if (array_move[1] == true && this->x < 725) {
		this->x += playerSpeed;
	}


	else if (array_move[2] == true) { //jump

		//previousTime = currentTime;

		this->jump();
	}



	if (this->x >= 725) {
		this->x = 725;
	}

	if (this->x <= 0) {
		this->x = 0;
	}

	// gravity works

	if (standing == false) {
		this->y_velocity += gravity * doodle::DeltaTime;
		this->y -= this->y_velocity;
	}
	else {
		this->y_velocity = 0;
	}
};


void Player::update_shot_direction() {
	if (doodle::KeyIsPressed) {
		if (doodle::Key == doodle::KeyboardButtons::Left) {
			this->shot_direction = Direction::WEST;
		}
		if (doodle::Key == doodle::KeyboardButtons::Right) {
			this->shot_direction = Direction::EAST;
		}
		if (doodle::Key == doodle::KeyboardButtons::Up) {
			this->shot_direction = Direction::NORTH;
		}
		if (doodle::Key == doodle::KeyboardButtons::Down) {
			this->shot_direction = Direction::SOUTH;
		}
	}
}



/*
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
*/

void Player::shoot() {
	if (doodle::KeyIsPressed && doodle::Key == doodle::KeyboardButtons::X) {
		//&& int(doodle::ElapsedTime * 1000) % this->shot_timer == 0) {
		new Shot(this->x, this->y + 150, this->shot_type, this->shot_direction);
	}
}

void Player::update_sprite() {
	switch (this->sprite_direction) {
	default:
		return;
	}
}

void Player::collision_check() {

}

void Player::display() {
	doodle::push_settings(); // using sprite results in error? needs to be fixed 
	doodle::set_fill_color(255);
	doodle::set_outline_color(0);
	doodle::draw_rectangle(this->x, this->y + 100, this->width, this->height); ///added 100 to y, 11/10 22:43PM
	doodle::pop_settings();
	//doodle::draw_image(this->sprite, this->x, this->y);
}