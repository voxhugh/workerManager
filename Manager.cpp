#include "Manager.h"



Manager::Manager(int id, string name, int dId)
{
this->m_Id = id;
this->m_Name = name;
this->m_DeptId = dId;

}

Manager::Manager()
{

}

Manager::~Manager()
{

};
//获取经理信息
void Manager::show_Worker()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职位：" << this->getDeptName()
		<< "\t职责：" << "听从老板安排，完成上级的工作，下发任务给员工" << endl;

}

//获取经理名称
string Manager::getDeptName()
{

	string str = "经理";
	return str;

}