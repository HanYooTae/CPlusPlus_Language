#include <iostream>
using namespace std;

template<class T>
class A
{
public:
	A(const T& input) {}

	void DoSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void Test() {}
};

//Ŭ���� ��ü�� Ư��ȭ ����
template<>
class A<char>
{
public:
	A(const char& input) {}

	void DoSomething()
	{
		cout << "char type specialization" << endl;
	}
};

int main()
{
	A<int> a_int(10);
	A<float> a_float(10.0f);
	A<char> a_char('a');

	a_int.DoSomething();
	a_float.DoSomething();
	a_char.DoSomething();

	a_int.Test();
	a_float.Test();
	//���ø� Ŭ������ Ư��ȭ�� ���, ����� ���� �ٸ��� ������ �ִ�.
	//a_char.Test();	//error	//Ư��ȭ�� char������ Test�Լ��� ����
	
	cout << endl;

	return 0;
}

/*
   ���� : 
   2������, bool��� ����, ��Ʈ����
   1.
   int a = 123;

	  a= 2345;
	  ....

	  a = 0;
	  a = a ? a -> ?�� ���� �����ڰ� ���� �� �ڵ庸�� ������ �ɱ�?

   2.
   int a = 123;
   int b = 456;

   a = a ? b
   b = a ? b
   a = a ? b

   temp�� ������� �ʰ� �ٲٴ¹� ã��

   3.
	  ¦��/Ȧ�� �Ǻ� -> %������� �ʰ�

   4.
	  ����/��� �Ǻ� -> ���迬���� ��� x


   5.
	  2�� �¼����� �ƴ��� �Ǻ� -> �ݺ��� ������� �ʰ�
	  ���� �ι��� �ϸ� �� �� ����

   6.
	  �빮��/�ҹ��� ��ȯ -> +, - �Ⱦ���
	  �ƽ�Ű �ڵ��� ��ҹ��ڴ� ������° ��Ʈ�� ��� 0�̰�
	  �ҹ��ڴ� ��� 1 �̴�.
*/

// ���� 
/*
   �Ʒ��� Ŭ������ ���� ���ø� ���ڿ� ���� �����͸� 8�� �������ִ� Ŭ�����̴�.

   ���⼭ ������ ����µ� bool���� ���� �� ������ �����ϰ� �ȴ�.
   -> bool���� 1����Ʈ ũ�⸸���ε� 8������ ǥ���� �� ������ �Ʒ���
   ���� ������ ��� 1����Ʈ * 8�� ũ�⸦ ������.

   �Ʒ��� Ŭ������ ���ø� Ư��ȭ�� bool���Ͻ�
   1����Ʈ�� ������ 8���� �Ұ��� ó���� �� �ְ� ������

   template <class T>
class Storage8
{
public:
   void Set(int index, const T& value)
   {
	  arr[index] = value;
   }

   const T& Get(int index) { return arr[index]; }

private:
   T arr[8];
};

*/