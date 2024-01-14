/*
	algorithm library
	- 컨테이너의 반복자를 사용하여 여러 작업을 쉽게 수행하게 도와주는 라이브러리
*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <random>
using namespace std;

random_device rd;
mt19937_64 mt(rd());

int main()
{
	vector<int> container;

	for (int i = 0; i < 10; i++)
		container.push_back(i);

	//list 사용 시 error
	/*shuffle(container.begin(), container.end(), mt);

	for (auto iter = container.begin(); iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;*/

	//범위 안의 최소값 탐색
	auto iter = min_element(container.begin(), container.end());
	cout << *iter << endl;

	//범위 안의 최대값 탐색
	iter = max_element(container.begin(), container.end());
	cout << *iter << endl;

	//원하는 원소 탐색
	//ctrl + F와 유사
	iter = find(container.begin(), container.end(), 7);
	cout << *iter << endl;

	//퀵정렬
	//list는 내부적으로 정렬기능을 지원하여 포함되어있지 않음
	sort(container.begin(), container.end());
	//container.sort();		//list 내부에 있는 sort()
	for (auto iter = container.begin(); iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}