#include <iostream>
using namespace std;

//����� Ŭ������� �Ҹ��ڿ��� virtual��
//������� ���� Ŭ������� final ���̱�
class Base
{
public:
	//1. �� ĳ���� �� �Ļ� Ŭ������ �Ҹ��ڰ� ȣ�� �ȵ�
	//~Base() { cout << "~Base()" << endl; }
	
	//2. virtual Ű���带 ����Ͽ� �� ��ü�� �´� �Ҹ��ڰ� ȣ��ǵ��� ��
	virtual ~Base() { cout << "~Base()" << endl; }		//������尡 �Ǳ� ������ best ���
};

class Derived : public Base
{
public:
	~Derived() 
	{
		cout << "~Derived()" << endl;
		//arr��� ���� ����
	}

private:
	int* arr = nullptr;		//���� �Ҵ���� ����� Ư���� ��찡 �ƴϸ� �Ҹ��ڿ��� ������
};

int main()
{
	{
		Derived b;
	}

	cout << "1###############" << endl;

	//���� Ŭ������ �� ĳ������ ���¿��� �Ļ� Ŭ������ ������ ��
	//�Ҹ��ڸ� ���� �Լ��� �������� ������ �Ļ� Ŭ������ �Ҹ��ڰ� ȣ��ȵǴ� ������ �߻�
	//-> �Ļ� Ŭ�������� �Ҹ��ڿ��� �߿��� �۾��� ���شٸ� �ش� �۾��� ������� �ʰ� ���õȴ�.
	//���� ����ϴ� �θ� Ŭ������ �Ҹ��ڴ� virtual�� ���̵��� ����		-> virtual�� ���̸� �ణ�� �޸𸮰� �þ�� ��
	{
		Base* base = new Derived;

		delete base;
	}

	return 0;
}