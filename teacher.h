#pragma once
//#define_CRT_SECURE_NO_WARNINGS
#include"identity.h"
#include<iostream>
using namespace std;
/*��ʦ����Ҫ��ѧ����ԤԼ �������
��ʾ��ʦ������ҳ��
�鿴����ԤԼ
���ԤԼ*/



class Teacher :public Identity {

public:
	Teacher();//Ĭ�Ϲ���

	//�вι���(ְ����� ���� ����)
	Teacher(int empId, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
//��ʦ���
	int m_EmpId;

};

