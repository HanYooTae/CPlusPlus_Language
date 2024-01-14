#pragma once
#include<string>
class Teacher
{
public:
	Teacher() = default;
	Teacher(const std::string& name)
		: name(name) 
	{}

	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name = name; }

private:
	std::string name;
};