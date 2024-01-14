#include <iostream>
#include <string>

using namespace std;

struct person
{
	person(int b)		//����ü�ȿ� ������ �Լ����� ����ü��� ���ƾ� ��
	{
		cout << "person�� ������!" << endl;
		this->b = b;
	};

	int b;
};

int main()
{
	int* ptr1 = new int(100);	//���� �Ҵ�
	delete ptr1;			//���� ����
	cout << ptr1 << endl;	// *ptr1�� ���� 100
	//cout << *ptr1 << endl;	// *ptr1�� ���� ������� ������ *ptr1�� ����� �ȵ�. ������ ptr1(�ּҰ�)�� ��������.
	ptr1 = nullptr;
	cout << ptr1 << endl;	// ��������� ������ �ذ����ֱ� ���Ͽ� ptr1�� �ּҰ��� �ʱ�ȭ��Ŵ.
	cout << endl;
	int* pt1 = new int(10);
	cout << pt1 << endl;
	cout << *pt1 << endl;

	delete pt1;
	pt1 = nullptr;
	cout << pt1 << endl;

	cout << endl;

	//���̷�Ʈ �ʱ�ȭ�� �����ΰ�?
	int* ptr2 = new int(7);	//���̷�Ʈ �ʱ�ȭ�� �ʱ�ȭ ����
	cout << ptr2 << endl;
	delete ptr2;
	cout << ptr2 << endl;
	ptr2 = nullptr;
	cout << ptr2 << endl;
	cout << endl;

	int* ptr3 = new int{ 7 };
	delete ptr3;
	ptr3 = nullptr;
	cout << ptr3 << endl;

	cout << endl;
	//������� �ٽ� ����
	//new�� �Ҵ� ���� �� nullptr�� �������� �ʱ� ������ C���� �ϴ� ������� ����ó���� ���� �ʴ´�.
	//-> std::nothrow�� ����� ��� �Ҵ� ���� �� nullptr�� ���Ϲ޴´�.		//try catch��� ����ó���ϴ� ���
	int* ptr4 = new/*(std::nothrow)*/ int(7);

	int* ptr5 = new(std::nothrow) int(7);

	if (ptr4 == nullptr)
		std::cout << "Error";

	if (ptr4 != nullptr)
	{
		delete ptr4;
		ptr4 = nullptr;
	}

	cout << "test : " << endl;
	int* test1 = new(nothrow) int(7);
	
	cout << test1 << endl;
	if (test1 == nullptr)
		cout << "Error!" << endl;

	if (test1 != nullptr)
	{
		delete test1;
		test1 = nullptr;
	}

	cout << test1 << endl;

	cout << "test over" << endl;

	//�迭 ���� ����
	int* arr = new int[10]{ 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;

	delete[] arr;	//�迭 �����͸� ���� �� []�� �߰��ؾ��Ѵ�.
	arr = nullptr;

	for (int i = 0; i < 5; i++)
	{
		cout << &arr[i] << ", ";
	}
	cout << endl;
	cout << endl;

	//������ �迭�� ������ �����ͷ� ���� �� �ִ�.
	int** ptr_arr = new int* [5];
	
	ptr_arr[0] = new int[10];
	ptr_arr[1] = new int[10];
	ptr_arr[2] = new int[10];
	ptr_arr[3] = new int[10];
	ptr_arr[4] = new int[10];

	for (int i = 0; i < 5; i++)
		cout << ptr_arr[i] << ", ";
	cout << endl;

	for (int i = 0; i < 5; i++) {
		delete[] ptr_arr[i];
		//ptr_arr[i] = nullptr;		//�� nullptr�� �ʱ�ȭ�������� �ʾҴ��� �����ϱ�
		cout << ptr_arr[i] << ", ";
	}
	cout << endl;

	delete[] ptr_arr;
	cout << ptr_arr << ", ";
	cout << endl;

	for (int i = 0; i < 5; i++) {
	}
		ptr_arr = nullptr;
		cout << ptr_arr << ", ";
	cout << endl;

	person avc(10);

	return 0;
}

// ���� new�� malloc���� ��� ����ϴ��� ����
//https://flower0.tistory.com/500, calloc�� realloc�� ã�ƺ���

/*
	new
	- ���� �ڷ����� �˰� �ִ� ����. �׷��� ������ �ش� �������� �����ڸ� ȣ�����ش�. ex) int* ptr = new int(100);
	- delete�� ���� �� ����� ��ü�� �˱� ������ �ش� ��ü�� �Ҹ��ڸ� ȣ������ �� �ִ�. ex) delete ptr;

	malloc
	- ��ȯ ���� void*�̱� ������ ���ϴ� ���·� ĳ��������� ��.
	- ����� ���� ���ϰ� �־��� byteũ���� ������ ������༭ �°� ĳ�����ؼ� ����� void*���·� ��������.
	
*/


//struct Test
//{
//   int a;
//   int b;
//   std::string str;
//};
//
//int main()
//{
//   Test* test = new Test;
//
//   test->a = 10;
//   test->b = 20;
//   test->str = "Hello!!";
//
//   std::cout << test->a << std::endl;
//   std::cout << test->b << std::endl;
//   std::cout << test->str << std::endl;
//   // ���� malloc�� ����� ���� Test���� �Ҵ��ϰ�, ���� �ڵ� ������ϰ� �������̳� ���輺 ã�ƺ���
//   return 0;
//}