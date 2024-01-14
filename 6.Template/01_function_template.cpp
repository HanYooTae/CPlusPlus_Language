/*
	Template
	- ���α׷��Ӱ� ���ϴ� Ÿ���� �־��ָ� �˸°� �ڵ带 ���ִ� Ʋ
	- int�� double���� ��ü���� �ڷ����� ������ �� �ִ� �Ϲ���(generic type)���� �����Ѵ�.
	- � ���������� ���ø� �Ű������� �����ϸ�, �����Ϸ��� �� ���������� �´� �ڵ带 �������ش�.
	- ��ü���� �������� ��� �Ϲ������� ���α׷����ϴµ�, �̰��� �Ϲ�ȭ ���α׷����̶�� �θ���.
	- �پ��� �ڷ����� ������ �˰����� �����ؾ� �Ѵٸ�, ���ø��� ����Ѵ�.
		-> �Ϻ� �ڷ����� ���ؼ��� ������ �ٸ��ٸ� Ư��ȭ�� ����� ����ó���� ���ش�.
*/

#include <iostream>
using namespace std;

//�����ε����� �پ��� Ÿ�Կ� ���� ó���� ���������� ���ο� Ÿ���� �ʿ��� ������ �߰��ؾ� ��
//-> ���ŷӰ� �ڵ� ��ü�� �������� ���� ���, ��� ��������� �Ѵ�.
//int GetMax(int x, int y) { return (x > y) ? x : y; }
//float GetMax(float x, float y) { return (x > y) ? x : y; }
//short GetMax(short x, short y) { return (x > y) ? x : y; }
//long GetMax(long x, long y) { return (x > y) ? x : y; }
//double GetMax(double x, double y) { return (x > y) ? x : y; }

template<typename T, typename T2>		//���ø� �Ű����� T����, �ڵ带 �ۼ��� �� ����� �ڷ��� Ÿ��            
//template<class T>			//class��� �� ���� ������, ���������� ó���� ���༭ ���̴� ����.
T GetMax(T x, T2 y)			//T�� �ϳ��� �ڷ���ó�� �����Ͽ� ���
{
	return (x > y) ? x : y;
}

//int GetMax(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//
//double GetMax(double x, double y)
//{
//	return (x > y) ? x : y;
//}

class Won
{
public:
	Won(int value = 0) :value(value) {}

	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

	bool operator > (const Won& rhs)
	{
		return value > rhs.value;
	}

private:
	int value = 0;
};

int main()
{
	//<>�� ����� ���ø� ���ڸ� �־��� �� �ִ�.
	cout << GetMax<int>(1, 2u) << endl;

	//���ø��� �Ű����� Ÿ���� ���缭 �־��ָ� <> ���� ����
	cout << GetMax(1l, 2l) << endl;
	cout << GetMax(1ll, 2ll) << endl;
	cout << GetMax(1llu, 2llu) << endl;
	cout << GetMax(1.0f, 2.0f) << endl;

	//�츮�� ���� �Լ� ���ø��� �� ���� ���ڸ� ���� �ڷ������� �ް� �ִ�.
	//-> �־��ִ� �� ������ Ÿ���� �޶� T�� � �ڷ������� �����ؾ� ���� ���� �����ȵ�.
	//typename�� �߰��Ͽ� ����ȭ
	GetMax(1.0f, 2.0);

	//����ڰ� ������ �ڷ����� ��� ����
	cout << GetMax(Won(6), Won(2)) << endl;

	return 0;
}