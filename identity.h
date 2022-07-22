#pragma once
#include<iostream>
using namespace std;


/*
在整个系统中 有三种身份 学生代表 老师 管理员
三种身份有着共性也有其特性 因此我们可以将三种身份抽象出一个身份类   identity
在头文件上创建iden.h的文件*/


class Identity//身份抽象类
{

public:
	virtual void operMenu() = 0;//用户菜单  纯虚函数





	string m_Name;//用户名
	string m_Pwd;//密码
};
