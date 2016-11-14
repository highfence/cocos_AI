#pragma once

#include "EnemyState.h"

// 적 타입에 따라서 다른 CREATE_FUNC를 만들어주기 위해서 정의.
#define CREATE_FUNC_ENEMY(__TYPE__) \
static __TYPE__* create(ENEMY::ENEMY_TYPE emeny_type) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->init(ownerPlayer)) \
    { \
        pRet->autorelease(); \
		pRet->scheduleUpdate();\
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = nullptr; \
        return nullptr; \
    } \
}

class Enemy : public Sprite
{
public:
	virtual bool      init(ENEMY::ENEMY_TYPE enemy_type);
	virtual void      update(float dt) override;

	/* State */
	template<typename T_STATE>
	void              changeState();

	CC_SYNTHESIZE(EnemyState*, m_pState, State);

private:
	Sprite*           m_pSprite;
};


// State를 전환.
template <typename T_STATE>
void Enemy::changeState()
{
	// state가 존재한다면 종료.
	if (m_pState)
	{
		getState()->endState(this);
		removeComponent(m_pState);
	}

	auto m_pState = T_STATE::create();
	setState(m_pState);
	getState()->startState(this);
	addComponent(m_pState);

	return;
}