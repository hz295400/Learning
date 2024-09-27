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
#brief �ڴ氲ȫ���̰߳�ȫ�ĵ���ģʽ

����ģʽ���֪ʶ
�ڴ�ƪ��
	1�� �ʣ�Ϊʲô��������ʱ�������ߵ��������� / �ܷ��������������ͷž�̬��Ա����
	    �𣺵�������߾�̬�������ڣ�����ζ�������ڳ�������������ڼ䶼���ڡ�
	       ���������ʱ������ϵͳ������������̵��ڴ�ռ䣬����һ����ͨ�����ö���������������ͷ���Դ��
		   ��ˣ��������������ͷž�̬��Ա����

	2�� �ʣ���α�֤������������ڴ�й¶ / �����������ι���
		�����ַ�ʽ
			a) �ڵ����Ĺ��캯���У�ʹ�þֲ���̬��������ʹ������ָ�룬�÷�ʽ��c11���̰߳�ȫ 
			b) ʹ�þ�̬��Ա������

�߳�ƪ��
	3�� �ʣ���ζ���һ���̵߳İ�ȫ�ĵ���ģʽ

	4�� �ʣ�ΪʲôC11�󣬾ֲ���̬�������̰߳�ȫ��
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