//https://openmynotepad.tistory.com/15

// range based for������ �纻�� ������ ���� �� �ּҰ� ��� �Ȱ����ɱ�?


//2�� ���� 32:20
#include <iostream>
#include <vector>

using namespace std;

struct array5
{
	int* begin()
	{
		return arr;		//�迭�� �������� �迭�� �̸�
	}

	int* end()
	{
		return &arr[4] + 1;
	}

	int arr[5] = { 1, 2, 3, 4, 5 };
};

struct test
{
	int* begin()
	{
		return arr;
	}

	int* end()
	{
		return &arr[0] + 1;
	}

	int arr[5] = { 1, 2, 3, 4, 5};
};

int main()
{
	int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	for (int i = 0; i < sizeof(fibonacci) / sizeof(fibonacci[0]); i++)
		cout << fibonacci[i] << ' ';
	cout << endl;
	cout << endl;
	cout << "test" << endl;
	cout << *fibonacci << endl;				// == fibonacci[0]
	cout << fibonacci << endl;				// �迭�� �� ��ü�� �������̱� ������ �ڱ��ڽ��� �ּҸ� �������.
	cout << &fibonacci << endl;				// �׷��� ������ fibonacci == &fibonacci
	cout << sizeof(fibonacci) << endl;		// �迭�� ���ڰ� 12���̱� ������, integer�� �� 4����Ʈ*12 = 48
	cout << sizeof(fibonacci[0]) << endl;	// ù ��° �迭 ����� ũ��� integer���̱� ������ 4����Ʈ
	cout << endl;

	/*
		���ӵ� �����͸� ������ �����ϴ� ��
		�ڷ����̳� auto�� ����
		&�� ���̸� ���� ���� ������
	*/

	//�纻 �������� ���Ҹ� �޴´�.
	cout << "�纻" << endl;
	for (int number : fibonacci)
		//cout << number << ' ';
		cout << &number << ' ';
	cout << endl;
	cout << endl;
	cout << endl;
	
	//������ �״�� �����´�
	//������ �������� ���̱� ������ const�� �ٿ��ִ� ���� ������
	cout << "���� ��" << endl;
	for (const int& number : fibonacci)
		//number = 0;			//������ �״�� �������� ���̴� number�� R-value�� �־��ָ� ���� ���� ���Ѵ�.
		number;
	for (int& number : fibonacci)
		cout << number << ' ';
		cout << endl;
		cout << endl;

	cout << "���̴� ��" << endl;
	//�ּҰ��� �ٲ�� ���� �ƴ� ���̴� ���� 0���� �ٲ�
	for (int number : fibonacci) {
		number = 0;
		cout << number << ' ';	
	}
	cout << endl;
	cout << endl;

	for (int number : fibonacci) {
		number = 0;
		cout << &number << ' ';
	}
	cout << endl;
	cout << endl;
	cout << "check" << endl;
	for (const auto& number : fibonacci)
		cout << number << ' ';
	cout << endl;

	for (const auto& number : {0, 1, 2, 3, 4, 5, 6})
		cout << number << ' ';
	cout << endl;
	
	//���ڿ� �迭�� �ּҰ��� ����ϸ� �̻��� ���� ���´�. ��????
	/*for (const auto& number : { 'a', 'b', 'c', 'd'})
		cout << &number << ' ';
	cout << endl;*/


	//struct array5
	//{
	//	int* begin()
	//	{
	//		return arr;		//�迭�� �������� �迭�� �̸�
	//	}

	//	int* end()
	//	{
	//		return &arr[4] + 1;
	//	}

	//	int arr[5] = { 1, 2, 3, 4, 5 };
	//};


	//����ڰ� ������ �ڷ����� ��� begin, end�Լ��� �������ָ� ��� ����
	array5 arr;

	cout << "dd" << endl;
	for (auto& t : arr)		//�������� ������ ã�� ���ؼ� error�� ��
		cout << t << ' ';
	cout << endl;

	//array5�� ���ư��� �ִ� ���
	for (int* p = &arr.arr[0]; p != &arr.arr[4] + 1; p++)
		cout << *p << ' ';

	cout << endl;


	//���߿� �ð��Ǹ� Ȯ��
	// Create a vector object that contains 10 elements.
	vector<double> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i + 0.14159);
	}

	// Range-based for loop to iterate through the vector, observing in-place.
	for (const auto& j : v) {
		cout << j << " ";
	}
	cout << endl;
	cout << "end of vector test" << endl;

	return 0;
}