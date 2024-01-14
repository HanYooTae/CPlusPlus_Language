#pragma once
#include "02_person.h"	//기반 클래스의 헤더를 추가해야한다.
//전방선언으로는 모든걸 알 수 없음. 무조건 헤더를 추가해야 함.
//class Person;

/*
	주의점
	- 파생 클래스가 상속받기 위해서는 기반 클래스의 모든 내용을 알고있어야 하는데,
	  전방선언으로는 기반 클래스의 존재유무만 알 뿐 내부를 알지못하기 때문에
	  상속을 받을 수 없다.
	- 따라서, 상속을 받기 위해서는 기반 클래스가 위치한 헤더의 파일을 추가해주어야 한다.
*/

class Student : public Person
{
public:
	//Student(const std::string& name)
	//	//멤버 이니셜라이저 리스트 : 본인이 가지고있는 멤버를 초기화
	//	:name(name)				//상속받은 멤버는 생성자 멤버 리스트가 아님
	//							//-> 생성과 동시에 초기화를 하는 곳인데 이미 존재하기 때문.
	//							//본인의 멤버만 초기화 가능
	//{
	//	this->name = name;		//생성자 멤버 리스트가 아닌 부분에서는 가능
	//}

	Student(const std::string& name)
		//:Person()			//기반 클래스가 생성되어야 파생클래스가 생성이 된다.
							//그렇기 때문에 보이진 않지만 기반 클래스의 생성자를 암시적으로 호출한다.
							//명시하지 않을 경우, 기본 생성자를 호출해준다.

		: Person(name)		//기반 클래스 생성자에 인자를 넘겨 원하는 생성자 호출
	{
	}

	void Study(){}			//멤버를 추가하여 기능을 확장

	//std::string name;
};