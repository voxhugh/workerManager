#pragma once
#include<iostream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include <string>
#include <fstream>
#define FILENAME "./empsInfo.txt"
using namespace std;

class WorkerManager
{
public :
	//���캯��
	WorkerManager();

	//��������
	~WorkerManager();

	//չʾ�˵�
	void show_Menu();

	//���ְ��
	void add_Emp();

	//��ʾְ��
	void show_Emp();

	//ɾ��ְ��
	void delete_Emp();

	//�޸�ְ��
	void mod_Emp();
	
	//����ְ��
	void find_Emp();

	//ְ������
	void sort_Emp();

	//���ְ��
	void clear_Emp();

	//ְ������
	bool is_Exist(int tempId);

	//���浽����
	void save();
	
	//���ļ��춨
	bool fileVFC();

	//ͳ�ƴ���ְ������
	int getEmpNum();

	//��ʼ�����̶����ְ��
	void initEmp();

	//idΪ���������Ψһ
	bool isOnlyKey(int id);

	//���Գ�ʼ��
	void initP();

	//ְ������
	int m_EmpNum;

	//ְ��ָ�룬�����ά�������� Worker * ����
	Worker** m_EmpArr;

	//�ձ�־λ
	bool m_isEmpty;

};