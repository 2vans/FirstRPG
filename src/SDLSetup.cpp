/*
 * SDLSetup.cpp
 *
 *  Created on: 25 sty 2016
 *      Author: Michau
 */

#include "SDLSetup.h"



SDL_Setup::SDL_Setup(int windowWidth, int windowHeight) {

	WINDOW_WIDTH = windowWidth;
	WINDOW_HEIGHT = windowHeight;
	m_event = new SDL_Event;


	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
	}
	// init of windwo
	m_window = SDL_CreateWindow("FirstRPG",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	//checking for error in initialization;
	if (m_window == NULL) {
	}

	//creating renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	//checkin if renderer is initialized.
	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}



}


SDL_Renderer *SDL_Setup::getRenderer() {
	return m_renderer;
}

SDL_Window *SDL_Setup::getWindow() {
	return m_window;
}

/*SDL_Event *SDL_Setup::getMainEvent() {
	return m_event;
}*/

void SDL_Setup::begin() {


			SDL_RenderClear(m_renderer);
}

SDL_Event *SDL_Setup::getMainEvent() {
	return m_event;
}



void SDL_Setup::end() {
	SDL_RenderPresent(m_renderer);
}

SDL_Setup::~SDL_Setup() {
	delete m_event;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}


