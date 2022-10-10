#include "Machine1.h"
#include <chrono>
#include <iostream>
using namespace std::chrono;

Machine1::Machine1(Console* _pConsole, SoundPlayer* _pSoundPlayer){
	pConsole = _pConsole;
	pSoundPlayer = _pSoundPlayer;
	startTime = getCurrentTime();
	interval = 300;
	lastBeat = getCurrentTime();
	time = 1;
	scannerState = 4;
}

void Machine1::run(){
	if (getCurrentTime() - interval > lastBeat) {
		lastBeat = getCurrentTime();
	}
	else {
		return;
	}
	//states:
	// 0 mining
	// 1 found something
	// 2 signalling
	switch (MinerState) {
	case 0:
		std::cout << "0\n";
		pSoundPlayer->playSoundByName("mine");
		if (time % 8 == 0) {
			//if found something
			pConsole->addCommand(commandPlaySound, "find");
			MinerState = 1;
		}
		break;
	case 1:
		std::cout << "1\n";
		pSoundPlayer->playSoundByName("pickup");
		signal1s++;
		MinerState = 0;
		break;
	case 2:
		std::cout << "2\n";
		//pConsole->addCommand(commandPlaySound, "signal1");
		signal1s++;
		MinerState = 0;
		break;
	}

	if (signal1s > 0){
		pSoundPlayer->playSoundByName("signal1", 0.3);
	}

	//states:
	// 0 resting
	// 1 scanning
	// 2 found data
	// 3 retreiving data
	//
	// signaling
	switch (scannerState) {
	case 0:
		pSoundPlayer->playSoundByName("idleScanner");
		if ((time) % 10 == 0) {
			scannerState = 1;
		}
		if (scannerFilled > 4) {
			scannerFilled = 0;
			pSoundPlayer->playSoundByName("signal2", 0.4);
		}

		break;
	case 1:
		
		pSoundPlayer->playSoundByName("scan");
		if (signal1s > 0) {

			scannerState = 2;
		}
		else {
			scannerState = 4;
		}

		break;
	case 2:
		pSoundPlayer->playSoundByName("foundData");
		signal1s = 0;
		scannerState = 0;
		scannerFilled++;
		break;
	case 3:
		pSoundPlayer->playSoundByName("getData");
		signal1s = 0;
		scannerState = 4;
		scannerFilled++;
		break;
	case 4:
		break;

	}

	time++;

}

void Machine1::scan() {
	scannerState = 1;
	std::cout << "1\n";
}

long Machine1::getCurrentTime() {
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}