#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
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
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;



	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{

			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单

				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "验证登录成功!" << endl;
				//登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);
				return;
			}
		}
	}

	cout << "登录验证失败！" << endl;

	system("pause");
	system("cls");
	return;

}


int main()
{
	int select = 0;
	while (true)
	{
		cout << "====================== 欢迎来到传智播客机房预约系统 ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|           1.学生代表          |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|           2.老 师             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|           3.管 理 员          |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|           0.退 出             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select;//接受用户选择
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}