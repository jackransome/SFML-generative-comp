#include "CommandExecuter.h"

CommandExecuter::CommandExecuter() {}

CommandExecuter::CommandExecuter(SoundPlayer* _pSoundPlayer) {
	pSoundPlayer = _pSoundPlayer;
}

void CommandExecuter::execute(Command command) {
	switch (command.type) {
	case commandPlaySound:
		pSoundPlayer->playSoundByName(command.string, command.f1, command.f2);
		break;
	case commandLoopSound:
		pSoundPlayer->loopSound(command.a);
		break;
	case commandStopSound:
		pSoundPlayer->stopSound(command.a);
		break;
	default:
		std::cout << "UNKNOWN COMMAND";
	}
}
