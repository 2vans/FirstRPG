/*
 * MainCharacter.h
 *
 *  Created on: 4 mar 2016
 *      Author: Michau
 */

#ifndef MAINCHARACTER_H_
#define MAINCHARACTER_H_
#include "SDLSetup.h"
#include "math.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "Environment.h"
#include "Inventory.h"


class MainCharacter {
private:
	float *m_cameraX;
	float *m_cameraY;


	bool m_quit;
	bool m_follow;
	Sprite *m_player;
	float m_followPointX;
	float m_followPointY;
	SDL_Setup *m_sdlSetup;
	int *m_mouseX;
	int *m_mouseY;
	Uint32 m_timeCheck;
	float m_distance;
	float m_angle;
	Environment *m_environment;

public:
	void drawSteady();
	void updateAnimation();
	void updateConstrols();
	float getDirection(float x1, float y1, float x2, float y2);
	void draw();
	void update();
	MainCharacter(SDL_Setup *sdlSetup, int *mouseX, int *mouseY, float *camerX, float *cameraY, Environment *environment);
	virtual ~MainCharacter();
	bool *getQuit();
};



#endif /* MAINCHARACTER_H_ */
