/*
	STL - Standard Template Library
	- 컨테이너, 반복자, 알고리즘을 지원한다.
	- 템플릿을 사용하여 어떠한 타입의 데이터여도 위의 라이브러리 기능을 사용할 수 있다.
		-> 자료형을 일반화하여 코드의 수정없이 동일한 작업을 수행할 수 있게 해준다.

		컨테이너(container)
		- 임의 타입의 데이터를 보관할 수 있다.

		반복자(iterator)
		- 컨테이너에 보관된 원소에 접근할 때 사용

		알고리즘(algorithm)
		- 반복자들을 가지고 일련의 작업을 수행한다.
*/

/*
	container - 컨테이너
	- 동일한 타입의 여러 객체를 저장하는 집합, 저장소
	- 템플릿을 사용해 저장하는 데이터의 자료형에 무관하게 무엇이든 담을 수 있게 만들어져있다.
	- 컨테이너의 종류
	
	1. sequence
		- 일반적인 자료구조와 동일한 형태
		- 자료를 입력한 순서대로 저장하기 때문에 저장, 검색, 알고리즘에 불리함
		- 적은 양의 자료나 검색 속도가 중요하지 않은 경우에 사용
			ex) vector, list, deque 등

	2. associative
		- 일정한 규칙에 따라 자료를 조직화하여 저장
		- 자료를 정렬하여 저장하기 때문에 검색에 유리
		- 많은 양의 자료나 검색 속도가 중요한 경우에 사용
			ex) set, map, multiset, multimap 등

	3. adaptor
		- 시퀀스 컨테이너를 변형시켜 스택 큐 우선순위 큐 형태로 저장
			ex) queue, stack 등
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

void Sequence_Container();		//데이터가 선형적으로 저장되어있는 컨테이너
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
	- 배열처럼 데이터를 선형으로 저장하는 컨테이너
	- 특별한 제약이나 규칙없이 원소를 보관
*/

void Sequence_Container()
{
	/*
		Vector
		- 가변 길이 배열, 동적 배열을 템플릿화
		- 원소가 실제 메모리에 순차적으로 저장되어있어 연속적인 데이터 처리에 유리
		- 임의 접근을 제공한다. [], at()
		- 할당한 공간을 다 채웠을 경우, 새로운 큰 공간을 동적으로 재할당하여
		  기존의 원소들을 복사한다.
		- 맨 뒤에 원소를 삽입, 삭제할 때는 빠르나, 임의의 위치에 있는 원소를 삽입, 삭제하는 경우
		  그 뒤의 원소를 한 칸씩 이동시켜주어야 하기 때문에 느리다.

		//임의의 크기가 할당됨		//초기 크기가 2일 경우, 1개가 초과되면 2개만큼 공간 추가(공간 추가는 제곱만큼 됨.)
		//연속적으로 처리해야하기 때문에, 빈 공간이 있을 경우, 빈 공간을 없애면서 채워짐. 최악의 경우, 맨 앞의 데이터를 삭제할 경우, 모든 데이터가 이동됨
		//삽입, 삭제가 불리함
		//대표적인 예) 맵
		//몬스터를 벡터로 만들고 hp가 0이 되면 비활성화시키고, 일정 시간 후에 다시 활성화시킬 수도 있음

		사용하기 좋은 경우
		- 크기가 예측 가능할 때
		- 삽입, 삭제가 별로 없을 때
		- 연속적인 데이터 처리가 필요할 때
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
		- 벡터와 비슷하지만, 벡터와는 다르게 원소가 메모리 공간에 연속적으로 존재하지 않음
		- 메모리를 재할당할 때, 추가로 메모리 공간을 만들어 논리적으로 이어붙인다.
		  => 데이터 할당이 벡터보다 빠름
		- 서로 떨어져있는 메모리 공간의 정보를 보관하기 위해 벡터보다 추가적인 메모리가 필요하다.
		- 벡터와 다르게 맨 앞 원소의 삽입, 삭제가 빠르다.
		- 임의의 위치에 있는 원소의 삽입, 삭제가 벡터보다 빠르다.
		- 임의 접근을 제공한다. [], at()

		사용하기 좋을 때
		- 맨 앞과 맨 뒤의 원소를 삽입, 삭제하는 경우가 많은 경우
		- 벡터처럼 사용하고 싶지만 크기가 예측이 안되는 경우
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
		- 양방향 연결 리스트를 템플릿화
		- 리스트는 시작 원소의 주소와 마지막 원소의 위치만을 기억한다.

		- 각각의 원소가 자신의 앞과 뒤에 오는 원소를 가리키고 있다.
		구조 예시
		->, <-는 포인터로 앞과 뒤의 원소의 주소를 저장하고 있다.

		  ㅁㅁㅁ      ㅁㅁㅁ      ㅁㅁㅁ
		  ㅁ원ㅁ ->   ㅁ원ㅁ ->   ㅁ원ㅁ
		  ㅁ소ㅁ      ㅁ소ㅁ      ㅁ소ㅁ
		  ㅁ1 ㅁ <-   ㅁ2 ㅁ <-   ㅁ3 ㅁ
		  ㅁㅁㅁ      ㅁㅁㅁ      ㅁㅁㅁ

	  - 위의 구조를 가지고 있어 임의의 위치에 있는 원소에 바로 접근이 안되고
		순차적으로 접근해야 한다.
	  - 원소의 삽입, 삭제가 일어날 경우 링크만 바꿔주면 되기에 삽입 삭제가 빠르다.

	  - 링형 네트워크와 유사
	  - 랭킹 시스템에 많이 사용
	  - 삽입 삭제가 많을 때 사용
	  - 메모리 단편화를 조심해야 함
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
	- 데이터를 일정한 규칙에 따라 저장하고 관리하는 컨테이너
	- 저장한 요소의 위치를 지정할 수 없고 균형 이진 트리나 해시 테이블을 이용하여 구현
	- 원소를 삽입할 경우 자동으로 정렬해주기 때문에 원하는 원소를 찾는 검색 속도가 빠르다.
	- 키(key) - 값(value) 구조를 가진다.
	-> 특정한 키값을 넣으면 대응하는 값을 돌려준다.
*/

void Associative_Container()		//관계 컨테이너	//tree
{
	/*
		set과 multiset
		- 저장하는 데이터값 그 자체를 키로 사용한다.
		- 데이터의 존재 유무만 체크하는 경우 사용
	*/

	//set - 키의 중복을 허용하지 않음		//크루스칼 알고리즘
	/*
		A B C D
		A B E

		-> A B C D E
		ex) 몬스터 컬렉션
	*/

	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl; //2개 //집합은 중복되는 것을 표시하지 않기 때문에 size는 2가 나온다.

		for (const auto& ele : str_set)
			cout << ele << ' ';
		cout << endl;
	}

	//multiset - 키의 중복을 허용함
	//set에서 의미없게 사용되던. lower_bound(), upper_bound(), equal_range() 멤버 변수가 multiset에서는 좀더 유용하게 사용됩니다.
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
		map과 multimap
		- 키와 값으로 데이터 관리

		- multimap - 경매장 동일한 아이템 출력 가능
	*/
	{
		cout << "map" << endl;
		//map<key, value>	key값과 value값을 쌍으로 저장하는 방식
		map<char, int> map;		//key/value		//mapping
		map['c'] = 50;
		map['a'] = 10;
		map['d'] = 40;
		map['b'] = 20;

		cout << map['a'] << endl;		//key와 매칭되는 값인 10이 나옴

		map['a'] = 100;

		cout << map['a'] << endl;		//중복을 허용하지 않으므로 10이라는 데이터가 100으로 덮어씌워짐

		for (const auto& ele : map)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl;

		//키를 기준으로 정렬되기 때문에 abcd 순서대로 나옴
	}

	{
		//중복된 key값이 들어오면 나중에 들어온 pair가 먼저 들어가 있던 것을 밀어냄 
		cout << "multimap" << endl;
		std::multimap<char, int> multimap;
		multimap.insert(pair<char, int>('a', 10));
		multimap.insert(pair<char, int>('b', 100));
		//multimap.insert(pair('c', 1000));		//c++17에서는 타입 생략 가능
		multimap.insert(make_pair('a', 10000));

		cout << multimap.count('a') << endl;	//해당 key값에 매핑되는 value의 개수 반환

		for (const auto& ele : multimap)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl;
	}

	/*
	   unordered associative container - 정렬되지 않은 연관 컨테이너
	   - 위의 연관 컨테이너는 트리를 사용하지만
	   정렬되지 않은 원소를 저장할 때 해시 테이블을 사용한다.
	   - 삽입, 삭제, 검색 모두 빠르다.

	   - unordered_set
	   - unordered_multiset
	   - unordered_map
	   - unordered_multimap
	*/
	
	//과제 : 해시테이블 조사

	{
		cout << endl;

		/*
			hash 계산법
			1. hash값을 왼쪽으로 5번 비트연산시킨다.
			2. 원본 hash값을 더한다.
			3. 한 문자의 ASCII값을 더한다.
			4. 위의 결과를 모든 문자에 대해서 반복한다.
			5. 최종 값이 hash테이블의 범위를 벗어나면, 나머지 연산을 취해준다.
		*/

		/*
			hash collision
			: 해시값이 같다면, 얻으려고 하는 값을 얻지 못하거나 엉뚱한 키가 삭제되는 문제가 발생

			해결방법
			1. 체이닝
			 - 해시 함수를 통해 얻어지는 방 번호에 해당하는 연결 리스트 등의 자료구조를 만들어놓고, 충돌이 일어나면 키 값을 통해 연결리스트를 순회하는 방법

			2. 개방 번지화 or 개방 주소법(Open Addressing)
			 - 비어있는 공간을 찾아서 할당하는 방법
		*/

		cout << "hash_test(apple), 최대 테이블의 크기 = 8191" << endl;
		cout << "Key를 만들기 위하여 특정 소수인 5381을 이용" << endl;
		char a = 'a';		//97
		char p = 'p';		//112
		char l = 'l';		//108
		char e = 'e';		//101

		{
			int a_hash = ((static_cast<int>(a) << 5) + 5381 + 97) % 8191;
			cout << "a해시값 : " << a_hash << endl;	//391

			int p1_hash = ((static_cast<int>(p) << 5) + a_hash + 112) % 8191;
			cout << "p1해시값 : " << p1_hash << endl;	//4087

			int p2_hash = ((static_cast<int>(p) << 5) + p1_hash + 112) % 8191;
			cout << "p2해시값 : " << p2_hash << endl;	//7783

			int l_hash = ((static_cast<int>(l) << 5) + p2_hash + 108) % 8191;
			cout << "l해시값 : " << l_hash << endl;

			int e_hash = ((static_cast<int>(e) << 5) + l_hash + 112) % 8191;
			cout << "e해시값 : " << e_hash << endl;
		}
		

		cout << endl;
	}
}

/*
	과제 : 각각의 stl이 게임이나 프로그래밍에서 어디서 사용될지 조사하기
*/

void Container_Adapter()
{
	/*
		- 기존 컨테이너의 인터페이스를 제한하여 제한되거나 변형된 컨테이너
		- 각각의 기초가 되는 클래스의 인터페이스를 제한하여 특정 형태의 동작만을 수행하도록 한다.
		- 반복자를 지원하지 않아 stl 알고리즘 사용이 안된다.
		- stack과 queue의 중간 값은 확인불가. 첫 값과 마지막 값만 확인 가능
	*/

	/*
		Stack
		- 다른 컨테이너를 변형하여 스택구조로 만든 컨테이너
		- 선형으로 데이터를 저장하고 후입선출(LIFO)를 따른다.
		- BFS(깊이우선탐색)

		Last In First Out
		- 가장 마지막에 저장된 데이터가 가장 먼저 나온다.

		ex) 뒤로가기
	*/

	{
		cout << "Stack" << endl;

		std::stack<int/*,*/> stack;		//매개변수를 2개를 받고 있었던거. 뒤에 있는건 deque
		stack.push(1);				//값을 복사해 추가
		stack.emplace(2);			//객체를 생성해서 추가
		stack.emplace(3);

		/*
			과제 : push, emplace 조사 / 뭐가 더 빠른지도 조사

			둘의 최종 결과는 100% 동일

			push : 기존 요소를 가져와 컨테이너에 복사본을 추가. priority_queue같은 경우, pair 오브젝트를 생성해야 사용 가능
			emplace : copy나 move를 통해 추가하는 것이 아닌, object를 생성하면서 stack에 바로 넣는다. priority_queue같은 경우, pair 오브젝트를 만들지 않고도 사용 가능.
		*/
		cout << stack.top() << endl;	//가장 최근의 값을 읽는다.	//맨위의 데이터를 보여줌
		stack.pop();					//가장 최근의 값을 제거		//맨위의 데이터를 제거
		cout << stack.top() << endl;
		stack.pop();
		cout << stack.top() << endl;
		stack.pop();
	}

	/*
		Queue
		- 선형으로 데이터를 저장하고 선입선출(FIFO)를 따른다.
		- BFS(너비우선탐색)

		First In, First Out
		- 가장 먼저 저장된 데이터가 가장 먼저 나온다.
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
		- 우선순위가 높은 데이터가 가장 먼저 나오는 자료구조
		- 먼저 들어간 원소가 아닌 우선순위가 가장 높은 원소가 제일 먼저 나온다.
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
