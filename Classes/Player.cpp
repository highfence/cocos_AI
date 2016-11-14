#include "pch.h"
#include "Player.h"

using namespace PLAYER;

bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	//Initialize member variable
	setPlayerDirectionX(DIRECTION::NONE);
	setPlayerDirectionY(DIRECTION::NONE);

	// 초기 스프라이트 설정.
	m_pCharacter = Sprite::create(PLAYER::PLAYER_SPRITE);
	m_pCharacter->setPosition(Vec2(STATIC::visibleSize.width * INIT_WIDTH, STATIC::visibleSize.height * INIT_HEIGHT));
	addChild(m_pCharacter);

	// 키보드 입력 설정.
	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	keylistener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(keylistener, 2);

	// Schedule update;
	scheduleUpdate();

	return true;

}


void Player::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event)
{

	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		setPlayerDirectionX(DIRECTION::RIGHT);
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		setPlayerDirectionX(DIRECTION::LEFT);
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		setPlayerDirectionY(DIRECTION::UP);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		setPlayerDirectionY(DIRECTION::DOWN);
		break;
	}

	return;
}


void Player::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{

	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		setPlayerDirectionX(DIRECTION::NONE);
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		setPlayerDirectionX(DIRECTION::NONE);
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		setPlayerDirectionY(DIRECTION::NONE);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		setPlayerDirectionY(DIRECTION::NONE);
		break;
	}

	return;
}


void Player::move(float dt)
{
	float dtX = getPlayerDirectionX() * PIXEL_PER_SEC * dt;
	float dtY = getPlayerDirectionY() * PIXEL_PER_SEC * dt;

	auto currentX = m_pCharacter->getPositionX();
	auto currentY = m_pCharacter->getPositionY();

	m_pCharacter->setPosition(currentX + dtX, currentY + dtY);
	return;
}
