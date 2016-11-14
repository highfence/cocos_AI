#pragma once

namespace STATIC
{
	const Size visibleSize = Size(1024, 768);
}


namespace PLAYER
{
	enum DIRECTION
	{
		NONE = 0, RIGHT = 1, LEFT = -1, UP = 1, DOWN = -1
	};

	const char PLAYER_SPRITE[] = "character.png";
	const float INIT_WIDTH = 0.2f;
	const float INIT_HEIGHT = 0.2f;
	const int PIXEL_PER_SEC = 300;
}


namespace ENEMY
{
	enum ENEMY_TYPE
	{
		Choco
	};
}