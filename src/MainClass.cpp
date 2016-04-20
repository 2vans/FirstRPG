/*
 * MainClass.cpp
 *
 *  Created on: 25 sty 2016
 *      Author: Michau
 */

#include "MainClass.h"

MainClass::MainClass(int windowWidth, int windowHeight) {

	cameraX = 0;
	cameraY = 0;

	mouseX = 0;
	mouseY = 0;

	sdlSetup = new SDL_Setup(windowWidth, windowHeight);

	grass = new Environment(sdlSetup, windowWidth, windowHeight, &cameraX, &cameraY);
	grass->loadFromFile();

	player = new MainCharacter(sdlSetup, &mouseX, &mouseY, &cameraX, &cameraY, grass);
	inv = new Inventory(sdlSetup, &cameraX, &cameraY, 0, 0);

	quit = player->getQuit();

}

void MainClass::gameLoop() {

	while (*quit != true) {
		sdlSetup->begin();

		grass->update();
		grass->backDraw();

		player->drawSteady();
		grass->frontDraw();
		player->update();
		inv->drawInv();
		sdlSetup->end();
	}

}

MainClass::~MainClass() {
	delete sdlSetup;


delete player;
}
