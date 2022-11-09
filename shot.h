#if !defined(SHOT_H)
#define SHOT_H

#include <doodle/doodle.hpp>
#include "enum.h"

class Shot {
	double x, y;
	Shot_type shot_type;

	doodle::Image sprite;

public:
	Shot(double _x, double _y, Shot_type _shot_type) {
		x = _x;
		y = _y;
		shot_type = _shot_type;
	}
};

#endif