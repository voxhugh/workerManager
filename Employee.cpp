#include "Employee.h"



Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}


Employee::Employee()
	{

	}
Employee::~Employee()
	{
	}
	//获取员工信息
	void Employee::show_Worker()
	{
		cout << "职工编号：" << this->m_Id
			<< "\t职工姓名：" << this->m_Name
			<< "\t职位：" << this->getDeptName()
			<< "\t职责：" << "完成上级安排的任务" << endl;

	}

	//获取员工名称
	string Employee::getDeptName()
	{

		string str = "普通职工";
		return str;

	}