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
//��ȡ������Ϣ
void Manager::show_Worker()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\tְλ��" << this->getDeptName()
		<< "\tְ��" << "�����ϰ尲�ţ�����ϼ��Ĺ������·������Ա��" << endl;

}

//��ȡ��������
string Manager::getDeptName()
{

	string str = "����";
	return str;

}