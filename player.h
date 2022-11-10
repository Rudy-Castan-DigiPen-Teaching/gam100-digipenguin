#if !defined(PLAYER_H)
#define PLAYER_H

#include <doodle/doodle.hpp>
#include "enum.h"
#include "shot.h"

class Player {
	double x, y;
	double x_acceleration;
	double x_speed = 1.0;

	double y_acceleration;
	int jump_power = 4;
	double y_friction = 0.8;
	bool is_jumping = false;
	bool is_touching_floor = true;

	int hit_points = 100;
	bool is_hurt = false;

	Shot_type shot_type = NORMAL;
	Direction shot_direction = EAST;
	int shot_timer = 100;

	doodle::Image sprite; // default sprite
	Direction sprite_direction = EAST;

public:
	Player(double _x, double _y) {
		x = _x;
		y = _y;
	}

	void update_sprite();
	void update_position();
	void shoot();
	void jump();
	void collision_check();
	void draw();
};

#endif