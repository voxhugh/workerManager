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
	//构造函数
	WorkerManager();

	//析构函数
	~WorkerManager();

	//展示菜单
	void show_Menu();

	//添加职工
	void add_Emp();

	//显示职工
	void show_Emp();

	//删除职工
	void delete_Emp();

	//修改职工
	void mod_Emp();
	
	//查找职工
	void find_Emp();

	//职工排序
	void sort_Emp();

	//清空职工
	void clear_Emp();

	//职工存在
	bool is_Exist(int tempId);

	//保存到磁盘
	void save();
	
	//读文件检定
	bool fileVFC();

	//统计磁盘职工人数
	int getEmpNum();

	//初始化磁盘读入的职工
	void initEmp();

	//id为主键，编号唯一
	bool isOnlyKey(int id);

	//属性初始化
	void initP();

	//职工人数
	int m_EmpNum;

	//职工指针，管理和维护堆区的 Worker * 数组
	Worker** m_EmpArr;

	//空标志位
	bool m_isEmpty;

};