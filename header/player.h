#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"
#include "slope.h"

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics &graphics, Vector2 spawnPoint);
	void draw(Graphics &graphics);
	void update(float elapsedTime);
	
	/* void moveleft
	* Moves the player left by -dx
	*/
	
	void moveLeft();
	/* void moveRight
	* Moves the player right by dx
	*/
	void moveRight();
	
	/* void stopMoving
	* Stops moving the player
	*/
	void stopMoving();
	
	/*
	* starts jumping
	*/
	
	/* void lookUp
	* The player looks up
	*/
	
	void lookUp();
	
	/* the player stops looking up 
	*/
	void stopLookingUp();
	void lookDown();
	void stopLookingDown();
	
	void jump();
	
	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();
	
	void handleTileCollisions(std::vector<Rectangle> &others);
	void handleSlopeCollisions(std::vector<Slope> &others);
	
	const float getX() const;
	const float getY() const;
	
private:
	float _dx, _dy;
	
	Direction _facing;
	
	bool _grounded;
	
	bool _lookingUp;
	bool _lookingDown;
};

#endif
