#pragma once
#include<unordered_map>
#include<vector>
#include<list>
#include<memory>

using namespace std;

class BaseSolution
{
public:
	BaseSolution();
	virtual ~BaseSolution();

	virtual void exec() = 0;
private:
	void initData();

protected:
	vector<int> num;
	int val;
};

/*
#brief 内存安全且线程安全的单例模式

单例模式相关知识
内存篇：
	1、 问：为什么单例结束时，不会走到析构函数 / 能否在析构函数中释放静态成员变量
	    答：单例对象具静态生命周期，这意味着它们在程序的整个运行期间都存在。
	       当程序结束时，操作系统会回收整个进程的内存空间，而不一定会通过调用对象的析构函数来释放资源。
		   因此，不能在析构中释放静态成员变量

	2、 问：如何保证单例不会产生内存泄露 / 单例对象该如何管理
		答：两种方式
			a) 在单例的构造函数中，使用局部静态变量，并使用智能指针，该方式在c11后线程安全 
			b) 使用静态成员变量，

线程篇：
	3、 问：如何定义一个线程的安全的单例模式

	4、 问：为什么C11后，局部静态变量是线程安全的
*/
class RegisterFactory
{
public:
	static shared_ptr<RegisterFactory> getInstance();
	void registerSol(int nId, BaseSolution* sol);
	void clearSol();
	list<BaseSolution*> getSols();
private:
	RegisterFactory() {};
	~RegisterFactory() {};
private:
	unordered_map<int, BaseSolution*> m_hashId2Sol;
};

#define REGISTER_SOL(className,nId)\
class className##Register\
{\
public:\
	className##Register()\
	{\
		RegisterFactory::getInstance()->clearSol();\
		RegisterFactory::getInstance()->registerSol(nId, new className());\
	}\
};\
static className##Register s_##className##Register;