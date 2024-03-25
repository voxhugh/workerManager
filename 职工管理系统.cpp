#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "Worker.h"
#include "Boss.h"
#include "WorkerManager.h"





int main()
{
	//test01();


	
	WorkerManager wm;
	int choice;

	while (true)
	{

		wm.show_Menu();
		cout << "请输入提供的服务：" << endl;
		cin >> choice;

		switch (choice)
		{
			case 0:
				cout << "欢迎下次使用！" << endl;
				system("pause");
				exit(0);
				break;
			case 1:
				wm.add_Emp();
				break;
			case 2:
				wm.show_Emp();
				break;
			case 3:
				wm.delete_Emp();
				break;
			case 4:
				wm.mod_Emp();
				break;
			case 5:
				wm.find_Emp();
				break;
			case 6:
				wm.sort_Emp();
				break;
			case 7:
				wm.clear_Emp();
				break;
			default:
				system("cls");
				break;
		}




	}
	



	system("pause");
	return 0;

}