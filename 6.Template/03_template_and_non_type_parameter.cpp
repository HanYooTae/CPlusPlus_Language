#include <iostream>
#include <array>
using namespace std;

/*
	non - type parameter
	- �ڷ����� �ƴ� ���ø� �Ű�����
	- ���ø� �Ű����� ���� �ڷ����� �ƴ� ���� �־��ش�.
*/

template<typename T/*type*/, unsigned int SIZE/*value*/>
class MyArray
{
public:
	MyArray()
	{

	}

	~MyArray()
	{

	}

private:
	T arr[10];		//���� �Ҵ�(�̹� �������ִ� ��, ������ ������ Ȯ�ΰ����� ���� ����)
	T arr2[SIZE];	//���ø� ��üȭ����(������ Ÿ��)�� ���� ��
};

int main()
{
	MyArray<int, 10> arr1;
	MyArray<float, 20> arr2;

	array<int, 10> stl_arr;

	return 0;
}