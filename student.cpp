#include"student.h"
//Ĭ�Ϲ���
Student::Student()
{


}

//�вι���
Student::Student(int id, string name, string pwd)
{
	//��ʼ��
	this->m_id= id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();


}
void Student::operMenu()
{
	cout << "��ӭѧ��������" << this->m_Name << "��½��" << endl;
	cout << "\t\t**************************************************\n";
	cout << "\t\t|            1.����ԤԼ                           |\n";
	cout << "\t\t|            2.�鿴�ҵ�ԤԼ                       |\n";
	cout << "\t\t|            3.�鿴����Ԥ                         |\n";
	cout << "\t\t|            4.ȡ��ԤԼ                           |\n";
	cout << "\t\t|            0.ע����¼                           |\n";
	cout << "\t\t**************************************************\n";
	cout << "���������ѡ��" << endl;


 }
//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��" << endl;
	cout << "����ԤԼʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "�������" << endl;

	}
	cout << "��������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;

		}
		cout << "������� ����������" << endl;

	}
	cout << "��ѡ�������ţ�" << endl;
	cout << "1�Ż�����������" << vCom[0].m_MaxNum << endl;
	cout << "2�Ż�����������" << vCom[1].m_MaxNum << endl;
	cout << "3�Ż�����������" << vCom[2].m_MaxNum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}

		cout << "���������������" << endl;


	}
	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_Name<< " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}
//�鿴ԤԼ
void Student::showMyOrder()
{


}
//�鿴����ԤԼ
void Student::showAllOrder()
{


}
//ȡ��ԤԼ
void Student::cancelOrder()
{


}