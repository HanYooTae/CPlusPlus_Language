#include <iostream>
#include <vector>	//���� �迭

int main()
{
	/*
		type aliases : ����, ���� -> using
	*/

	typedef double distance_t;		//double�� distance_t�� ǥ�� ���� 
	typedef float f;

	distance_t hi;
	f number = 1.0f;

	std::vector<std::pair<std::string, std::string>> pair_list;
	
	using namespace std;

	//�׷��� ���
	vector<pair<string, string>> pair_list2;

	//typedef�� �̿��� ���� ����
	typedef std::vector<std::pair<std::string, std::string>> pair_list_t;
	pair_list_t pair_list_t_1;

	//using�� ����� ���� ����
	using pair_list_ty = std::vector<std::pair<std::string, std::string>>;
	pair_list_ty pair_list_ty_1;

	return 0;
}