#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"
//�������Ա�Ĳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		Manager* man = (Manager*)manager;
		//������ָ��תΪ����ָ�룬���������������ӿ�
		int select = 0;
		//�����û���ѡ��
		cin >> select;
		if (select == 1)
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{

			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{

			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
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
	//���ù���Ա�Ӳ˵�
	student->operMenu();
	Student* stu = (Student*)student;
	//������ָ��תΪ����ָ�룬���������������ӿ�
	int select = 0;
	//�����û���ѡ��
	cin >> select;
	if (select == 1)
	{
		//����ԤԼ
		stu->applyOrder();
	}
	else if (select == 2)
	{//�鿴����ԤԼ

		stu->showMyOrder();
	}
	else if (select == 3)
	{//�鿴����ԤԼ
		stu->showMyOrder();
	}
	else if (select == 4)
	{

		//ȡ��ԤԼ
		stu->cancelOrder();
	}
	else
	{
		delete student;
		cout << "ע���ɹ�" << endl;
		system("pause");
		system("cls");
		return;
	}

    }
}




//��¼����
void LoginIn(string fileName, int type)
{


	Identity* person = NULL;//����ָ���������
	ifstream ifs;
	ifs.open(fileName, ios::in);
		//�ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//ѧ����¼
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ��¼

	{
		cout << "���������ְ�����룺" << endl;
		cin >> id;

	}
	cout << "����������û�����" << endl;
	cin >> name;
	cout << "������������룺" << endl;
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
				cout << "ѧ����֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵĲ˵�
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
				cout << "��ʦ��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ��ݵĲ˵�


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
				cout << "����Ա��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա��ݵĲ˵�
				managerMenu(person);

				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}




int main()
{
	int select = 0;
	while (true)
	{
		cout << "**********************��ӭ��������ԤԼϵͳ***********"
			<< endl;
		cout << endl << "���������" << endl;
		cout << "\t\t**************************************************\n";
		cout << "\t\t|            1.ѧ������                          |\n";
		cout << "\t\t|            2.��ʦ                              |\n";
		cout << "\t\t|            3.����Ա                            |\n";
		cout << "\t\t|            0.�˳�                              |\n";
		cout << "\t\t|                                                |\n";
		cout << "\t\t**************************************************\n";
		cout << "���������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "ѡ���������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	


	system("pause");
	return 0;
}