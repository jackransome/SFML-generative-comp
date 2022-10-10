#include "Game.h"

Game::Game(sf::RenderWindow* pwindow) {
	pWindow = pwindow;
	graphics = Graphics(pwindow);
	inputManager = InputManager(pwindow);
	spriteCollection = SpriteCollection(pwindow, &graphics);
	soundPlayer = SoundPlayer();
	camera = Camera();
	console = Console();
	objectCollection = ObjectCollection(&console, &inputManager, &spriteCollection, &soundPlayer, &camera);
	commandExecuter = CommandExecuter(&soundPlayer);
	spriteCollection.loadImage("pic1", "resources/pic1.png");
	spriteCollection.loadImage("pic2", "resources/pic2.png");
	spriteCollection.loadImage("pic3", "resources/pic3.png");
	spriteCollection.loadImage("animation1", "resources/animation1.png");
	spriteCollection.loadImage("pillar_small_2", "resources/pillar_small_2.png");
	spriteCollection.loadImage("mc_walk_back", "resources/main_character/mc_walk_back.png");
	spriteCollection.loadImage("mc_walk_right", "resources/main_character/mc_walk_right.png");
	spriteCollection.loadImage("mc_walk_left", "resources/main_character/mc_walk_left.png");
	spriteCollection.loadImage("mc_walk_front", "resources/main_character/mc_walk_front.png");
	spriteCollection.loadImage("fire_animation_1", "resources/fire_animation_1.png");
	spriteCollection.loadImage("drone_fly", "resources/drone_fly.png");
	spriteCollection.loadImage("mc_run_left", "resources/main_character/mc_run_left.png");
	spriteCollection.loadImage("mc_run_right", "resources/main_character/mc_run_right.png");
	spriteCollection.loadImage("mc_blink_1", "resources/main_character/mc_blink_1.png");
	spriteCollection.loadImage("mc_stand_back", "resources/main_character/mc_stand_back.png");
	spriteCollection.loadImage("mc_stand_left", "resources/main_character/mc_stand_left.png");
	spriteCollection.loadImage("mc_stand_right", "resources/main_character/mc_stand_right.png");
	sprite1 = spriteCollection.getPointerFromName("pic1");
	sprite2 = spriteCollection.getPointerFromName("pic2");
	sprite3 = spriteCollection.getPointerFromName("pic3");
	//spriteSheet1 = SpriteSheet(pwindow, &spriteCollection, "animation1", 144, 172, 4, 1);
	//spriteSheet1 = SpriteSheet(pwindow, &spriteCollection, "animation2", 16, 26, 6, 2);
	//spriteSheet1.setDoesReset(false);
	soundPlayer.loadSound("find", "resources/find.wav");
	soundPlayer.loadSound("mine", "resources/mine.wav");
	soundPlayer.loadSound("pickup", "resources/pickup.wav");
	soundPlayer.loadSound("signal1", "resources/signal1.wav");
	soundPlayer.loadSound("scan", "resources/scan.wav");
	soundPlayer.loadSound("getData", "resources/getData.wav");
	soundPlayer.loadSound("signal2", "resources/signal2.wav");
	soundPlayer.loadSound("foundData", "resources/foundData.wav");
	soundPlayer.loadSound("idleScanner", "resources/idleScanner.wav");

	machine1 = Machine1(&console, &soundPlayer);


	camera.setScreenDimensions(1920, 1080);
	camera.setScreenshakeCutoff(1);
	camera.setScreenshakeDecay(0.9);
	spriteCollection.setUseCamera(true);
	spriteCollection.setPCamera(&camera);
	spriteCollection.setOrderZ(true);
	spriteCollection.addFont("resources/fonts/Hacked_CRT.TTF");
	objectCollection.setDebug(false);

	inputGenerator = InputGenerator();
}

void Game::HandleInput() {
	inputManager.update();
	inputManager.translateMouseCoords(camera.getPosition().x, camera.getPosition().y);
	if (inputManager.isKeyDown(space) && !inputManager.wasKeyDown(space)) {
		machine1.scan();
		//console.addCommand(commandPlaySound, "hh");
		//console.addCommand(commandShakeScreen, 15);	
	}
	if (inputManager.isKeyDown(f)) {
		//console.addCommand(commandEnableDebug, 1);
	}
	if (inputManager.isKeyDown(g)) {
		//console.addCommand(commandEnableDebug, 0);
	}
}

void Game::Run() {
	objectCollection.update();
	objectCollection.runCollisionDetection();
	while (console.getSize() > 0) {
		commandExecuter.execute(console.getCommand());
	}
	soundPlayer.update();
}

void Game::Draw() {

	// inside the main loop, between window.clear() and window.display()

	machine1.run();
	return;

	camera.runscreenShake();
	graphics.clearScreen(sf::Color(255, 255, 255, 100));

	spriteCollection.addImageDraw(sprite2, 400, 400, 400);
	spriteCollection.addImageDraw(sprite3, 800, 800, 800);
	spriteCollection.addImageDraw(sprite1, 400, 800, 800);
	//spriteCollection.addTextDraw(0, 20, 20, 20, "Test Text hello world TEST", 40, sf::Color::Black);

	//spriteCollection.addAbsoluteCircleDraw(inputManager.mouseX, inputManager.mouseY, 50, inputManager.mouseY, sf::Color(255, 0, 0, 255));
	spriteCollection.addCircleDraw(0, 0, 5, inputManager.mouseY, sf::Color(0, 255, 0, 255));

	objectCollection.draw();

	spriteCollection.drawAll();

	frame++;
}