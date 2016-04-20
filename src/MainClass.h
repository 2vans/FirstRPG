/*
 * MainClass.h
 *
 *  Created on: 25 sty 2016
 *      Author: Michau
 */

#ifndef MAINCLASS_H_
#define MAINCLASS_H_
#include <stdlib.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDLSetup.h"
#include "Sprite.h"
#include "math.h"
#include "MainCharacter.h"
#include "Environment.h"
#include "Inventory.h"


class MainClass {


private:

	float cameraX;
	float cameraY;



	SDL_Setup *sdlSetup;
	MainCharacter *player;
	Environment *grass;
	Inventory *inv;
	bool *quit;
	int mouseX;
	int mouseY;

	//Uint32 timeCheck;




public:
	MainClass(int windowWidth, int windowHeight);
	virtual ~MainClass();
	void gameLoop();


};



#endif /* MAINCLASS_H_ */
