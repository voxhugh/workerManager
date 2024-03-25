#pragma once
#include "Worker.h"
#include <iostream>
#include <string>

class Employee : public Worker
{

public:

	Employee();

	Employee(int id, string name, int dId);

	~Employee();

	virtual void show_Worker();

	virtual string getDeptName();

};