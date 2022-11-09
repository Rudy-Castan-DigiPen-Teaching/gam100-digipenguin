#if !defined(PLAYER_H)
#define PLAYER_H

#include <doodle/doodle.hpp>

class Player {
	double x, y;
	double x_acceleration;
	float x_speed = 1.0;

	double y_acceleration;
	int jump_power = 4;
	float y_friction = 0.8;
	bool is_jumping = false;
	bool is_touching_floor = true;

	int hit_points = 100;
	bool is_hurt = false;

	Shot_type shot_type = NORMAL;
	int shot_timer = 100;

	doodle::Image sprite;

public:
	Player(double _x, double _y, doodle::Image _sprite) {
		x = _x;
		y = _y;
		sprite = _sprite;
	}

	void update_sprite();
	void update_position();
	void shoot();
	void jump();
	void collision_check();
	void draw();
};

#endif