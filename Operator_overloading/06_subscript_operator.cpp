//���� ������
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class IntArray
{
public:
	//1.
	int Get(int index) { return arr[index]; }
	void Set(int index, int value) { arr[index] = value; }

	//2.
	int* GetArr() { return arr; }

	//3. 2���� ������ ���
	//���ٰ� �ϱ⿡�� �ָ���
	//[]�� �ݺ������� ȣ��� ��Ȳ�� ������, if���̱� ������ ��������.
	int& operator[](int index)
	{
		//if (index >= 10)
		//{
		//
		//}

		//4. ����� �ÿ��� üũ�ϱ� ������ ��������� ����
		assert(index >= 0);
		assert(index < 10);

		return arr[index];
	}

	const int& operator[](int index) const
	{

	}

private:
	int arr[10];
};

int main()
{
	IntArray arr;
	//1. �����ε��� ������ �� ó�� ���(���ŷο�)
	/*arr.Set(0, 1);
	arr.Set(1, 2);
	arr.Set(2, 3);

	arr.Get(0);
	arr.Get(1);*/

	//2. �迭�� ��ȯ�޾� ���
	//ũ�⿡ ���� ������ �� �� ���� -> �������� ����
	auto p_arr = arr.GetArr();

	p_arr[0] = 10;
	p_arr[1] = 10;

	//3. [] �����ε�
	arr[0] = 1;
	arr[2] = 2;
	arr[3] = 3;

	IntArray* arr2 = new IntArray;

	//arr2[0] = 10;		//������ ���¿� []�� ���̸� error
	(*arr2)[0] = 10;

	vector<int> vecs;
	
	//4.ó�� ó������
	vecs[0];
	vecs[1];

	//3.ó�� ó������
	vecs.at(0);
	vecs.at(1);

	//�ӵ��鿡�� ��밡���� ���
	int* arr5 = vecs.data();		//0�� �Լ��� ���� �ּҸ� ��ȯ
	arr5++;

	return 0;
}