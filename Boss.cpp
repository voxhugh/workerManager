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
//��ȡBoss��Ϣ
void Boss::show_Worker()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\tְλ��" << this->getDeptName()
		<< "\tְ��" << "����˾��������" << endl;

}

//��ȡBoss����
string Boss::getDeptName()
{

	string str = "�ܲ�";
	return str;

}