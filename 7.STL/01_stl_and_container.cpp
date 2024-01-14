/*
	STL - Standard Template Library
	- �����̳�, �ݺ���, �˰����� �����Ѵ�.
	- ���ø��� ����Ͽ� ��� Ÿ���� �����Ϳ��� ���� ���̺귯�� ����� ����� �� �ִ�.
		-> �ڷ����� �Ϲ�ȭ�Ͽ� �ڵ��� �������� ������ �۾��� ������ �� �ְ� ���ش�.

		�����̳�(container)
		- ���� Ÿ���� �����͸� ������ �� �ִ�.

		�ݺ���(iterator)
		- �����̳ʿ� ������ ���ҿ� ������ �� ���

		�˰���(algorithm)
		- �ݺ��ڵ��� ������ �Ϸ��� �۾��� �����Ѵ�.
*/

/*
	container - �����̳�
	- ������ Ÿ���� ���� ��ü�� �����ϴ� ����, �����
	- ���ø��� ����� �����ϴ� �������� �ڷ����� �����ϰ� �����̵� ���� �� �ְ� ��������ִ�.
	- �����̳��� ����
	
	1. sequence
		- �Ϲ����� �ڷᱸ���� ������ ����
		- �ڷḦ �Է��� ������� �����ϱ� ������ ����, �˻�, �˰��� �Ҹ���
		- ���� ���� �ڷᳪ �˻� �ӵ��� �߿����� ���� ��쿡 ���
			ex) vector, list, deque ��

	2. associative
		- ������ ��Ģ�� ���� �ڷḦ ����ȭ�Ͽ� ����
		- �ڷḦ �����Ͽ� �����ϱ� ������ �˻��� ����
		- ���� ���� �ڷᳪ �˻� �ӵ��� �߿��� ��쿡 ���
			ex) set, map, multiset, multimap ��

	3. adaptor
		- ������ �����̳ʸ� �������� ���� ť �켱���� ť ���·� ����
			ex) queue, stack ��
*/

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
using namespace std;

void Sequence_Container();		//�����Ͱ� ���������� ����Ǿ��ִ� �����̳�
void Associative_Container();
void Container_Adapter();

int main()
{
	Sequence_Container();
	//Associative_Container();
	//Container_Adapter();

	return 0;
}

/*
	Sequence Container
	- �迭ó�� �����͸� �������� �����ϴ� �����̳�
	- Ư���� �����̳� ��Ģ���� ���Ҹ� ����
*/

void Sequence_Container()
{
	/*
		Vector
		- ���� ���� �迭, ���� �迭�� ���ø�ȭ
		- ���Ұ� ���� �޸𸮿� ���������� ����Ǿ��־� �������� ������ ó���� ����
		- ���� ������ �����Ѵ�. [], at()
		- �Ҵ��� ������ �� ä���� ���, ���ο� ū ������ �������� ���Ҵ��Ͽ�
		  ������ ���ҵ��� �����Ѵ�.
		- �� �ڿ� ���Ҹ� ����, ������ ���� ������, ������ ��ġ�� �ִ� ���Ҹ� ����, �����ϴ� ���
		  �� ���� ���Ҹ� �� ĭ�� �̵������־�� �ϱ� ������ ������.

		//������ ũ�Ⱑ �Ҵ��		//�ʱ� ũ�Ⱑ 2�� ���, 1���� �ʰ��Ǹ� 2����ŭ ���� �߰�(���� �߰��� ������ŭ ��.)
		//���������� ó���ؾ��ϱ� ������, �� ������ ���� ���, �� ������ ���ָ鼭 ä����. �־��� ���, �� ���� �����͸� ������ ���, ��� �����Ͱ� �̵���
		//����, ������ �Ҹ���
		//��ǥ���� ��) ��
		//���͸� ���ͷ� ����� hp�� 0�� �Ǹ� ��Ȱ��ȭ��Ű��, ���� �ð� �Ŀ� �ٽ� Ȱ��ȭ��ų ���� ����

		����ϱ� ���� ���
		- ũ�Ⱑ ���� ������ ��
		- ����, ������ ���� ���� ��
		- �������� ������ ó���� �ʿ��� ��
	*/
	{
		cout << "vector" << endl;
		vector<int> vec;

		for (int i = 0; i < 10; i++)
		{
			vec.push_back(i);
		}
			vec.pop_back();

		for (const auto& ele : vec)
			cout << ele << ' ';
		cout << endl;
	}

	/*
		Dequeue(FIFO)
		- ���Ϳ� ���������, ���Ϳʹ� �ٸ��� ���Ұ� �޸� ������ ���������� �������� ����
		- �޸𸮸� ���Ҵ��� ��, �߰��� �޸� ������ ����� �������� �̾���δ�.
		  => ������ �Ҵ��� ���ͺ��� ����
		- ���� �������ִ� �޸� ������ ������ �����ϱ� ���� ���ͺ��� �߰����� �޸𸮰� �ʿ��ϴ�.
		- ���Ϳ� �ٸ��� �� �� ������ ����, ������ ������.
		- ������ ��ġ�� �ִ� ������ ����, ������ ���ͺ��� ������.
		- ���� ������ �����Ѵ�. [], at()

		����ϱ� ���� ��
		- �� �հ� �� ���� ���Ҹ� ����, �����ϴ� ��찡 ���� ���
		- ����ó�� ����ϰ� ������ ũ�Ⱑ ������ �ȵǴ� ���
	*/

	{
		cout << "deque" << endl;
		deque<int> deq;
		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.push_front(i);
		}
			deq.pop_front();
			deq.pop_back();

		for (const auto& ele : deq)
			cout << ele << ' ';
		cout << endl;
	}

	/*
		List
		- ����� ���� ����Ʈ�� ���ø�ȭ
		- ����Ʈ�� ���� ������ �ּҿ� ������ ������ ��ġ���� ����Ѵ�.

		- ������ ���Ұ� �ڽ��� �հ� �ڿ� ���� ���Ҹ� ����Ű�� �ִ�.
		���� ����
		->, <-�� �����ͷ� �հ� ���� ������ �ּҸ� �����ϰ� �ִ�.

		  ������      ������      ������
		  ������ ->   ������ ->   ������
		  ���Ҥ�      ���Ҥ�      ���Ҥ�
		  ��1 �� <-   ��2 �� <-   ��3 ��
		  ������      ������      ������

	  - ���� ������ ������ �־� ������ ��ġ�� �ִ� ���ҿ� �ٷ� ������ �ȵǰ�
		���������� �����ؾ� �Ѵ�.
	  - ������ ����, ������ �Ͼ ��� ��ũ�� �ٲ��ָ� �Ǳ⿡ ���� ������ ������.

	  - ���� ��Ʈ��ũ�� ����
	  - ��ŷ �ý��ۿ� ���� ���
	  - ���� ������ ���� �� ���
	  - �޸� ����ȭ�� �����ؾ� ��
	*/
	{
		cout << "list" << endl;
		list<int> list;

		for (int i = 0; i < 10; i++)
		{
			list.push_back(i);
		}
			list.pop_back();

		for (const auto& ele : list)
			cout << ele << ' ';
		cout << endl;
	}
}

/*
	associative container
	- �����͸� ������ ��Ģ�� ���� �����ϰ� �����ϴ� �����̳�
	- ������ ����� ��ġ�� ������ �� ���� ���� ���� Ʈ���� �ؽ� ���̺��� �̿��Ͽ� ����
	- ���Ҹ� ������ ��� �ڵ����� �������ֱ� ������ ���ϴ� ���Ҹ� ã�� �˻� �ӵ��� ������.
	- Ű(key) - ��(value) ������ ������.
	-> Ư���� Ű���� ������ �����ϴ� ���� �����ش�.
*/

void Associative_Container()		//���� �����̳�	//tree
{
	/*
		set�� multiset
		- �����ϴ� �����Ͱ� �� ��ü�� Ű�� ����Ѵ�.
		- �������� ���� ������ üũ�ϴ� ��� ���
	*/

	//set - Ű�� �ߺ��� ������� ����		//ũ�罺Į �˰���
	/*
		A B C D
		A B E

		-> A B C D E
		ex) ���� �÷���
	*/

	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl; //2�� //������ �ߺ��Ǵ� ���� ǥ������ �ʱ� ������ size�� 2�� ���´�.

		for (const auto& ele : str_set)
			cout << ele << ' ';
		cout << endl;
	}

	//multiset - Ű�� �ߺ��� �����
	//set���� �ǹ̾��� ���Ǵ�. lower_bound(), upper_bound(), equal_range() ��� ������ multiset������ ���� �����ϰ� ���˴ϴ�.
	https://blockdmask.tistory.com/80
	{
		multiset<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (const auto& ele : str_set)
			cout << ele << ' ';
		cout << endl;
	}

	//key/value -> pair
	{
		std::pair<int, double> test;
		test.first;		//int
		test.second;	//double

		/*
			struct test
			{
				int first;
				int second;
			}
		*/

		/*vector<pair<int, bool>> a;
		a[0].first;
		a[0].second;*/
	}

	/*
		map�� multimap
		- Ű�� ������ ������ ����

		- multimap - ����� ������ ������ ��� ����
	*/
	{
		cout << "map" << endl;
		//map<key, value>	key���� value���� ������ �����ϴ� ���
		map<char, int> map;		//key/value		//mapping
		map['c'] = 50;
		map['a'] = 10;
		map['d'] = 40;
		map['b'] = 20;

		cout << map['a'] << endl;		//key�� ��Ī�Ǵ� ���� 10�� ����

		map['a'] = 100;

		cout << map['a'] << endl;		//�ߺ��� ������� �����Ƿ� 10�̶�� �����Ͱ� 100���� �������

		for (const auto& ele : map)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl;

		//Ű�� �������� ���ĵǱ� ������ abcd ������� ����
	}

	{
		//�ߺ��� key���� ������ ���߿� ���� pair�� ���� �� �ִ� ���� �о 
		cout << "multimap" << endl;
		std::multimap<char, int> multimap;
		multimap.insert(pair<char, int>('a', 10));
		multimap.insert(pair<char, int>('b', 100));
		//multimap.insert(pair('c', 1000));		//c++17������ Ÿ�� ���� ����
		multimap.insert(make_pair('a', 10000));

		cout << multimap.count('a') << endl;	//�ش� key���� ���εǴ� value�� ���� ��ȯ

		for (const auto& ele : multimap)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl;
	}

	/*
	   unordered associative container - ���ĵ��� ���� ���� �����̳�
	   - ���� ���� �����̳ʴ� Ʈ���� ���������
	   ���ĵ��� ���� ���Ҹ� ������ �� �ؽ� ���̺��� ����Ѵ�.
	   - ����, ����, �˻� ��� ������.

	   - unordered_set
	   - unordered_multiset
	   - unordered_map
	   - unordered_multimap
	*/
	
	//���� : �ؽ����̺� ����

	{
		cout << endl;

		/*
			hash ����
			1. hash���� �������� 5�� ��Ʈ�����Ų��.
			2. ���� hash���� ���Ѵ�.
			3. �� ������ ASCII���� ���Ѵ�.
			4. ���� ����� ��� ���ڿ� ���ؼ� �ݺ��Ѵ�.
			5. ���� ���� hash���̺��� ������ �����, ������ ������ �����ش�.
		*/

		/*
			hash collision
			: �ؽð��� ���ٸ�, �������� �ϴ� ���� ���� ���ϰų� ������ Ű�� �����Ǵ� ������ �߻�

			�ذ���
			1. ü�̴�
			 - �ؽ� �Լ��� ���� ������� �� ��ȣ�� �ش��ϴ� ���� ����Ʈ ���� �ڷᱸ���� ��������, �浹�� �Ͼ�� Ű ���� ���� ���Ḯ��Ʈ�� ��ȸ�ϴ� ���

			2. ���� ����ȭ or ���� �ּҹ�(Open Addressing)
			 - ����ִ� ������ ã�Ƽ� �Ҵ��ϴ� ���
		*/

		cout << "hash_test(apple), �ִ� ���̺��� ũ�� = 8191" << endl;
		cout << "Key�� ����� ���Ͽ� Ư�� �Ҽ��� 5381�� �̿�" << endl;
		char a = 'a';		//97
		char p = 'p';		//112
		char l = 'l';		//108
		char e = 'e';		//101

		{
			int a_hash = ((static_cast<int>(a) << 5) + 5381 + 97) % 8191;
			cout << "a�ؽð� : " << a_hash << endl;	//391

			int p1_hash = ((static_cast<int>(p) << 5) + a_hash + 112) % 8191;
			cout << "p1�ؽð� : " << p1_hash << endl;	//4087

			int p2_hash = ((static_cast<int>(p) << 5) + p1_hash + 112) % 8191;
			cout << "p2�ؽð� : " << p2_hash << endl;	//7783

			int l_hash = ((static_cast<int>(l) << 5) + p2_hash + 108) % 8191;
			cout << "l�ؽð� : " << l_hash << endl;

			int e_hash = ((static_cast<int>(e) << 5) + l_hash + 112) % 8191;
			cout << "e�ؽð� : " << e_hash << endl;
		}
		

		cout << endl;
	}
}

/*
	���� : ������ stl�� �����̳� ���α׷��ֿ��� ��� ������ �����ϱ�
*/

void Container_Adapter()
{
	/*
		- ���� �����̳��� �������̽��� �����Ͽ� ���ѵǰų� ������ �����̳�
		- ������ ���ʰ� �Ǵ� Ŭ������ �������̽��� �����Ͽ� Ư�� ������ ���۸��� �����ϵ��� �Ѵ�.
		- �ݺ��ڸ� �������� �ʾ� stl �˰��� ����� �ȵȴ�.
		- stack�� queue�� �߰� ���� Ȯ�κҰ�. ù ���� ������ ���� Ȯ�� ����
	*/

	/*
		Stack
		- �ٸ� �����̳ʸ� �����Ͽ� ���ñ����� ���� �����̳�
		- �������� �����͸� �����ϰ� ���Լ���(LIFO)�� ������.
		- BFS(���̿켱Ž��)

		Last In First Out
		- ���� �������� ����� �����Ͱ� ���� ���� ���´�.

		ex) �ڷΰ���
	*/

	{
		cout << "Stack" << endl;

		std::stack<int/*,*/> stack;		//�Ű������� 2���� �ް� �־�����. �ڿ� �ִ°� deque
		stack.push(1);				//���� ������ �߰�
		stack.emplace(2);			//��ü�� �����ؼ� �߰�
		stack.emplace(3);

		/*
			���� : push, emplace ���� / ���� �� �������� ����

			���� ���� ����� 100% ����

			push : ���� ��Ҹ� ������ �����̳ʿ� ���纻�� �߰�. priority_queue���� ���, pair ������Ʈ�� �����ؾ� ��� ����
			emplace : copy�� move�� ���� �߰��ϴ� ���� �ƴ�, object�� �����ϸ鼭 stack�� �ٷ� �ִ´�. priority_queue���� ���, pair ������Ʈ�� ������ �ʰ� ��� ����.
		*/
		cout << stack.top() << endl;	//���� �ֱ��� ���� �д´�.	//������ �����͸� ������
		stack.pop();					//���� �ֱ��� ���� ����		//������ �����͸� ����
		cout << stack.top() << endl;
		stack.pop();
		cout << stack.top() << endl;
		stack.pop();
	}

	/*
		Queue
		- �������� �����͸� �����ϰ� ���Լ���(FIFO)�� ������.
		- BFS(�ʺ�켱Ž��)

		First In, First Out
		- ���� ���� ����� �����Ͱ� ���� ���� ���´�.
	*/

	{
		cout << "Queue" << endl;

		std::queue<int> queue;

		queue.push(1);
		queue.push(2);
		queue.push(3);

		cout << queue.front() << ' ' << queue.back() << endl;
		queue.pop();
		cout << queue.front() << ' ' << queue.back() << endl;
	}

	/*
		Priority Queue
		- �켱������ ���� �����Ͱ� ���� ���� ������ �ڷᱸ��
		- ���� �� ���Ұ� �ƴ� �켱������ ���� ���� ���Ұ� ���� ���� ���´�.
	*/
	{
		cout << "Priorty Queue" << endl;

		priority_queue<int> priority_queue;
		
		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			priority_queue.push(n);

		for (int i = 0; i < 10; i++)
		{
			cout << priority_queue.top() << ' ';
			priority_queue.pop();
		}
	}

}
