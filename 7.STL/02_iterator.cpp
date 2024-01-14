/*
	iterator - 반복자
	- 컨테이너의 원소에 접근할 수 있는 포인터와 같은 객체
	- 포인터와 같이 원소에 접근하므로 반복자를 사용하여
	  컨테이너와 저장된 데이터의 타입에 상관없이 알고리즘을 사용할 수 있게 해준다.
	- 접근하는 방식이 쉬움. (vector든 list든 바꿔주기만 하면 사용 가능)
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
//stack과 queue는 반복자가 없다
using namespace std;



int main()
{
	//1. vector
	{
		vector<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);

		std::vector<int>::iterator iter;		//iterator 선언
		iter = container.begin();				//begin() : 컨테이너의 첫 번째 원소를 가리킬 반복자 반환

		/*
			//std::vector<int>::iterator iter;		//iterator 선언
			auto iter = container.begin();				//begine() : 컨테이너의 첫 번째 원소를 가리킬 반복자 반환
		*/
		

		while (iter != container.end())		//end() : 컨테이너 마지막 원소 뒤의 위치를 가리키는 반복자 반환
		{
			cout << *iter << " ";
			++iter;
		}
		cout << endl;

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";
		cout << endl;
	}

	//2.list
	//반복자를 통해 전근 방법을 일반화하여 다른 컨테이너와 동작이 비슷하다.
	//-> 수정이 적다.
	{
		list<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";
		cout << endl;
	}

	//3.set
	{
		set<int> container;
		for (int i = 0; i < 10; i++)
			container.insert(i);

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";
		cout << endl;
	}

	//4. map
	{
		map<int, char> container;
		for (int i = 0; i < 10; i++)
			container.insert(make_pair(i, i + 32));

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << iter->first << ", " << iter->second << " ";
		cout << endl;
	}

	return 0;
}