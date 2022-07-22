#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"
//进入管理员的菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		Manager* man = (Manager*)manager;
		//将父类指针转为子类指针，调用了类里其他接口
		int select = 0;
		//接受用户的选项
		cin >> select;
		if (select == 1)
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{

			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{

			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}

}
void studentMenu(Identity*& student)
{
	while(true)
	{
	//调用管理员子菜单
	student->operMenu();
	Student* stu = (Student*)student;
	//将父类指针转为子类指针，调用了类里其他接口
	int select = 0;
	//接受用户的选项
	cin >> select;
	if (select == 1)
	{
		//申请预约
		stu->applyOrder();
	}
	else if (select == 2)
	{//查看自身预约

		stu->showMyOrder();
	}
	else if (select == 3)
	{//查看所有预约
		stu->showMyOrder();
	}
	else if (select == 4)
	{

		//取消预约
		stu->cancelOrder();
	}
	else
	{
		delete student;
		cout << "注销成功" << endl;
		system("pause");
		system("cls");
		return;
	}

    }
}




//登录功能
void LoginIn(string fileName, int type)
{


	Identity* person = NULL;//父类指向子类对象
	ifstream ifs;
	ifs.open(fileName, ios::in);
		//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)//教师登录

	{
		cout << "请输入你的职工号码：" << endl;
		cin >> id;

	}
	cout << "请输入你的用户名：" << endl;
	cin >> name;
	cout << "请输入你的密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			/*cout << fId << endl;
			cout << fName<< endl;
			cout << fPwd<< endl;
			cout << endl;*/
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的菜单
				studentMenu(person);
            	return;

			}
         }
	}
	else if (type == 2)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份的菜单


				return;
			}
		}

	}
	else if (type == 3)
	{	
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份的菜单
				managerMenu(person);

				return;
			}
		}
	}
	cout << "验证登录失败：" << endl;
	system("pause");
	system("cls");
	return;
}




int main()
{
	int select = 0;
	while (true)
	{
		cout << "**********************欢迎来到机房预约系统***********"
			<< endl;
		cout << endl << "请输入身份" << endl;
		cout << "\t\t**************************************************\n";
		cout << "\t\t|            1.学生代表                          |\n";
		cout << "\t\t|            2.老师                              |\n";
		cout << "\t\t|            3.管理员                            |\n";
		cout << "\t\t|            0.退出                              |\n";
		cout << "\t\t|                                                |\n";
		cout << "\t\t**************************************************\n";
		cout << "请输入你的选择：";
		cin >> select;
		switch (select)
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "选择错误，重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	


	system("pause");
	return 0;
}