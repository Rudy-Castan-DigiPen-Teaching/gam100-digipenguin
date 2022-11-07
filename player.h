#if !defined(PLAYER_H)
#define PLAYER_H

struct Player {
	int x, y;
	int hit_points = 100;
	void update_position();
	void collision_check();
	void draw();

	int shot_type = 0;
};

#endif