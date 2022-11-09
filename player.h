#if !defined(PLAYER_H)
#define PLAYER_H

#include <doodle/doodle.hpp>

class Player {
	double x, y;
	float speed = 1.0;
	int hit_points = 100;
	bool is_hurt = false;

	int shot_type = 0;

	doodle::Image sprite;

public:
	Player(int _x, int _y, doodle::Image _sprite) {
		x = _x;
		y = _y;
		sprite = _sprite;
	}

	void update_sprite();
	void update_position();
	void collision_check();
	void draw();
};

#endif