#pragma once
#include "Worker.h"
#include <iostream>
#include <string>

class Boss : public Worker
{

public:

	Boss(int id, string name, int dId);

	Boss();


	~Boss();

	virtual void show_Worker();

	virtual string getDeptName();

};