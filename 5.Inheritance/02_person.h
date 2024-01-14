#pragma once
#include <string>

//���� �ߺ��� ����� ������ student�� teacher�� �ִ�.
//�ڵ忡 �ߺ��� ���� ���������� ������� -> �����ϱ� ���ؼ� �Ѵ� �����ؾ���
//����� ����� ���� Ŭ������ ����� ��ӽ����ֱ�

//�Ʒ��� ���� �� Ŭ������ ����� ���� �ٿ�����

class EX_Student
{
public:
	EX_Student() = default;
	EX_Student(const std::string& name) :name(name) {}

	auto GetName() const { return name; }
	void SetName(const std::string& name) /*const*/ { this->name = name; }		//const������ ������ �ȵ�

	void Study(){}

private:
	std::string name;
};

class EX_Teacher
{
public:
	EX_Teacher() = default;		//�����ڴ� �ظ��ϸ� 1���� �����صδ� ���� ����.
	EX_Teacher(const std::string& name) :name(name) {}

	auto GetName() const { return name; }
	void SetName(const std::string& name) /*const*/ { this->name = name; }		//const������ ������ �ȵ�

	void Teach() {}

private:
	std::string name;
};

//�ߺ��Ǵ� ����� ���� Ŭ������ �ۼ�
class Person
{
public:		//���� ������
	Person() = default;
	Person(const std::string& name) :name(name) {}

	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name = name; }

protected:
	std::string name;
};