#include "WorkerManager.h"



//���캯��
WorkerManager::WorkerManager()
{
	//�ȼ춨���ж��ڴ����Ƿ�������
	if (this->fileVFC()) {

		//ͳ��ְ������
		this->m_EmpNum = this->getEmpNum();

		//����ְ������
		this->m_EmpArr = new Worker * [this->m_EmpNum];

		//��ʼ��
		this->initEmp();
	}


}

//��������
WorkerManager::~WorkerManager()
{

	//�ͷŶ�������
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

//չʾ�˵�
void WorkerManager::show_Menu()
{
	cout << "***************************************************" << endl;
	cout << "************** ��ӭʹ��ְ������ϵͳ�� *************" << endl;
	cout << "***************** 0.�˳�������� ******************" << endl;
	cout << "***************** 1.����ְ����Ϣ ******************" << endl;
	cout << "***************** 2.��ʾְ����Ϣ ******************" << endl;
	cout << "***************** 3.ɾ����ְְ�� ******************" << endl;
	cout << "***************** 4.�޸�ְ����Ϣ ******************" << endl;
	cout << "***************** 5.����ְ����Ϣ ******************" << endl;
	cout << "***************** 6.���ձ������ ******************" << endl;
	cout << "***************** 7.��������ĵ� ******************" << endl;
	cout << "***************************************************" << endl;


}

//���ְ��
void WorkerManager::add_Emp()
{
	int addNum;
	cout << "������Ҫ��ӵ�ְ��������" << endl;
	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker * [newSize];

		//���ڴ�ԭ����Ա����Ϣ���ȱ���
		if (this->m_EmpArr != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArr[i];
			}

		}


		//׷���û���ӵ�Ա������
		for (int i = m_EmpNum; i < addNum; i++)
		{
			int id;
			string name;
			int dId;


			cout << "������� " << (i-m_EmpNum+1) << " ��" <<  "Ա����Ϣ��" << endl;

			cout << "Ա�����" << endl;
			cin >> id;

			//�ж�id�Ƿ��ظ�
			if (!this->isOnlyKey(id))
			{
				system("pause");
				system("cls");
				return;
			}
			

			cout << "Ա������" << endl;
			cin >> name;

			cout << "����" << endl;

			cout << "\t1����ͨԱ��" << endl;
			cout << "\t2������" << endl;
			cout << "\t3���ܲ�" << endl;
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
				cout << "��������" << endl;
				system("pause");
				system("cls");
				break;
			}
			newSpace[i]->m_Id = id;
			newSpace[i]->m_Name = name;
			newSpace[i]->m_DeptId = dId;
		
		}

		//�ͷ�ԭ���鲢����ָ��ָ��
		delete[] this->m_EmpArr;
		this->m_EmpArr = newSpace;

		//����ְ������
		this->m_EmpNum = newSize;

		//�������
		this->save();

		//��ʾ��ӳɹ�
		cout << "Ա����ӳɹ���" << endl;

		//�ñ�־λΪ�ǿ�
		m_isEmpty = false;

	}
	else
	{

		cout << "��������" << endl;

	}

	//������ˢ��
	system("pause");
	system("cls");



}

//��ʾְ��
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

//ɾ��ְ��
void WorkerManager::delete_Emp()
{
	//�ļ������ڼ춨
	if (!this->fileVFC())
	{
		system("pause");
		system("cls");
		return;

	}
	int t_Id;
	cout << "������Ҫɾ��ְ����id�ţ�" << endl;
	cin >> t_Id;
	int index = this->is_Exist(t_Id);
	//�ҵ�
	if (index != -1 && index != -2)
	{
		for (int i = index; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArr[i] = this->m_EmpArr[i + 1];

		}

		cout << "��ɾ�����Ϊ " << t_Id << "��ְ��" << endl;
		this->m_EmpNum--;
		//���浽����
		this->save();
		
	}
	//δ�ҵ�
	else if (this->is_Exist(t_Id) == -2)
	{
		cout << "���޴��ˣ�" << endl;
	}
	
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::mod_Emp()
{

	//�ļ������ڼ춨
	if (!this->fileVFC())
	{
		system("pause");
		system("cls");
		return;
	}

	int t_Id;
	cout << "������Ҫ�޸�ְ����id�ţ�" << endl;
	cin >> t_Id;
	//���淵�ص�Ա���±꣬-1���ļ������ڣ�-2�ǲ��޴���
	int index = this->is_Exist(t_Id);
	if (index != -1 && index != -2)
	{
		delete this->m_EmpArr[index];
		cout << "�Ѳ鵽���Ϊ" << index+1 << "��Ա��" << endl;
		cout << "������ְ����������Ϣ��" << endl;
		int id, dId;
		string name;
		cout << "ְ�����" << endl;
		cin >> id;
		cout << "ְ������" << endl;
		cin >> name;
		cout << "ְ������" << endl;
		cout << "\t1����ͨԱ��" << endl;
		cout << "\t2������" << endl;
		cout << "\t3���ܲ�" << endl;
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
		cout << "�޸ĳɹ���" << endl;
		//���浽����
		this->save();
	}
	else if (index == -2)
	{
		cout << "���޴��ˣ�" << endl;

	}
	system("pause");
	system("cls");

}

//����ְ��
void WorkerManager::find_Emp()
{
	//�ļ������ڼ춨
	if (!this->fileVFC())
	{
		system("pause");
		system("cls");
		return;

	}
	cout << "������Ҫ���ҵķ�ʽ��" << endl;
	cout << "\t1�������" << endl;
	cout << "\t2��������" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		int temId;
		cout << "������Ҫ���ҵ�ְ��id:" << endl;
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
		cout << "������Ҫ���ҵ�ְ������:" << endl;
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
	cout << "���޴��ˣ�" << endl;
	system("pause");
	system("cls");
	return;

}

//ְ������
void WorkerManager::sort_Emp()
{
	//�ļ������ڼ춨
	if (!this->fileVFC())
	{
		system("pause");
		system("cls");
		return;
	}
	cout << "�����밴��ŵ�����ʽ��" << endl;
	cout << "\t1������" << endl;
	cout << "\t2������" << endl;
	int select;
	cin >> select;

	int maxOrmin;
	//ѡ�������㷨
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
		//����
			Worker* temp;
			temp = this->m_EmpArr[i];
			this->m_EmpArr[i] = this->m_EmpArr[maxOrmin];
			this->m_EmpArr[maxOrmin] = temp;

	}
	//���浽����
	this->save();


}

//���ְ��
void WorkerManager::clear_Emp()
{
	int select;
	cout << "�Ƿ�ȷ���������ְ����" << endl;
	cout << "\t1��ȷ��" << endl;
	cout << "\t2������" << endl;
	cin >> select;
	if (select == 1)
	{
		//trunc��մ�����Ϣ
		fstream ofs(FILENAME, ios::trunc);
		ofs.close();
		//�ͷŶ����������������ָ��
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArr[i];
			this->m_EmpArr[i] = NULL;
		}
		delete[] this->m_EmpArr;
		this->m_EmpArr = NULL;
		this->initP();
		cout << "ְ����Ϣ����գ�" << endl;
	}
	else
	{
		cout << "�ѷ��أ�" << endl;
	}
	system("pause");
	system("cls");
}

//ְ������
bool WorkerManager::is_Exist(int tempId)
{


	//�Ȳ�ѯ�ļ��Ƿ����
	if (this->fileVFC())
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArr[i]->m_Id == tempId)
			{
				return i;

			}

		}
		//δ�ҵ�����-2
		return -2;
	}
	//�����ڷ���-1
	return -1;

}

//���浽����
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	//���ж���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArr[i]->m_Id << " "
		<< this->m_EmpArr[i]->m_Name << " "
		<< this->m_EmpArr[i]->m_DeptId << endl;
	}
	ofs.close();

}

//���ļ��춨
bool WorkerManager::fileVFC()
{
	fstream ifs;
	ifs.open(FILENAME, ios::in);

	//1���ļ�������,��ʼ������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->initP();

		ifs.close();
		return false;
	}

	//2���ļ�Ϊ�գ���ʼ������
	char ch;
	ifs >> ch;

	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->initP();
		ifs.close();
		return false;
	}

	ifs.close();

	//3���ļ����ڣ�ֱ�ӷ���

	return true;

}

//ͳ�ƴ���ְ������
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
	//�÷ǿձ�־������Ա������
	this->m_isEmpty = false;
	this->m_EmpNum = num;

	return num;
}

//��ʼ�����̶����ְ��
void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id, dId, index = 0;
	string name;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//���ݲ���ʹָ�� Worker * ��ָ���ض���,ʵ�ֶ�̬
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
	
	cout << "��ʼ���ɹ���" << endl;

}

//idΪ���������Ψһ
bool WorkerManager::isOnlyKey(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArr[i]->m_Id == id)
		{
			cout << "ְ��id�Ѵ��ڣ������ظ���ӣ�" << endl;
			return false;
		}
	}
	return true;
}


//���Գ�ʼ��
void WorkerManager::initP()
{
	m_EmpNum = 0;
	m_EmpArr = NULL;
	m_isEmpty = true;

}