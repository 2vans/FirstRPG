/*
 * Environment.cpp
 *
 *  Created on: 9 mar 2016
 *      Author: Michau
 */

#include "Environment.h"

Environment::Environment(SDL_Setup *sdlSetup, int windowWidth, int windowHeight,
		float *cameraX, float *cameraY) {

	m_sdlSetup = sdlSetup;
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;

	m_cameraX = cameraX;
	m_cameraY = cameraY;

	m_onePress = false;

	m_mode = game;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			m_grass[i][j] = new Sprite(m_sdlSetup->getRenderer(),
					"Assets/background.bmp", i * m_windowWidth,
					j * m_windowHeight, m_windowWidth, m_windowHeight, cameraX,
					cameraY, CollisionRectangle());

		}
	}

}

void Environment::backDraw() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			m_grass[i][j]->draw();
		}
	}

	for (std::vector<Tree*>::iterator i = m_trees.begin(); i != m_trees.end();
			i++) {
		(*i)->drawTrunk();
	}
}

void Environment::frontDraw() {
	for (std::vector<Tree*>::iterator i = m_trees.begin(); i != m_trees.end();
			i++) {
		(*i)->drawCrown();
	}
}

void Environment::update() {
	if (m_mode == creationMode) {

		if (m_sdlSetup->getMainEvent()->type == SDL_KEYDOWN) {
			if (!m_onePress
					&& m_sdlSetup->getMainEvent()->key.keysym.sym == SDLK_F1) {
				m_trees.push_back(
						new Tree(m_sdlSetup, -*m_cameraX + 388,
								-*m_cameraY + 149, m_cameraX, m_cameraY));
				m_onePress = true;
			}

			if (!m_onePress
					&& m_sdlSetup->getMainEvent()->key.keysym.sym == SDLK_F2) {
				if (m_trees.size() > 0 )
					delete *m_trees.end();
				m_trees.pop_back();
				m_onePress = true;
			}

			if (!m_onePress
					&& m_sdlSetup->getMainEvent()->key.keysym.sym == SDLK_F11) {
				std::ofstream loadFile;
				loadFile.open("Assets/stageLayout.txt");

				loadFile << "====TREES====" << std::endl;
				for (std::vector<Tree*>::iterator i = m_trees.begin();
						i != m_trees.end(); i++) {

					loadFile << "X: " << (*i)->getX() << " Y: " << (*i)->getY()
							<< std::endl;

				}
				loadFile << "====NO_TREES====" << std::endl;
				loadFile.close();
				m_onePress = true;
			}
		}

		if (m_sdlSetup->getMainEvent()->type == SDL_KEYUP) {
			if (m_onePress
					&& m_sdlSetup->getMainEvent()->key.keysym.sym == SDLK_F1) {
				m_onePress = false;
			}
		}
		if (m_sdlSetup->getMainEvent()->type == SDL_KEYUP) {
					if (m_onePress
							&& m_sdlSetup->getMainEvent()->key.keysym.sym == SDLK_F2) {
						m_onePress = false;
					}
				}
	}

	if (m_sdlSetup->getMainEvent()->type == SDL_KEYDOWN) {
		if (!m_onePress
				&& m_sdlSetup->getMainEvent()->key.keysym.sym == SDLK_F12) {
			if (m_mode == game) {
				m_mode = creationMode;
			} else if (m_mode == creationMode) {
				m_mode = game;
			}

			m_onePress = true;
		}
	}

	if (m_sdlSetup->getMainEvent()->type == SDL_KEYUP) {
		if (m_onePress
				&& m_sdlSetup->getMainEvent()->key.keysym.sym == SDLK_F12) {
			m_onePress = false;
		}
	}

}

void Environment::saveToFile() {
	std::ofstream loadFile;
	loadFile.open("Assets/stageLayout.txt");
	loadFile << "kurna to działA" << std::endl;

	loadFile.close();
	std::cout << "Fukuczce zapisałem stoo!" << std::endl;

}

std::vector<Tree*> Environment::getTrees() {
	return m_trees;
}

void Environment::loadFromFile() {
	enum modes {
		noMode, trees
	};

	int mode = trees;

	std::ifstream loadedSrile("Assets/stageLayout.txt");
	std::string line;

	if (loadedSrile.is_open()) {
		while (loadedSrile.good()) {
			std::getline(loadedSrile, line);

			if (line == "====TREES====") {
				mode = trees;
			} else if (line == "====NO_TREES====") {
				mode = noMode;
			} else {
				if (mode == trees) {

					std::istringstream iss(line);

					int tempX;
					int tempY;
					std::string previousWord;
					std::string word;
					while (iss) {
						iss >> word;
						if (previousWord == "X:") {
							tempX = atoi(word.c_str());
						} else if (previousWord == "Y:") {
							tempY = atoi(word.c_str());
							m_trees.push_back(
									new Tree(m_sdlSetup, tempX, tempY,
											m_cameraX, m_cameraY));
						}
						previousWord = word;
					}
				}
			}
		}

	} else {
		std::cout << "Srile sie nie otworzyły" << std::endl;
	}
	loadedSrile.close();
}

Environment::~Environment() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			delete m_grass[i][j];
		}
	}
}

