//https://boycoding.tistory.com/169
// 10_static_member_variable.cpp

/*
	static member vairable
	- Ŭ���� ���ο� �ϳ��� �����ϴ�, ũ������ ��� ��ü�� �����ϴ� ����
	- ������ Ŭ��������, �ʱ�ȭ�� �ҽ�����(.cpp, .c)���� ���־�� �Ѵ�.(�߿�!)
*/

#include<iostream>
using namespace std;

class Test
{
public:
	// �������� �Ǵµ� ��ü�� ���⿡ ��ũ x -> ���Ǻ� �����ؾ� ��.
	void Add();

	int value = 1;

	//static int count = 10; // error
	// �� �ȿ� �ִ� static�� ���α׷� ���۰� ���ÿ� �޸𸮰� �����Ǿ�� �Ѵ�.
	// �׷��� class ����� ���� -> ���⼭�� ���� ���� �ǰ� �ʱ�ȭ�� ���� ����
	// -> �� �޸𸮿� �ö� �� ����.
	static int count;

	// const�� ������ ����� ���ÿ� �ʱ�ȭ �Ǳ� ������ �����ϴ�.
	static const int test = 10;

private:
};

// define int cpp -> ��� ���Ͽ��� �ʱ�ȭ�� ��� error�� �߻��� Ȯ���� ����. -> ���� �ҽ����Ͽ��� �ߺ� ���ǰ� �� �� ����
int Test::count = 10;

int main()
{
	// �ν��Ͻ��� ������ �ʾƵ� �����ϹǷ� ���� ����� ����
	cout << &Test::count << ", " << Test::count << endl;

	Test t1, t2;
	
	t1.value = 10;
	t2.value = 20;

	cout << "value" << endl;
	cout << & t1.value << ", " << t1.value << endl;
	cout << &t2.value << ", " << t2.value << endl;

	t1.count = 30;
	t2.count = 40;

	cout << "count" << endl;
	cout << &t1.count << ", " << t1.count << endl;
	cout << &t2.count << ", " << t2.count << endl;

	t1.Add();		//LNK���� -> ��ũ����

	return 0;
}

/*
	���� : �̱��� ���� �����ϱ�
*/

void Test::Add()
{
	//cout << "test" << endl;
}
