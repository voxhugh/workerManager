#pragma once
#include <iostream>
#include <string>
using namespace std;


class Worker
{
public:

	//��ʾְ����Ϣ
	virtual void show_Worker()=0;

	//��ȡ��������
	virtual string getDeptName()=0;

	int m_Id;
	string m_Name;
	int m_DeptId;
};