/*
 * MainCharacter.cpp
 *
 *  Created on: 4 mar 2016
 *      Author: Michau
 */

#include "MainCharacter.h"

MainCharacter::MainCharacter(SDL_Setup *sdlSetup, int *mouseX, int *mouseY,
		float *cameraX, float *cameraY, Environment *environment) {

	m_environment = environment;

	m_cameraX = cameraX;
	m_cameraY = cameraY;

	m_distance = 0;
	m_angle = 0;

	m_sdlSetup = sdlSetup;
	m_mouseX = mouseX;
	m_mouseY = mouseY;

	m_quit = false;

	m_follow = false;

	m_followPointX = 0;
	m_followPointY = 0;

	m_timeCheck = SDL_GetTicks();
	m_player = new Sprite(m_sdlSetup->getRenderer(),
			"Assets/playerCharacter.png", 400, 300, 60, 80, m_cameraX,
			m_cameraY, CollisionRectangle(400 - 15, 300 - 76 + 65, 30, 15));

	m_player->setStartPos(30, 76);
	m_player->setupAnimation(4, 4);

}

float MainCharacter::getDirection(float x1, float y1, float x2, float y2) {
	float differenceX = x1 - x2;
	float differenceY = y1 - y2;

	float distance = sqrt(
			(differenceX * differenceX) + (differenceY * differenceY));

	return distance;

}

void MainCharacter::draw() {
	m_player->draw();
}

void MainCharacter::drawSteady() {
	m_player->drawSteady();
}

void MainCharacter::updateAnimation() {
	m_angle = atan2((m_followPointY - *m_cameraY),
			(m_followPointX - *m_cameraX));

	m_angle = (m_angle * (180 / 3.14)) + 180;

	if (m_angle >= 45 && m_angle < 135) {
		if (m_follow) {
			m_player->animation(0, 3, 0, 333);
		} else {
			m_player->animation(0, 0, 0, 33);
		}

	} else if (m_angle >= 135 && m_angle < 225) {
		if (m_follow) {
			m_player->animation(0, 3, 2, 333);
		} else {
			m_player->animation(3, 3, 2, 33);
		}
	} else if (m_angle >= 225 && m_angle < 315) {
		if (m_follow) {
			m_player->animation(0, 3, 0, 333);
		} else {
			m_player->animation(0, 0, 0, 33);
		}
	} else {
		if (m_follow) {
			m_player->animation(0, 3, 2, 333);
		} else {
			m_player->animation(3, 3, 2, 33);
		}
	}
}

void MainCharacter::updateConstrols() {
	SDL_GetMouseState(m_mouseX, m_mouseY);

	while (SDL_PollEvent(m_sdlSetup->getMainEvent())) {
		if (m_sdlSetup->getMainEvent()->type == SDL_QUIT) {
			m_quit = true;
		}
	}
	if (m_sdlSetup->getMainEvent()->type == SDL_MOUSEBUTTONDOWN
			|| m_sdlSetup->getMainEvent()->type == SDL_MOUSEMOTION) {
		if (m_sdlSetup->getMainEvent()->button.button == SDL_BUTTON_LEFT) {
			m_followPointX = *m_cameraX - *m_mouseX + 400;
			m_followPointY = *m_cameraY - *m_mouseY + 300;

			m_follow = true;
		}
	}

	m_distance = getDirection(*m_cameraX, *m_cameraY, m_followPointX,
			m_followPointY);
	bool coliding = false;

	if (m_timeCheck + 10 < SDL_GetTicks() && m_follow) {

		for (unsigned int i = 0; i < m_environment->getTrees().size(); i++) {
			if (m_player->isCollaiding(
					m_environment->getTrees()[i]->getTrunk()->GetCollision())) {
				if (*m_cameraX > m_followPointX) {
					*m_cameraX = *m_cameraX + 2;
				}
				if (*m_cameraX < m_followPointX) {
					*m_cameraX = *m_cameraX - 2;
				}
				if (*m_cameraY > m_followPointY) {
					*m_cameraY = *m_cameraY + 2;
				}
				if (*m_cameraY < m_followPointY) {
					*m_cameraY = *m_cameraY - 2;
				}

				coliding = true;
				m_followPointX = *m_cameraX;
				m_followPointY = *m_cameraY;
			}
		}

		m_timeCheck = SDL_GetTicks();
		if (!coliding) {
			if (m_distance > 2.0) {

				if (*m_cameraX != m_followPointX) {
					*m_cameraX = (*m_cameraX
							- ((*m_cameraX - m_followPointX) / m_distance)
									* 2.0f);

				}

				if (*m_cameraY != m_followPointY) {
					*m_cameraY = (*m_cameraY
							- ((*m_cameraY - m_followPointY) / m_distance)
									* 2.0f);

				}

			} else
				m_follow = false;
		}
	}
	m_timeCheck = SDL_GetTicks();
}

void MainCharacter::update() {

	updateConstrols();
	updateAnimation();

	for (unsigned int i = 0; i < m_environment->getTrees().size(); i++) {
		if (m_player->isCollaiding(
				m_environment->getTrees()[i]->getTrunk()->GetCollision())) {
			std::cout << "koliduje kurna!" << std::endl;
		}
	}

}

bool *MainCharacter::getQuit() {
	return &m_quit;
}
MainCharacter::~MainCharacter() {
	delete m_player;
}

