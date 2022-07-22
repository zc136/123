#pragma once
//#define_CRT_SECURE_NO_WARNINGS
#include"identity.h"
#include<iostream>
using namespace std;
/*教师类主要看学生的预约 并且审核
显示教师操作的页面
查看所有预约
审核预约*/



class Teacher :public Identity {

public:
	Teacher();//默认构造

	//有参构造(职工编号 姓名 密码)
	Teacher(int empId, string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void validOrder();
//教师编号
	int m_EmpId;

};

