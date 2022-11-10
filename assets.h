#if !defined(ASSETS_H)
#define	ASSETS_H

#include <doodle/doodle.hpp>

struct Player_sprites {
	const doodle::Image player_sprite_placeholder{ "assets/images/playerspriteplaceholder.png" };
};

struct Shot_sprites {
	const doodle::Image shot_default{ "assets/images/shot_default.png" };
};

struct Map_tiles {
	const doodle::Image tile{ "assets/images/tile.png" };
	const doodle::Image tile_1{ "assets/images/tile_1.png" };
	const doodle::Image tile2{ "assets/images/tile2.png" };
	const doodle::Image tile2_1{ "assets/images/tile2_1.png" };
};

#endif