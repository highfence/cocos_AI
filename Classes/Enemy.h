#pragma once

#include "EnemyState.h"

// �� Ÿ�Կ� ���� �ٸ� CREATE_FUNC�� ������ֱ� ���ؼ� ����.
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


// State�� ��ȯ.
template <typename T_STATE>
void Enemy::changeState()
{
	// state�� �����Ѵٸ� ����.
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