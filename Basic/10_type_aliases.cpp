#include <iostream>
#include <vector>	//동적 배열

int main()
{
	/*
		type aliases : 가명, 별명 -> using
	*/

	typedef double distance_t;		//double을 distance_t로 표현 가능 
	typedef float f;

	distance_t hi;
	f number = 1.0f;

	std::vector<std::pair<std::string, std::string>> pair_list;
	
	using namespace std;

	//그래도 길다
	vector<pair<string, string>> pair_list2;

	//typedef를 이용한 별명 지정
	typedef std::vector<std::pair<std::string, std::string>> pair_list_t;
	pair_list_t pair_list_t_1;

	//using을 사용한 별명 지정
	using pair_list_ty = std::vector<std::pair<std::string, std::string>>;
	pair_list_ty pair_list_ty_1;

	return 0;
}