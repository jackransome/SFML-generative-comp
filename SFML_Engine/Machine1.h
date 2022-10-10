#pragma once
#include "Console.h"
#include "SoundPlayer.h"

class Machine1 {
public:
	Machine1() {}
	Machine1(Console* _pConsole, SoundPlayer* _pSoundPlayer);
	void run();
	void scan();
private:
	int interval = 500;
	long getCurrentTime();
	int time = 0;
	int MinerState = 0;
	int scannerState = 0;
	int scannerFilled = 0;
	int hunger = 0;
	Console* pConsole;
	SoundPlayer* pSoundPlayer;
	int signal1s = 0;
	long startTime = 0;
	long lastBeat = 0;
};