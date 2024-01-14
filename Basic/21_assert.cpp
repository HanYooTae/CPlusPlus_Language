#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	int x = 0;
	cout << x << endl;

	//true�� ����ִٸ� ��� ����, false�� ���´ٸ� ���α׷� ����(�����߻���Ŵ)
	//Ư�� ������ ���������� üũ�� �� �ִ�.
	//debug��忡���� üũ��. release��忡���� üũ���� �ʴ´�.

	//runtime �� üũ��. compiletime ���� üũ�� ���� ����.
	//�Ϲ������� ������ Ÿ�� ���� üũ�� �ȵȴ�. ��Ÿ�� �� üũ��.
	//assert(false);
	assert(x != 0 && "x is 0");		//�Ѵ� true�� ��� ��
									//���ڿ� ����� �׻� ���̹Ƿ� &&�� ����Ͽ� ���ڿ��� �߰������� �ٿ��� �� ����.

	cout << "Hello" << endl;

	//static_assert(false);		//������ Ÿ�� �� üũ�� �� �ִ� assert

	//������ Ÿ�� �� �� �� �ִ� �͸� ���� �� �ִ�.
	const int x1 = 6;
	//�Ʒ� �ִ� static_assert�� ������ Ʋ���ٸ� ������ ����
	//const int x1 = 10;
	const int y1 = 7;
	//���ڿ��� �߰������ ��
	static_assert(x1 < y1, "x is bigger than y1");
	cout << x1 << endl;
	cout << y1 << endl;

	//��Ÿ�� �� üũ�Ǵ� ���� �� �� ����.
	int z = 10;
	/*constexpr�� ���̸� ������ ������ Ÿ�� �� ����*/const int w = z;		//��Ÿ�� �� ����ȴ�.

	return 0;
}