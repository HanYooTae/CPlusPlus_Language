/*
	iterator - �ݺ���
	- �����̳��� ���ҿ� ������ �� �ִ� �����Ϳ� ���� ��ü
	- �����Ϳ� ���� ���ҿ� �����ϹǷ� �ݺ��ڸ� ����Ͽ�
	  �����̳ʿ� ����� �������� Ÿ�Կ� ������� �˰����� ����� �� �ְ� ���ش�.
	- �����ϴ� ����� ����. (vector�� list�� �ٲ��ֱ⸸ �ϸ� ��� ����)
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
//stack�� queue�� �ݺ��ڰ� ����
using namespace std;



int main()
{
	//1. vector
	{
		vector<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);

		std::vector<int>::iterator iter;		//iterator ����
		iter = container.begin();				//begin() : �����̳��� ù ��° ���Ҹ� ����ų �ݺ��� ��ȯ

		/*
			//std::vector<int>::iterator iter;		//iterator ����
			auto iter = container.begin();				//begine() : �����̳��� ù ��° ���Ҹ� ����ų �ݺ��� ��ȯ
		*/
		

		while (iter != container.end())		//end() : �����̳� ������ ���� ���� ��ġ�� ����Ű�� �ݺ��� ��ȯ
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
	//�ݺ��ڸ� ���� ���� ����� �Ϲ�ȭ�Ͽ� �ٸ� �����̳ʿ� ������ ����ϴ�.
	//-> ������ ����.
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