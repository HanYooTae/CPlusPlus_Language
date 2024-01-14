#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0) : x(x), y(y) { }

	//ostream : ��� ��Ʈ��
	//&�� �����Ͽ� ü�̴�
	friend ostream& operator <<(ostream& out, const Point& p)
	{
		out << "(" << p.x << ", " << p.y << ")";
		return out;
	}

	//istream : �Է� ��Ʈ��
	friend istream& operator >>(istream& in, Point& p)		//�޾��ִ� �����̱� ������ ��� ���� ������ �ȵ�
	{
		in >> p.x >> p.y;
		return in;
	}

private:
	int x;
	int y;
};

int main()
{
	Point p1(0, 10), p2{ 5, 5 };

	cout << p1 << ", " << p2 << endl;

	cin >> p1 >> p2;

	cout << p1 << ", " << p2 << endl;


	return 0;
}

/*
	���� : ����Լ�
		1. ����Լ� �����ϱ�
		2. ����Լ��� ����ؼ� �Ǻ���ġ ���� ����
		3. (����) ����Լ��� ����ؼ� �ϳ���ž ����

	���� : ������ �����
*/