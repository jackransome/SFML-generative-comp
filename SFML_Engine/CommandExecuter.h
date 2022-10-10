#pragma once
#include "ObjectCollection.h"
#include "SoundPlayer.h"
#include "Camera.h"
#include "SpriteCollection.h"
#include "InputManager.h"

class CommandExecuter {
public:
	CommandExecuter();
	CommandExecuter( SoundPlayer* _pSoundPlayer);
	void execute(Command command);
private:
	SoundPlayer* pSoundPlayer;
};