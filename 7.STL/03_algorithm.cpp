/*
	algorithm library
	- �����̳��� �ݺ��ڸ� ����Ͽ� ���� �۾��� ���� �����ϰ� �����ִ� ���̺귯��
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

	//list ��� �� error
	/*shuffle(container.begin(), container.end(), mt);

	for (auto iter = container.begin(); iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;*/

	//���� ���� �ּҰ� Ž��
	auto iter = min_element(container.begin(), container.end());
	cout << *iter << endl;

	//���� ���� �ִ밪 Ž��
	iter = max_element(container.begin(), container.end());
	cout << *iter << endl;

	//���ϴ� ���� Ž��
	//ctrl + F�� ����
	iter = find(container.begin(), container.end(), 7);
	cout << *iter << endl;

	//������
	//list�� ���������� ���ı���� �����Ͽ� ���ԵǾ����� ����
	sort(container.begin(), container.end());
	//container.sort();		//list ���ο� �ִ� sort()
	for (auto iter = container.begin(); iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}