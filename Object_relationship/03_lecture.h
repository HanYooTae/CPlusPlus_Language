#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "03_student.h"
#include"03_teacher.h"

//lecture�� student�� teacher�� ���� -> ���հ���

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
		students.push_back(student); // push_back : �迭�� �ǵڿ� �߰��Ѵ�.
	}

	void Print()
	{
		// ������ �ּҸ� ���
		std::cout << "teacher : " << teacher << std::endl;

		for (const auto& student : students)
			std::cout << "student : " << student << std::endl;

		std::cout << std::endl;
	}

private:
	std::string name;

	// �ʿ��� �ٸ� Ŭ������ �������� ������ �ִ�.
	// ������/������ ���� ��� composition���谡 �ȴ�.
	// ������ ���� ���̹Ƿ� �Ҹ��ڿ��� �����ϸ� �ȵȴ�.
	Teacher* teacher;
	std::vector<Student*> students;
};