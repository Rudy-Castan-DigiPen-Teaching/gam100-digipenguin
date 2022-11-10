#if !defined(SHOT_H)
#define SHOT_H

#include <doodle/doodle.hpp>
#include "enum.h"

class Shot;

extern std::vector<Shot*> shots_fired;

class Shot {
	double x, y;
	int speed;
	Shot_type shot_type;
	Direction direction;

	doodle::Image sprite;

public:
	Shot(double _x, double _y, Shot_type _shot_type, Direction _direction) {
		x = _x;
		y = _y;
		shot_type = _shot_type;
		direction = _direction;
		shots_fired.push_back(this);
	}
	void update_position();
	void update_state(); 
};

#endif