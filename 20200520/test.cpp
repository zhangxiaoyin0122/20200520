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
	//类的实例化：创建一个类类型的变量的过程
	// 变量： 对象  ---> 自定义类型的变量一般习惯称为对象
	A a;
	B b;
	//struct定义的成员默认访问权限为public
	a._a = 1;
	a.fun();

	//class 定义的成员默认访问权限为private
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

//类的大小也遵循内存对齐的规则
class G
{
	char _c;   //1
	double _d; // 16
	int _a;  // 20
	char _c2;  //21
	//24
	//嵌套类本身遵循内存对齐的原则，计算大小： H: 24
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
