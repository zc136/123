#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<functional>
#include<numeric>
#include<algorithm>
#include"computerRoom.h"
//����Ա��  ��ѧ������ʦ�˻����й���   �鿴������Ϣ�Լ����ԤԼ��¼
//��ʾ����Ա�����Ľ���  ����˺�  �鿴�˺� �鿴������Ϣ  ���ԤԼ��¼


class Manager :public Identity
{
public:
	
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//����˺�
	void addPerson();
	//���˺�
	void showPerson();
	//�鿴��������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();
	//ѧ������
  vector <Student> vStu;
	//��ʦ����
	vector<Teacher>vTea;

	//����Ƿ����ظ�
	bool checkRepeat(int id, int type);

	vector<ComputerRoom>vCom;
};



