/*Julia Zeng
EC 327 PA3
GameObject.h*/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Point2D.h"
#include "Vector2D.h"
#include <iostream>
using namespace std;

class GameObject
{
protected: 

	Point2D location;
	int id_num;
	char display_code; 
	char state;

public:
	GameObject(char in_code); 
	GameObject(Point2D in_loc, int in_id, char in_code);

	virtual bool Update() = 0;
	Point2D GetLocation();
	int GetId();
	char GetState();
	char GetDisplayCode();
	virtual ~GameObject() = 0;
	virtual void ShowStatus();
	virtual bool ShouldBeVisible() = 0;
	void DrawSelf(char* ptr);

	
};


#endif 