//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	//静态成员函数特点：
//	//1 程序共享一个函数
//	//2 静态成员函数只能访问静态成员变量
//
//	static void func()
//	{
//		cout << "func调用" << endl;
//		m_A = 100;
//	}
//
//	static int m_A;//静态成员变量
//	int m_B;//
//private:
//	//静态成员函数也是有访问权限的
//	static void func2()
//	{
//		cout << "func2调用" << endl;
//	}
//};
//int Person::m_A = 10;
//
//void test01()
//{
//	//静态成员变量两种访问方式
//
//	//1.通过对象
//	Person p1;
//	p1.func();
//
//	//2.通过类名
//	Person::func();
//}
//
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}