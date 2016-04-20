/*
 * SDLSetup.h
 *
 *  Created on: 25 sty 2016
 *      Author: Michau
 */

#ifndef SDLSETUP_H_
#define SDLSETUP_H_

#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>



class SDL_Setup {
public:
	int WINDOW_WIDTH;
	int  WINDOW_HEIGHT;
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Event *m_event;

public:
	SDL_Setup(int windowWidth, int windowHeight);
	virtual ~SDL_Setup();
	SDL_Renderer *getRenderer();
	SDL_Window *getWindow();
	SDL_Event *getMainEvent();


	void begin();
	void end();
};



#endif /* SDLSETUP_H_ */
