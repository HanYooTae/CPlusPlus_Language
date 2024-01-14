#include <iostream>
#include <array>

using namespace std;

int main()
{
	//int arr1[] = {1, 2, 3, 4, 5};//copy �ʱ�ȭ		//ok
	//int arr2[]{1, 2, 3, 4, 5};	//uniform �ʱ�ȭ		//ok
	////int arr[](1, 2, 3, 4, 5);	//direct �ʱ�ȭ		//error
	//int test(1);

	////Uniform Initialization�� ��ü���� �� �߿��ϰ� �ۿ��ϱ� ����
	//int test1 = 1.2;			//��Һ�ȯ
	////int test2{ 1.2 };			//error
	//int test3(1.2);				//��Һ�ȯ

	//cout << test << endl;
	//cout << test1 << endl;
	////cout << test2 << endl;
	//cout << test3 << endl;

	/*
		STL : Standard Template Libraries
		-> �����͸� �ս��� ����ϵ��� ���� ���̺귯��
	*/

	array<int, 5> arr4;							//int�� 5���� �޸� ����
	array<int, 5> arr5{1, 2, 3, 4, 5};			//�ʱ�ȭ�� ����



	// []�� ����ó���� ���� �ʱ� ������ �������� ���輺�� ����
	// at()�� ���� ó���� �ϱ� ������ []���� ���������� ������.
	// �׳� ������ ����� �ʰ� []�� ����ϴ� ���� ����
	cout << arr5[0] << endl;
	cout << arr5[1] << endl;
	cout << arr5.at(0) << endl;
	cout << arr5.at(1) << endl;
	cout << arr5.at(5) << endl;		// ��Ÿ�� �� ���� �߻�
	cout << arr5.size() << endl;

	return 0;
}

/*
	���� : STD, STL ����. ���� ��������, ���̰� ��������
*/