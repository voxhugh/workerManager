#include "Boss.h"




Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}
Boss::Boss()
{
}

Boss::~Boss()
{



}
//获取Boss信息
void Boss::show_Worker()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职位：" << this->getDeptName()
		<< "\t职责：" << "管理公司所有事务" << endl;

}

//获取Boss名称
string Boss::getDeptName()
{

	string str = "总裁";
	return str;

}