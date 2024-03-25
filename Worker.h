#pragma once
#include <iostream>
#include <string>
using namespace std;


class Worker
{
public:

	//显示职工信息
	virtual void show_Worker()=0;

	//获取部门名称
	virtual string getDeptName()=0;

	int m_Id;
	string m_Name;
	int m_DeptId;
};