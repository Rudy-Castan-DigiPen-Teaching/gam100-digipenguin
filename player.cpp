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


#define BUTTON_LEFT 0
#define BUTTON_RIGHT 1
#define BUTTON_UP 2
#define BUTTON_DOWN 3
#define BUTTON_Z 4



//make bool array
bool buttons[] = { false, false, false, false, false }; // { left, right, up, down, jump(Z key)}

// use map(wip) : ~to make more sexy code~ //////////////////////////////////////////////////////
//std::map<doodle::KeyboardButtons, bool> buttons[] = {
//	{ doodle::KeyboardButtons::Left, false },
//	{ doodle::KeyboardButtons::Right, false},
//	{ doodle::KeyboardButtons::Up, false},
//	{ doodle::KeyboardButtons::Down, false},
//	{ doodle::KeyboardButtons::Z, false}
//};
//////////////////////////////////////////////////////////////////////



Player::Player(double _x, double _y) {
	this->x = _x;
	this->y = _y;
	this->sprite = player_sprites.player_sprite_placeholder;
}



void Player::jump() {

	if (this->standing == true) {
		this->y_velocity -= playerJumpHeight;
		//^^ if timer set finished -> y_velocity -= player_jump_height * dt(deltatime)?
		this->standing = false;
	}
}

//DO NOT put this functions(push,release_button) in Player Class (it'll become non-static)

void push_button(doodle::KeyboardButtons button) {
	switch (button) {
	case doodle::KeyboardButtons::Left:
		buttons[BUTTON_LEFT] = true;
		break;
	case doodle::KeyboardButtons::Right:
		buttons[BUTTON_RIGHT] = true;
		break;
	case doodle::KeyboardButtons::Up:
		buttons[BUTTON_UP] = true;
		break;
	case doodle::KeyboardButtons::Down:
		buttons[BUTTON_DOWN] = true;
		break;
	case doodle::KeyboardButtons::Z:
		buttons[BUTTON_Z] = true;
		break;
	}
};

void release_button(doodle::KeyboardButtons button) {
	switch (button) {
	case doodle::KeyboardButtons::Left:
		buttons[BUTTON_LEFT] = false;
		break;
	case doodle::KeyboardButtons::Right:
		buttons[BUTTON_RIGHT] = false;
		break;
	case doodle::KeyboardButtons::Up:
		buttons[BUTTON_UP] = false;
		break;
	case doodle::KeyboardButtons::Down:
		buttons[BUTTON_DOWN] = false;
		break;
	case doodle::KeyboardButtons::Z:
		buttons[BUTTON_Z] = false;
		break;
	}
};

void Player::update_position() {
	//block height value (change to platform height)

	//std::cout << standing << std::endl;

	int y_block = -75; //why y axis odd???

	if (this->y <= y_block) {

		this->standing = true;
	}



	if (buttons[BUTTON_LEFT] && buttons[BUTTON_Z]) { //left jump

		jump();
		this->x -= playerSpeed;
	}

	else if (buttons[BUTTON_RIGHT] && buttons[BUTTON_Z]) { //right jump

		jump();
		this->x += playerSpeed;
	}




	else if (buttons[BUTTON_LEFT]) {
		this->x -= playerSpeed;
	}

	else if (buttons[BUTTON_RIGHT]) {
		this->x += playerSpeed;
	}


	else if (buttons[BUTTON_Z]) { //jump

		//previousTime = currentTime;

		this->jump();
	}



	if (this->x >= 750) {
		this->x = 750;
	}

	if (this->x <= 25) {
		this->x = 25;
	}

	if (this->y <= y_block) {
		this->y = y_block;
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