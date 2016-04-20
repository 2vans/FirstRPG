/*
 * Sprite.cpp
 *
 *  Created on: 3 lut 2016
 *      Author: Michau
 */

#include "Sprite.h"

Sprite::Sprite(SDL_Renderer *renderer, const char*name, int x, int y, int w,
		int h, float *cameraX, float *cameraY,
		CollisionRectangle collisionRectangle) {

	m_collision = collisionRectangle;
	m_colRect = m_collision.getCollisionRect();

	m_cameraX = cameraX;
	m_cameraY = cameraY;

	m_renderer = renderer;
	m_image = IMG_LoadTexture(m_renderer, name);
	if (m_image == 0) {

	}

	m_cImage = IMG_LoadTexture(m_renderer, "Assets/colision.png");
	if (m_image == 0) {

	}
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;

	SDL_QueryTexture(m_image, NULL, NULL, &m_imageWidth, &m_imageHeight);

	m_crop.x = 0;
	m_crop.y = 0;
	m_crop.w = m_imageWidth;
	m_crop.h = m_imageHeight;

	m_frame = 0;
	m_frameX = 0;
	m_frameY = 0;

	m_timeCheck = SDL_GetTicks();
	m_posX = x;
	m_posY = y;

	m_startX = 0;
	m_startY = 0;

	m_camera.x = m_rect.x + *m_cameraX;
	m_camera.y = m_rect.y + *m_cameraY;
	m_camera.w = m_rect.w;
	m_camera.h = m_rect.h;
}

Sprite::~Sprite() {
	SDL_DestroyTexture(m_image);
	SDL_DestroyTexture(m_cImage);
}
float Sprite::getX() {
	return m_posX;
}
float Sprite::getY() {
	return m_posY;
}

void Sprite::setupAnimation(int frameX, int frameY) {

	m_frameX = frameX;
	m_frameY = frameY;

	m_crop.w = m_imageWidth / m_frameX;
	m_crop.h = m_imageWidth / m_frameY;
}

void Sprite::animation(int startFrame, int endFrame, int row, float speed) {

	if (m_timeCheck + speed < SDL_GetTicks()) {

		if (m_frame < endFrame) {
			m_frame++;
		} else {
			m_frame = startFrame;
		}

		m_crop.x = startFrame + (m_imageWidth / m_frameX) * m_frame;
		m_crop.y = row * (m_imageHeight / m_frameY);
		m_timeCheck = SDL_GetTicks();
	}
}

void Sprite::draw() {

	m_camera.x = m_rect.x + *m_cameraX;
	m_camera.y = m_rect.y + *m_cameraY;
	m_collision.setX(m_rect.x + *m_cameraX);
	m_collision.setY(m_rect.y + *m_cameraY);
	m_colRect = m_collision.getCollisionRect();

	SDL_RenderCopy(m_renderer, m_image, &m_crop, &m_camera);
	SDL_RenderCopy(m_renderer, m_cImage, NULL, &m_colRect);

}

void Sprite::drawSteady() {

	SDL_RenderCopy(m_renderer, m_image, &m_crop, &m_rect);
	SDL_RenderCopy(m_renderer, m_cImage, NULL, &m_colRect);
}

CollisionRectangle Sprite::GetCollision() {
	return m_collision;
}

SDL_Rect Sprite::getRect() {
	return m_rect;
}

bool Sprite::isCollaiding(CollisionRectangle collider) {
	return !(m_collision.getCollisionRect().x + m_collision.getCollisionRect().w
			< collider.getCollisionRect().x
			|| m_collision.getCollisionRect().y
					+ m_collision.getCollisionRect().h
					< collider.getCollisionRect().y
			|| m_collision.getCollisionRect().x
					> collider.getCollisionRect().x
							+ collider.getCollisionRect().w
			|| m_collision.getCollisionRect().y
					> collider.getCollisionRect().y
							+ collider.getCollisionRect().h);
}
void Sprite::setX(float x) {
	m_posX = x;
	m_rect.x = m_posX - m_startX;
}

void Sprite::setY(float y) {
	m_posY = y;
	m_rect.y = m_posY - m_startY;
}

void Sprite::setPos(float x, float y) {
	m_posX = x;
	m_posY = y;
	m_rect.x = m_posX - m_startX;
	m_rect.y = m_posY - m_startY;

}

void Sprite::setStartPos(float startX, float startY) {
	this->m_startX = startX;
	this->m_startY = startY;

	setPos(getX(), getY());
}
