#pragma once
#include "Worker.h"
#include <iostream>
#include <string>

class Manager : public Worker
{

public:

	Manager(int id, string name, int dId);

	Manager();

	~Manager();

	virtual void show_Worker();

	virtual string getDeptName();

};