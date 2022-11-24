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
	//doodle::draw_image(this->sprite, this->x, this->y);
	doodle::no_outline();
	doodle::set_fill_color(doodle::HexColor{ 0xff0000ff });
	doodle::draw_ellipse(this->x, this->y, 10, 10);
}

void Shot::update_position() {
	this->x += this->speed * std::cos(this->angle);
	this->x += this->speed * std::sin(this->angle);
	for (int i = 0; i < shots_fired.size() - 1; i++)
	{
		if (this->x >= 775 || this->x <= 25)
		{
			delete shots_fired[i];
			shots_fired.erase(shots_fired.begin() + i);
		}
	}
}

void Shot::update_state() {

}