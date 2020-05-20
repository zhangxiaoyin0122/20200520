#include <iostream>
using namespace std;

struct A
{
public:  
	int _a;

	void fun()
	{
		cout << "struct A fun()" << endl;
	}
};

class B
{
private: 
	int _a;

	void fun()
	{
		cout << "class B fun()" << endl;
	}

	void fun2();
};

void fun2()
{
	cout << "fun2()" << endl;
}

void B::fun2()
{
	cout << "B::fun2()" << endl;
}

void test()
{
	//���ʵ����������һ�������͵ı����Ĺ���
	// ������ ����  ---> �Զ������͵ı���һ��ϰ�߳�Ϊ����
	A a;
	B b;
	//struct����ĳ�ԱĬ�Ϸ���Ȩ��Ϊpublic
	a._a = 1;
	a.fun();

	//class ����ĳ�ԱĬ�Ϸ���Ȩ��Ϊprivate
	//b._a = 1;
	//b.fun();
}

class C
{
	int _c;
};
class D
{
	int _c;
	void fun1()
	{
		int a = 1;
		float b = 2.0;
		char c = 'a';
	}
};

class E
{
	void fun1()
	{
		int a = 1;
		float b = 2.0;
		char c = 'a';
	}
};

class F
{};

void test2()
{
	cout << sizeof(C) << " " << sizeof(D) << " " << sizeof(E) << " " << sizeof(F) << endl;
	F f;
}

//��Ĵ�СҲ��ѭ�ڴ����Ĺ���
class G
{
	char _c;   //1
	double _d; // 16
	int _a;  // 20
	char _c2;  //21
	//24
	//Ƕ���౾����ѭ�ڴ�����ԭ�򣬼����С�� H: 24
	class H
	{
		double _d;  //8
		char _c; //9
		int _a; //16
		char _c1; //17
		//24
	};
	H _h;
};
//sizeof(G):  

void test3()
{
	cout << sizeof(G) << endl;
}

struct I
{
	char _c;   //1
	double _d; // 16
	int _a;  // 20
	char _c2;  //21
};

void test4()
{
	I oi;
	cout << (char*)&oi._c2 - (char*)&oi << endl;
}

int main() {
	//test();
	test4();
	return 0;
}
