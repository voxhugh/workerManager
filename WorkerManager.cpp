#include "WorkerManager.h"



//构造函数
WorkerManager::WorkerManager()
{
	//先检定，判断在磁盘是否有数据
	if (this->fileVFC()) {

		//统计职工人数
		this->m_EmpNum = this->getEmpNum();

		//创建职工数组
		this->m_EmpArr = new Worker * [this->m_EmpNum];

		//初始化
		this->initEmp();
	}


}

//析构函数
WorkerManager::~WorkerManager()
{

	//释放堆区数据
	if (this->m_EmpArr != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArr[i];
			this->m_EmpArr[i] = NULL;
		}

		delete[] this->m_EmpArr;
		this->m_EmpArr = NULL;

	}

}

//展示菜单
void WorkerManager::show_Menu()
{
	cout << "***************************************************" << endl;
	cout << "************** 欢迎使用职工管理系统！ *************" << endl;
	cout << "***************** 0.退出管理程序 ******************" << endl;
	cout << "***************** 1.增加职工信息 ******************" << endl;
	cout << "***************** 2.显示职工信息 ******************" << endl;
	cout << "***************** 3.删除离职职工 ******************" << endl;
	cout << "***************** 4.修改职工信息 ******************" << endl;
	cout << "***************** 5.查找职工信息 ******************" << endl;
	cout << "***************** 6.按照编号排序 ******************" << endl;
	cout << "***************** 7.清空所有文档 ******************" << endl;
	cout << "***************************************************" << endl;


}

//添加职工
void WorkerManager::add_Emp()
{
	int addNum;
	cout << "请输入要添加的职工人数：" << endl;
	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker * [newSize];

		//若内存原先有员工信息，先备份
		if (this->m_EmpArr != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArr[i];
			}

		}


		//追加用户添加的员工数组
		for (int i = m_EmpNum; i < addNum; i++)
		{
			int id;
			string name;
			int dId;


			cout << "请输入第 " << (i-m_EmpNum+1) << " 个" <<  "员工信息：" << endl;

			cout << "员工编号" << endl;
			cin >> id;

			//判断id是否重复
			if (!this->isOnlyKey(id))
			{
				system("pause");
				system("cls");
				return;
			}
			

			cout << "员工姓名" << endl;
			cin >> name;

			cout << "部门" << endl;

			cout << "\t1、普通员工" << endl;
			cout << "\t2、经理" << endl;
			cout << "\t3、总裁" << endl;
			cin >> dId;
			switch (dId)
			{
			case 1:
				newSpace[i] = new Employee;
				break;
			case 2:
				newSpace[i] = new Manager;
				break;
			case 3:
				newSpace[i] = new Boss;
				break;
			default:
				cout << "输入有误" << endl;
				system("pause");
				system("cls");
				break;
			}
			newSpace[i]->m_Id = id;
			newSpace[i]->m_Name = name;
			newSpace[i]->m_DeptId = dId;
		
		}

		//释放原数组并更改指针指向
		delete[] this->m_EmpArr;
		this->m_EmpArr = newSpace;

		//更新职工人数
		this->m_EmpNum = newSize;

		//存入磁盘
		this->save();

		//提示添加成功
		cout << "员工添加成功！" << endl;

		//置标志位为非空
		m_isEmpty = false;

	}
	else
	{

		cout << "输入有误" << endl;

	}

	//阻塞后刷屏
	system("pause");
	system("cls");



}

//显示职工
void WorkerManager::show_Emp()
{

	if (this->fileVFC())
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArr[i]->show_Worker();

		}
		cout << endl;

	}

	system("pause");
	system("cls");

}

//删除职工
void WorkerManager::delete_Emp()
{
	//文件不存在检定
	if (!this->fileVFC())
	{
		system("pause");
		system("cls");
		return;

	}
	int t_Id;
	cout << "请输入要删除职工的id号：" << endl;
	cin >> t_Id;
	int index = this->is_Exist(t_Id);
	//找到
	if (index != -1 && index != -2)
	{
		for (int i = index; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArr[i] = this->m_EmpArr[i + 1];

		}

		cout << "已删除编号为 " << t_Id << "的职工" << endl;
		this->m_EmpNum--;
		//保存到磁盘
		this->save();
		
	}
	//未找到
	else if (this->is_Exist(t_Id) == -2)
	{
		cout << "查无此人！" << endl;
	}
	
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::mod_Emp()
{

	//文件不存在检定
	if (!this->fileVFC())
	{
		system("pause");
		system("cls");
		return;
	}

	int t_Id;
	cout << "请输入要修改职工的id号：" << endl;
	cin >> t_Id;
	//保存返回的员工下标，-1是文件不存在，-2是查无此人
	int index = this->is_Exist(t_Id);
	if (index != -1 && index != -2)
	{
		delete this->m_EmpArr[index];
		cout << "已查到编号为" << index+1 << "的员工" << endl;
		cout << "请输入职工的最新信息：" << endl;
		int id, dId;
		string name;
		cout << "职工编号" << endl;
		cin >> id;
		cout << "职工姓名" << endl;
		cin >> name;
		cout << "职工部门" << endl;
		cout << "\t1、普通员工" << endl;
		cout << "\t2、经理" << endl;
		cout << "\t3、总裁" << endl;
		cin >> dId;
		Worker* wk = NULL;
		switch (dId)
		{
		case 1:
			wk = new Employee(id, name, dId);
			break;
		case 2:
			wk = new Manager(id, name, dId);
			break;
		case 3:
			wk = new Boss(id, name, dId);
			break;
		}
		this->m_EmpArr[index] = wk;
		cout << "修改成功！" << endl;
		//保存到磁盘
		this->save();
	}
	else if (index == -2)
	{
		cout << "查无此人！" << endl;

	}
	system("pause");
	system("cls");

}

//查找职工
void WorkerManager::find_Emp()
{
	//文件不存在检定
	if (!this->fileVFC())
	{
		system("pause");
		system("cls");
		return;

	}
	cout << "请输入要查找的方式：" << endl;
	cout << "\t1、按编号" << endl;
	cout << "\t2、按姓名" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		int temId;
		cout << "请输入要查找的职工id:" << endl;
		cin >> temId;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArr[i]->m_Id == temId)
			{
				this->m_EmpArr[i]->show_Worker();
				system("pause");
				system("cls");
				return;
			}

		}
	}
	else
	{
		string temName;
		cout << "请输入要查找的职工姓名:" << endl;
		cin >> temName;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArr[i]->m_Name == temName)
			{
				this->m_EmpArr[i]->show_Worker();
				system("pause");
				system("cls");
				return;
			}
		}
	}
	cout << "查无此人！" << endl;
	system("pause");
	system("cls");
	return;

}

//职工排序
void WorkerManager::sort_Emp()
{
	//文件不存在检定
	if (!this->fileVFC())
	{
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入按编号的排序方式：" << endl;
	cout << "\t1、升序" << endl;
	cout << "\t2、降序" << endl;
	int select;
	cin >> select;

	int maxOrmin;
	//选择排序算法
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		maxOrmin = i;
		switch (select)
		{
		case 2:

			for (int j = i; j < this->m_EmpNum - 1; j++)
			{
				if (this->m_EmpArr[j + 1] > this->m_EmpArr[maxOrmin])
				{
					maxOrmin = j + 1;
				}

			}

			break;
		default:
			for (int j = i; j < this->m_EmpNum - 1; j++)
			{
				if (this->m_EmpArr[j + 1] < this->m_EmpArr[maxOrmin])
				{
					maxOrmin = j + 1;
				}

			}
			break;
		}
		//交换
			Worker* temp;
			temp = this->m_EmpArr[i];
			this->m_EmpArr[i] = this->m_EmpArr[maxOrmin];
			this->m_EmpArr[maxOrmin] = temp;

	}
	//保存到磁盘
	this->save();


}

//清空职工
void WorkerManager::clear_Emp()
{
	int select;
	cout << "是否确认清空所有职工？" << endl;
	cout << "\t1、确认" << endl;
	cout << "\t2、返回" << endl;
	cin >> select;
	if (select == 1)
	{
		//trunc清空磁盘信息
		fstream ofs(FILENAME, ios::trunc);
		ofs.close();
		//释放堆区数组对象与数组指针
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArr[i];
			this->m_EmpArr[i] = NULL;
		}
		delete[] this->m_EmpArr;
		this->m_EmpArr = NULL;
		this->initP();
		cout << "职工信息已清空！" << endl;
	}
	else
	{
		cout << "已返回！" << endl;
	}
	system("pause");
	system("cls");
}

//职工存在
bool WorkerManager::is_Exist(int tempId)
{


	//先查询文件是否存在
	if (this->fileVFC())
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArr[i]->m_Id == tempId)
			{
				return i;

			}

		}
		//未找到返回-2
		return -2;
	}
	//不存在返回-1
	return -1;

}

//保存到磁盘
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	//成行读入
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArr[i]->m_Id << " "
		<< this->m_EmpArr[i]->m_Name << " "
		<< this->m_EmpArr[i]->m_DeptId << endl;
	}
	ofs.close();

}

//读文件检定
bool WorkerManager::fileVFC()
{
	fstream ifs;
	ifs.open(FILENAME, ios::in);

	//1、文件不存在,初始化属性
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->initP();

		ifs.close();
		return false;
	}

	//2、文件为空，初始化属性
	char ch;
	ifs >> ch;

	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		this->initP();
		ifs.close();
		return false;
	}

	ifs.close();

	//3、文件存在，直接返回

	return true;

}

//统计磁盘职工人数
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id, dId, num=0;
	string name;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;

	}

	ifs.close();
	//置非空标志，更新员工人数
	this->m_isEmpty = false;
	this->m_EmpNum = num;

	return num;
}

//初始化磁盘读入的职工
void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id, dId, index = 0;
	string name;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//依据部门使指向 Worker * 的指针重定向,实现多态
		Worker* wk = NULL;
		switch (dId)
		{
		case 1:
			wk = new Employee(id,name,dId);
			break;
		case 2:
			wk = new Manager(id,name,dId);
			break;
		case 3:
			wk = new Boss(id,name,dId);
			break;

		}
		this->m_EmpArr[index] = wk;
		index++;
	}
	ifs.close();
	
	cout << "初始化成功！" << endl;

}

//id为主键，编号唯一
bool WorkerManager::isOnlyKey(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArr[i]->m_Id == id)
		{
			cout << "职工id已存在，不可重复添加！" << endl;
			return false;
		}
	}
	return true;
}


//属性初始化
void WorkerManager::initP()
{
	m_EmpNum = 0;
	m_EmpArr = NULL;
	m_isEmpty = true;

}