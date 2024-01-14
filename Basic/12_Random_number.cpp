#include <iostream>

using namespace std;

//c ����
/*
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
*/

//C++ ����
#include <random>

int main()
{
	/*
		c style ������ ������
		- �õ尪�� ���� �ð����� �ϱ� ������ ���� �ð� ����
		  ���α׷����� ���� �õ尪�� ������.
		- %�� ������ �����ϱ� ������ �յ��� ������ �������� �ʴ´�.
		- rand() ��ü�� ���� �˰����� ���� �ʴ�.

		% 2(0 1 2 3 4 5 6 7 8 9 10)

		0 : 0, 2, 4, 6, 8, 10
		1 : 1, 3, 5, 7, 9

	*/
	{
		srand((unsigned int)time(NULL));

		for (int i = 0; i < 10; i++)
			printf("%d, ", rand() % 10);
		printf("\n");
	}

	//C++
	{
		random_device rd;			//�õ尪�� ��� ���ؼ� ���
		//������ �������ִ� ����
		mt19937_64 merssenne(rd());	//rd()�� �õ尪�� �־��ش�.		//merssenne�� ������ ������ �ƴ�. �ƹ��ų� �־��ְ� �����ɷ� �־��� �� ����

		//������ Ȯ���� 1 ~ 6�� ������ ����
		uniform_int_distribution<> dice(1, 6);	//int���� �ٸ� �ڷ����� ����� �����ϴ�

		cout << endl;

		for (int i = 0; i < 10; i++)
			cout << dice(merssenne) << ", ";
		cout << endl;
	}

	{
		random_device rd1;
		mt19937_64 mt(rd1());
		uniform_int_distribution<> dice1(1, 6);
		for (int i = 0; i < 10; i++)
		{
			cout << dice1(mt) << ", ";
		}cout << "\n";
	}

	{
		cout << "test : ";
		random_device a;
		mt19937_64 test(a());
		uniform_int_distribution<> find(1, 6);

		for (int i = 0; i < 5; i++)
			cout << find(a) << ", ";
		cout << endl;
	}

	return 0;
}