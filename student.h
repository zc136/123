#pragma once
/*����ѧ����
* ��ʾѧ�������Ĳ˵����� ����ԤԼ  �鿴����ԤԼ  ȡ��ԤԼ  
*/


#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"manager.h"
#include"teacher.h"
#include<functional>
#include<numeric>
#include<algorithm>
#include"computerRoom.h"
//ѧ����
class Student :public Identity
{
public:


	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
	//ѧ��ѧ��
	int m_id;
	vector<ComputerRoom>vCom;
};