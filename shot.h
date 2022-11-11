/*--------------------------------------------------------------
All content © 2022 DigiPen (USA) Corporation, all rights reserved.
File Name: shot.h
Project: GAM100
Author: Hankyung Lee
-----------------------------------------------------------------*/

#if !defined(SHOT_H)
#define SHOT_H

#include <doodle/doodle.hpp>
#include "enum.h"
#include "assets.h"

extern const Shot_sprites shot_sprites;

class Shot;

extern std::vector<Shot*> shots_fired;

class Shot {
	double x, y;
	int speed = 4; // will be replaced with shotspeed 
	double angle;
	Shot_type shot_type;
	Direction direction;

	doodle::Image sprite;

public:
	Shot(double _x, double _y, Shot_type _shot_type, Direction _direction);
	void display();
	void update_position();
	void update_state(); 
};

#endif