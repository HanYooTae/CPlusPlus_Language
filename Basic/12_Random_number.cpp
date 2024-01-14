#include <iostream>

using namespace std;

//c 난수
/*
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
*/

//C++ 난수
#include <random>

int main()
{
	/*
		c style 난수의 문제점
		- 시드값을 현재 시간으로 하기 때문에 같은 시간 대의
		  프로그램들은 같은 시드값을 가진다.
		- %로 범위를 제한하기 때문에 균등한 난수를 생성하지 않는다.
		- rand() 자체의 난수 알고리즘이 좋지 않다.

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
		random_device rd;			//시드값을 얻기 위해서 사용
		//난수를 생성해주는 엔진
		mt19937_64 merssenne(rd());	//rd()로 시드값을 넣어준다.		//merssenne은 정해진 변수가 아님. 아무거나 넣어주고 싶은걸로 넣어줄 수 있음

		//동일한 확률로 1 ~ 6이 나오게 정의
		uniform_int_distribution<> dice(1, 6);	//int말고 다른 자료형도 사용이 가능하다

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