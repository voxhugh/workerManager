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
	//��ȡԱ����Ϣ
	void Employee::show_Worker()
	{
		cout << "ְ����ţ�" << this->m_Id
			<< "\tְ��������" << this->m_Name
			<< "\tְλ��" << this->getDeptName()
			<< "\tְ��" << "����ϼ����ŵ�����" << endl;

	}

	//��ȡԱ������
	string Employee::getDeptName()
	{

		string str = "��ְͨ��";
		return str;

	}