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
//管理员类  对学生和老师账户进行管理   查看机房信息以及清空预约记录
//显示管理员操作的界面  添加账号  查看账号 查看机房信息  清空预约记录


class Manager :public Identity
{
public:
	
	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//添加账号
	void addPerson();
	//查账号
	void showPerson();
	//查看机房的信息
	void showComputer();
	//清空预约记录
	void cleanFile();

	//初始化容器
	void initVector();
	//学生容器
  vector <Student> vStu;
	//教师容器
	vector<Teacher>vTea;

	//检测是否有重复
	bool checkRepeat(int id, int type);

	vector<ComputerRoom>vCom;
};



