/*
	Object Slicing - ��ü �����̽�
	- �Ļ� Ŭ������ �ν��Ͻ��� ��� Ŭ������ �ν��Ͻ��� ������ �� �߻�
	- �Ļ� Ŭ������ ���� ������ �սǵȴ�.
*/

#include <iostream>
#include <vector>
#include <functional>		//reference_wrapper

using namespace std;

class Base
{
public:
	virtual void Print() { cout << "Base" << endl; }
public:
	int i = 0;
};

class Derived1 : public Base
{
public:
	virtual void Print() { cout << "Derived1" << endl; }
public:
	int j = 1;		//object slicing��
};

class Derived2 : public Base
{
public:
	virtual void Print() { cout << "Derived2" << endl; }
public:
	int k = 1;		//object slicing��
};

int main()
{
	//1. call by reference
	Derived1 d;
	//reference -> d�� Base ���·� ������ ��
	//�޸𸮴� �״�ΰ� ũ�⸦ �۰� ���� ��
	Base& ref = d;
	ref.Print();

	//2. call by value
	//copy -> d�� Base�κи� ������ ���ο� �޸𸮸� ����
	//�Ļ� Ŭ������ ������ �κ��� �ս��� �ȴ�.
	Base base = d;	//object slicing
	base.Print();

	//3.
	// �սǾ��� vector�� �ְ� ���� ��
	Derived1 derived1;
	Derived1 derived2;
	Derived2 derived3;
	Derived2 derived4;

	//�� Ÿ���� �ܼ� base��, copy�� �Ǿ� ���谡 ������.
	// ���۷��� ���·� �־���� �Ѵ�.
	//vector<Base> my_vec;	//�ڷ� �� ©��

	// &�� ���Ϳ� �ȵ� -> ��������� reference_wrapper�� �����͸� �������

	// * ��� 
	vector<Base*> my_vec1;

	my_vec1.push_back(&derived1);
	my_vec1.push_back(&derived2);
	my_vec1.push_back(&derived3);
	my_vec1.push_back(&derived4);

	for (auto& vec : my_vec1)
		vec->Print();


	// reference_wrapper ���		//reference�� ����� �� �ֵ��� ����

	vector<reference_wrapper<Base>> my_vec2;

	my_vec2.push_back(derived1);
	my_vec2.push_back(derived2);
	my_vec2.push_back(derived3);
	my_vec2.push_back(derived4);

	for (auto& vec : my_vec2)
		vec.get().Print();

	return 0;
}

/*
   ���� : ���� ���� �����



   �ʿ��� ������

	�̻���
	{
	  ��ġ
	}

   ��
   {
	  ��
	  ��ġ
	  HP
   }

   �÷��̾�
   {
	  ��
	  ��ġ
	  HP
   }

   �ʿ��� ����
   �⺻���� ���� ����
   �̵�(�÷��̾�)
   �̵�(��)
   �̻��� �߻�
   �浹 ó��


   // ���� ����

   //����
   ���� ����

   // ������Ʈ
   �÷��̾� �Է�(�̵�, �߻�);
   �� AI(�̵�, �߻�)
   �̻��� �̵�(��, �÷��̾�)
   �浹ó��

   // ����
   �÷��̾�
   ��
   �̻���
   ��(��)
   �÷��̾� UI
   ����

   std::vector ����غ���
*/