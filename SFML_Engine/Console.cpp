#include "Console.h"
#include <chrono>

Console::Console() {
	commands = std::queue<Command>();
	int e = commands.size();
	int r = 4;
}

void Console::addCommand(CommandType _type) {
	commands.push(Command(_type));
}

void Console::addCommand(CommandType _type, int _a) {
	commands.push(Command(_type, _a));
}

void Console::addCommand(CommandType _type, float _f1) {
	commands.push(Command(_type, _f1));
}

void Console::addCommand(CommandType _type, float _f1, float _f2, float _f3, float _f4) {
	commands.push(Command(_type, _f1, _f2, _f3, _f4));
}

void Console::addCommand(CommandType _type, std::string _string) {
	commands.push(Command(_type, _string));
}

void Console::addCommand(CommandType _type, std::string _string, float _f1) {
	commands.push(Command(_type, _string, _f1));
}

void Console::addCommand(CommandType _type, std::string _string, float _f1, float _f2) {
	commands.push(Command(_type, _string, _f1, _f2));
}

void Console::addCommand(CommandType _type, ObjectType _objectType, float _f1, float _f2) {
	commands.push(Command(_type, _objectType, _f1, _f2));
}

void Console::addCommand(CommandType _type, ObjectType _objectType, float _f1, float _f2, float _f3) {
	commands.push(Command(_type, _objectType, _f1, _f2, _f3));
}

void Console::addCommand(CommandType _type, ObjectType _objectType, float _f1, float _f2, float _f3, float _f4) {
	commands.push(Command(_type, _objectType, _f1, _f2, _f3, _f4));
}

void Console::addCommand(CommandType _type, float _f1, float _f2) {
	commands.push(Command(_type, _f1, _f2));
}

void Console::addCommand(Command command) {
	commands.push(command);
}

int Console::getSize() {
	return commands.size();
}

int Console::getTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void Console::incrementFrame() {
	frame++;
}

int Console::getFrame() {
	return frame;
}

Command Console::getCommand(bool toLog) {
	Command temp = commands.front();
	commands.pop();
	if (enableLogging && toLog) {
		log.push(temp);
	}
	return temp;
}