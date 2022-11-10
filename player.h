#if !defined(PLAYER_H)
#define PLAYER_H

#include <doodle/doodle.hpp>
#include "enum.h"
#include "assets.h"
#include "shot.h"

constexpr double gravity = 9.81;

//player setting///////////////////////////////////////////
constexpr double playerJumpHeight = 5;
constexpr double playerSpeed = 4;
constexpr int playerColor = 0x2743D2ff;

//timer setting (wip) /////////////////////////////////////
extern double previousTime;
extern double currentTime;

extern Player_sprites player_sprites;

class Player {
	int width = 25;
	int height = 50;

	double x, y;
	double x_acceleration;
	double x_speed = 1.0;

	//double y_acceleration;
	//int jump_power = 4;
	//double y_friction = 0.8;
	double y_velocity = 0;
	bool standing = false;
	//bool is_jumping = false;
	//bool is_touching_floor = true;

	int hit_points = 100;
	bool is_hurt = false;

	Shot_type shot_type = NORMAL;
	Direction shot_direction = EAST;
	int shot_timer = 100;

	doodle::Image sprite; // default sprite
	Direction sprite_direction = EAST;

public:
	Player(double _x, double _y);
	void update_sprite();
	void update_position();
	void update_shot_direction();
	void shoot();
	void jump();
	void collision_check();
	void display();
};

#endif