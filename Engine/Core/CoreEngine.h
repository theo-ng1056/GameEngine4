#ifndef COREENGINE_H
#define COREENGINE_H

#include <memory>
#include "Window.h"
#include "Timer.h"
#include "Debug.h"
#include "GameInterface.h"

class CoreEngine
{
public:
	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;
	CoreEngine& operator=(const CoreEngine&) = delete;
	CoreEngine& operator=(CoreEngine&&) = delete;

	// Return a reference to this core engine object
	static CoreEngine* GetInstance();

	// Create window
	bool OnCreate(string name_, int width_, int height_);

	void Run();
	// Return running variable value
	bool GetIsRunning();

	void SetGameInterface(GameInterface* gameInterface_);


private:
	CoreEngine();
	~CoreEngine();

	void Update(const float deltaTime_);
	void Render();
	void OnDestroy();

	static unique_ptr<CoreEngine> engineInstance; // hole pointer to this engine class
	friend default_delete<CoreEngine>; // delete unique_ptr by default (destructor)

	Window* window;

	bool isRunning; 

	Timer timer;
	unsigned int fps;

	GameInterface* gameInterface;
};

#endif // !COREENGINE_H



