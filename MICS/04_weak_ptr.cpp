/*
	strong reference vs weak reference
	- strong reference : 메모리 해제에 영향을 미치는 참조 -> shared_ptr이 참조할 때 증가
	- weak reference : 메모리 해제에 영향을 주지 않는 참조 -> weak_ptr이 포인터를 참조할 때 증가

	weak_ptr
		- 다른 두 스마트 포인터와 달리 단독으로 사용하지 못하는 스마트 포인터
		- shared_ptr의 순환 의존성 문제를 해결하기 위해 사용한다.
*/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Person
{
public:
	Person(const string& name) : name(name)
	{
		cout << name << " Created" << endl;
	}

	~Person()
	{
		cout << name << " Destroyed" << endl;
	}

	const string& GetName() const { return name; }

	// 외부 함수
	friend bool PartnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (p1 == nullptr || p2 == nullptr)
			return false;

		p1->partner = p2;
		p2->partner = p1;

		cout << p1->name << " is partnered with " << p2->name << endl;
		return true;
	}

private:
	string name;
	// 동적 할당된 객체가 서로가 서로를 shared_ptr 형태로 소유 시 순환 의존성 문제가 발생
	//std::shared_ptr<Person> partner;

	// weak_ptr 형태로 소유하여 순환 의존성 문제 해결 가능
	// -> 서로가 참조하고 있다는 것은 알지만, 해제 시 영향을 주지 않는다.
	std::weak_ptr<Person> partner;
};

class Test : public Person
{
public:
	Test(const std::string& name)
		: Person(name)
	{}
};

int main()
{
	/*
		circular dependency issues : 순환 의존성 문제

		서로가 서로를 참조하는 상황에서 카운팅이 서로에게 물려있어
		서로 지워지길 기다리고 있기 때문에 카운팅이 되지 않고 무한정 대기하게 됨(메모리가 삭제되지 않음) -> 메모리 누수
	*/
	{
		// 할당된 Lucy를 스마트 포인터 lucy가 소유, 강한 참조 -> 참조 0 -> 1
		auto lucy = std::make_shared<Person>("Lucy");

		// 할당된 Ricky를 스마트 포인터 ricky가 소유, 강한 참조 -> 참조 0 -> 1
		auto ricky = std::make_shared<Person>("Ricky");
		
		// 동적 할당된 객체 Lucy에서 Ricky를 소유
		// 동적 할당된 객체 Ricky에서 Lucy를 소유
		// 서로의 카운트 1 -> 2 증가
		PartnerUp(lucy, ricky);

	}	/*
			스마트 포인터 lucy, ricky 소멸->각각의 카운트 감소 2 -> 1
			하지만, 동적 할당된 객체 Lucy, Ricky가 멤버 변수로 서로를 shared_ptr 형태로 가지고 있음.

			1. Lucy가 소멸하기 위해 Ricky가 가진 스마트 포인터가 소멸해야 함
			2. Ricky가 가진 스마트 포인터가 소멸되기 위해서는 Ricky가 소멸해야 함
			3. Ricky가 소멸하기 위해 Lucy가 가진 스마트 포인터가 소멸해야 함
			4. Lucy가 가진 스마트 포인터가 소멸되기 위해서는 Ricky가 소멸해야 함
				-> 무한 반복

			서로가 무한루프를 가지고 있다해서 순환 의존성 문제라고 부른다.
			-> 서로를 소유할 때 weak_ptr 형태로 소유하여 문제 해결 가능
		*/

	// weak_ptr
	{
		auto test = std::make_shared<Person>("Test");
		auto test1 = test;
		std::weak_ptr<Person> weak = test;

		cout << endl << "------------------------------------------------------------" << endl;

		test = nullptr;		// == test.reset();

		// expired() : weak_ptr이 참조한 포인터의 소멸 여부 확인, 소멸 시 true 반환
		if (weak.expired() != true)
			cout << "유효함" << endl;		// 만료되지 않음
		else
			cout << "유효하지 않음" << endl;	// 만료됨

		cout << endl << "------------------------------------------------------------" << endl;

		/*
			weak_ptr 형태로는 바로 사용하지 못하고 shared_ptr 형태로 바꾸어서 사용해야 한다.
			-> 멀티 스레드 환경에서는 weak_ptr이 데이터를 사용할 때 먼저 shared_ptr이 전부 해제되어
			weak_ptr이 참조한 데이터가 소멸하는 것을 막기 위해 사용 전에 최소 1의 강한 참조 횟수를 확보하기 위함이다.
		*/

		// weak-> error		// 사용하려면 weak.lock()-> 사용
		weak.lock()->GetName();	// ok	 // lock() : 약한 참조(weak_ptr)를 강한 참조(shared_ptr)형태로 바꾸어준다.
	}

	cout << endl;

	// 추가적인 스마트 포인터 사용법 + 주의점
	{
		auto test1 = std::make_shared<Person>("Test1");
		auto test2 = std::make_shared<Person>("Test2");

		// 1. 스마트 포인터끼리 스왑 가능
		test1.swap(test2);

		// 2. 해당 스마트 포인터의 포인터 비우기 (아래 둘 중 하나)
		// 삭제 X, 해당 스마트 포인터만 데이터를 포기하는 것
		test1.reset();
		test1 = nullptr;

		// 3. 스마트 포인터의 캐스팅
		// 업캐스팅은 암시적 형변환 가능
		std::shared_ptr<Person> parent = std::make_shared<Test>("Test");

		// 다운 캐스팅은 무조건 명시적 형변환을 해주어야 한다.
		// 스마트 포인터의 형변환은 _pointer 문구가 더 붙음
		std::shared_ptr<Test> child = std::static_pointer_cast<Test>(parent);

		// 4. 스마트 포인터의 포인터 보유 여부 확인법
		// dull 포인터 동일하게 주소값 보유 여부 확인 가능
		if (test1 == nullptr);
		if (!test1 != false);
	}

	return 0;
}