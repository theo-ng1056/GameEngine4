#ifndef GAME1_H
#define GAME1_H

#include "../Engine/Core/CoreEngine.h"

class Game1 :public GameInterface 
{
public:
	Game1();
	virtual ~Game1();

	bool OnCreate()override;
	void Update(const float deltaTime_)override;
	void Render()override;
};


#endif // !GAME1_H

