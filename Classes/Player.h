#pragma once

class Player : public Sprite
{
public :
	CREATE_FUNC(Player);

	virtual bool         init();
	void 	     		 onKeyPressed(EventKeyboard::KeyCode, Event*);
	void				 onKeyReleased(EventKeyboard::KeyCode, Event*);

	void				 move(float);


private :
	Sprite*              m_pCharacter;

	CC_SYNTHESIZE(Point, m_PlayerPosition, playerPosition);
	CC_SYNTHESIZE(int, m_PlayerDirectionX, PlayerDirectionX);
	CC_SYNTHESIZE(int, m_PlayerDirectiony, PlayerDirectionY);

};