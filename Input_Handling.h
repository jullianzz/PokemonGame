/*Julia Zeng
EC 327 PA 4
Input_Handling.h*/

#ifndef INVALID_INPUT_H
#define INVALID_INPUT_H

#include <string>
#include <iostream>

using namespace std;

class Invalid_Input
{
public:
	Invalid_Input(string in_ptr) : msg_ptr (in_ptr) { }
	const string msg_ptr;

private:
	Invalid_Input();
	//no default construction
};





#endif