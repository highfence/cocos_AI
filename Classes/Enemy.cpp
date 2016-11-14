#include "pch.h"
#include "Enemy.h"


bool Enemy::init(ENEMY::ENEMY_TYPE enemy_type)
{
	Sprite::init();

	return true;
}

void Enemy::update(float dt)
{
	m_pState->runState(this, dt);
	return;
}
