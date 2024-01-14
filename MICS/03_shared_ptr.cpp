/*
	shared_ptr
		- ����ũ �����Ϳ� �޸� ������ ������ ������ ������
		- �����͸� �Լ��� ���� �����ؾ��� �� ����ũ ������ ��� ����ϱ� ����
		- ���� ī���� ����� ����Ѵ�.
			�� �ش� dull pointer�� �����ϰ� �ִ� ����Ʈ ������ ������ ī�����Ͽ�
			   ������ ����Ʈ �����Ͱ� �Ҹ��� �� �������ִ� ���
*/

#include <iostream>
#include <memory>
#include "02_02_resource.h"
using namespace std;

int main()
{
	{
		// res1�� �����Ǹ� ī��Ʈ 0 -> 1 ����
		auto res1 = std::make_shared<Resource>(5);

		// use_count() : ���� �ڽ��� ������ dull pointer�� �����ϰ��ִ� ����Ʈ �������� ��
		cout << "Count : " << res1.use_count() << endl;

		{
			// res1�� ������ dull �����͸� res2�� �����޴´�, ī��Ʈ ���� 1 -> 2
			auto res2 = res1;

			cout << "Count : " << res2.use_count() << " " << res1.use_count() << endl;
		}	// res2 �Ҹ�, ī��Ʈ ���� 2 -> 1, ���� nullptr�� ������ ����Ʈ �����Ͱ� �־� ����X

		cout << "Count : " << res1.use_count() << endl;
	}	 // res1 �Ҹ�, ī��Ʈ ���� 1 -> 0, dull �����͸� ������ ������ ����Ʈ �����Ͱ� �Ҹ��Ͽ� dull pointer ���� O

	// ������
	Resource* ptr = new Resource(10);

	{
		// res1�� �����Ǹ鼭 ī��Ʈ ���� 0 -> 1
		std::shared_ptr<Resource> res1(ptr);

		cout << "Count : " << res1.use_count() << endl;
		{
			// res2�� �����Ǹ鼭 ī��Ʈ ���� 0 -> 1
			std::shared_ptr<Resource> res2(ptr);

			// res1�� ������ �����Ƿ� count : 1 ���
			cout << "Count : " << res2.use_count() << endl;
		}	//res2 �Ҹ�, ī��Ʈ ���� 1 -> 0, ������ ����Ʈ �����Ͱ� �Ҹ��Ͽ� ������ dull pointer ����

		// ī��Ʈ�� 1 ���
		cout << "Count : " << res1.use_count() << endl;
	}	//res2 �Ҹ�, ī��Ʈ ���� 1 -> 0, ������ ����Ʈ �����Ͱ� �Ҹ��Ͽ� ������ dull pointer ����
	// ������ res2���� ���� �ش� �����͸� ������ -> ��� ������ ���� �߻�

	return 0;
}