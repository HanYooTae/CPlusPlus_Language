/*
	�̸� ���� (namespace)
	- ���ǵ� ��ü�� ���� �Ҽ��� �����ִ� ��
	- std::cout, std::cin ���⼭ std�� cout, cin�� �̸� ����
	- ��ü�� �̸��� ���Ƶ� �̸������� �ٸ��� �ٸ� ��ü�� �ν��Ѵ�.
	- ������ �Լ��� �̸��� ��ġ�� ��츦 �ذ��� �� �ִ�.


	����

	namespace ���� �̸�
	{
		���
	}


	���ٹ�

	�����̸�::���

	ex) namespace a
	{
		int b;
	}

	a::b = 10;
	- �̸� ���� a�� �ִ� ���� b�� �����Ͽ� 10�� ����
*/

#include <iostream>

namespace my_namespace_1
{
	int a;	//my_namespace_1::a

	void do_something(){}	//my_namespace_1::do_somthing()

	namespace DIDI
	{
		namespace TITI
		{
			namespace RURU
			{
				int c;	//my_namespace_1::DIDI::TITI::RURU::c;
			}
		}
	}
}

namespace my_namespace_1	//�з��ؼ� ����ص� ���� �̸������� ����.
{
	int hello;	//my_namespace::hello
}

//C++17���� ����
//namespace my_namespace_1::DIDI::TITI
//{
//	int test;
//}

namespace my_namespace_2
{
	int a;
	void do_something(){}
}


int main()
{
	/*
		using namespace �̸�����
		- �ش� �̸� ������ ������ ���� ������ ������� �ʰ� ������ �����ϴ�.
	*/
	using namespace my_namespace_1;
	using namespace std;	//������ ����ϸ� ������ �߻��� ���� ����. �� ���������� ���
	
	//a;	//error, ����Ǿ� ���� ����

	// �̸������� �޶� ���� �̸��� ���� ��밡�� -> �ߺ��� ���� �� �ִ�.
	my_namespace_1::a = 5;
	my_namespace_2::a = 10;

	my_namespace_1::DIDI::TITI::RURU::c;

	std::cout << 10 << std::endl;
	// ����� ������ �̸� ������ ���� ������ -> using namespace ���
	cout << 10 << endl;

	{
		using namespace my_namespace_1;
		using namespace my_namespace_2;
		//a = 10; ambigous : ��ȣ��

		my_namespace_2::a = 20;

		hello;
	}

	{
		using namespace my_namespace_2;
		
		my_namespace_1::a = 20;
		a = 110;
	}

	

	return 0;
}