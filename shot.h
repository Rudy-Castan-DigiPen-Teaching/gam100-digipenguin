#if !defined(SHOT_H)
#define SHOT_H

struct Shot {
	int x, y;
	enum shotType {
		NORMAL,
		STICKY,
		ATTRACT,
		REFLECT
	};
};

#endif