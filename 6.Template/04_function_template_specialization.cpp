/*
	function template specialization - �Լ� ���ø� Ư��ȭ
	- Ư�� �ڷ����� ���ؼ� �ٸ� ����� �����ϰ� ���� �� ���
	- Ư�� �ڷ����� ���� ����ó���� ����
*/

#include <iostream>
using namespace std;

template<typename T>
T GetMax(T x, T y)
{
	return (x > y) ? x : y;
}


//template specialization
//Ư��ȭ�� Ÿ�Կ� ���ؼ� �ٸ� ������ ������
template<>
char GetMax(char x, char y)
{
	cout << "warning : comparing chars" << endl;
	return (x > y) ? x : y;
}

template<class T>
class Storage
{
public:
	Storage(T value)
		:value(value)
	{

	}

	void Print()
	{
		cout << value << endl;
	}

private:
	T value;
};

//��� �Լ� Ư��ȭ
template<>
void Storage<double>::Print()
{
	cout << scientific << value << endl;
}

int main()
{
	cout << GetMax<int>(1, 2) << endl;
	cout << GetMax<float>(2.0f, 4.0f) << endl;
	cout << GetMax('a', 'b') << endl;
	
	cout << endl;

	Storage<int> s1(5);
	s1.Print();

	Storage<double> s2(5.2);
	s2.Print();

	return 0;
}