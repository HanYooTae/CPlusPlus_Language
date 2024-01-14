#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "03_student.h"
#include"03_teacher.h"

//lecture가 student와 teacher을 소유 -> 집합관계

class Lecture
{
public:
	Lecture(const std::string& name)
		: name(name)
	{}

	void Assignment_Teacher(Teacher* teacher)
	{
		this->teacher = teacher;
	}

	void Assignment_Student(Student* student)
	{
		students.push_back(student); // push_back : 배열의 맨뒤에 추가한다.
	}

	void Print()
	{
		// 각각의 주소를 출력
		std::cout << "teacher : " << teacher << std::endl;

		for (const auto& student : students)
			std::cout << "student : " << student << std::endl;

		std::cout << std::endl;
	}

private:
	std::string name;

	// 필요한 다른 클래스의 참조만을 가지고 있다.
	// 포인터/참조를 지울 경우 composition관계가 된다.
	// 가지고 있을 뿐이므로 소멸자에서 해제하면 안된다.
	Teacher* teacher;
	std::vector<Student*> students;
};