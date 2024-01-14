#include <iostream>
using namespace std;

#define ����1

#ifdef ����1

int main()
{
	/*
   ���� :
   2������, bool��� ����, ��Ʈ����
   1.
   int a = 123;

	  a= 2345;
	  ....

	  a = 0;
	  a = a ? a -> ?�� ���� �����ڰ� ���� �� �ڵ庸�� ������ �ɱ�?
*/

	//a�� 0���� �ٲٱ�
	int a1 = 12345;
	a1 = a1 ^ a1;
	cout << a1 << endl;
	cout << endl;
	

/*
   2.
   int a = 123;
   int b = 456;

   a = a ? b
   b = a ? b
   a = a ? b

   temp�� ������� �ʰ� �ٲٴ¹� ã��
*/

	int a = 1;		//01
	int b = 2;		//10

	//^������(XOR) : �� ��Ʈ�� �ٸ��� 1, ������ 0
	a = a ^ b;		//11
	b = a ^ b;		//01
	a = a ^ b;		//10

	cout << a << endl;
	cout << b << endl;
	cout << endl << endl;
	//a = (a + b) - (b = a);


/*
   3.
	  ¦��/Ȧ�� �Ǻ� -> %������� �ʰ�
*/
	int c = 1;
	int d = 2;

	int c1 = c & 1;
	int d1 = d & 1;

	if (c1 == 1)
		cout << "Ȧ��" << endl;
	else if (c1 == 0)
		cout << "¦��" << endl;

	if (d1 == 1)
		cout << "Ȧ��" << endl;
	else if (d1 == 0)
		cout << "¦��" << endl;



	/*
	   4.
		  ����/��� �Ǻ� -> ���迬���� ��� x
	*/
	cout << endl;

	int y = 1;
	y >>= 31;

	int z = -1;
	z >>= 31;

	if (y == 0)
		cout << "���" << endl;
	else if (y == -1)
		cout << "����" << endl;

	if (z == 0)
		cout << "���" << endl;
	else if (z == -1)
		cout << "����" << endl;

	/*
	   5.
		  2�� �¼����� �ƴ��� �Ǻ� -> �ݺ��� ������� �ʰ�
		  ���� �ι��� �ϸ� �� �� ����
	*/

	int e = 4;

	if ((e & (e - 1)) == 0)
		cout << "2�� �¼��� �½��ϴ�." << endl;

	else
		cout << "2�� �¼��� �ƴմϴ�." << endl;

	/*
	   6.
		  �빮��/�ҹ��� ��ȯ -> +, - �Ⱦ���
		  �ƽ�Ű �ڵ��� ��ҹ��ڴ� ������° ��Ʈ�� ��� 0�̰�
		  �ҹ��ڴ� ��� 1 �̴�.
	*/

	string str = "ABC";

	for (char& ch : str)
	{
		if ('A' <= ch && 'Z' >= ch)
		{
			ch |= 32;
		}
		cout << ch << endl;
	}
	cout << str << endl;

	return 0;
}

#endif // ����1

// ���� 2
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

template<>
class Storage8<bool>
{
public:
	Storage8(const char& input) {}

	void Set(int index, const bool& value)
	{
		arr[index] = value;
	}

	const bool& Get(int index) { return arr[index]; }

private:
	bool arr[8];
};