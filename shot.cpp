/*--------------------------------------------------------------
All content © 2022 DigiPen (USA) Corporation, all rights reserved.
File Name: shot.cpp
Project: GAM100
Author: Hankyung Lee
-----------------------------------------------------------------*/

#include <doodle/doodle.hpp>
#include <cmath>
#include "shot.h"
#include "assets.h"

Shot::Shot(double _x, double _y, Shot_type _shot_type, Direction _direction) {
	this->x = _x;
	this->y = _y;
	this->shot_type = _shot_type;
	this->direction = _direction;
	switch (this->shot_type) {
	default:
		this->sprite = shot_sprites.shot_default;
	}
	this->angle = -doodle::HALF_PI + doodle::QUARTER_PI * this->direction;
	shots_fired.push_back(this);
}

void Shot::display() {
	doodle::draw_image(this->sprite, this->x, this->y);
}

void Shot::update_position() {
	this->x += this->speed * std::cos(this->angle);
	this->x += this->speed * std::sin(this->angle);
	if (this->x >= 750)
	{
		this->x = 750;
	}
	if (this->x <= 50)
	{
		this->x = 50;
	}
}

void Shot::update_state() {

}