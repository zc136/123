#pragma once
/*创建学生类
* 显示学生操作的菜单界面 申请预约  查看自身预约  取消预约  
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
//学生类
class Student :public Identity
{
public:


	//默认构造
	Student();

	//有参构造
	Student(int id, string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//申请预约
	void applyOrder();
	//查看预约
	void showMyOrder();
	//查看所有预约
	void showAllOrder();
	//取消预约
	void cancelOrder();
	//学生学号
	int m_id;
	vector<ComputerRoom>vCom;
};