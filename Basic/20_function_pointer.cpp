#include <iostream>
#include <functional>		//�Լ� �����͸� ���� �� �� �ְ� ���ִ� ���̺귯��
using namespace std;

bool func(const int& x)
{
	cout << x << endl;
	return x > 0;
}

//�Լ��� �̸� �κ��� Ÿ�� �κ��� �ȴ�.  func_ptr
typedef bool(*func_ptr)(const int&);

//���� ������
using func_type = bool(*)(const int&);

int main()
{
	//�̷��� ����ϸ� ������
	bool (*pf)(const int&) = func;

	//1.
	func_ptr f = func;

	//2.
	func_type f2 = func;

	//#include <fucntional>�� ����ؼ� ����� �� �ִ� ���
	//��ȯ���� �Ű������� �����ָ� �ȴ�.
	//���������� �ּҿ� �������� ���Ѵ�?
	function<bool(const int&)> f3 = func;
	f3(10);

	return 0;
}