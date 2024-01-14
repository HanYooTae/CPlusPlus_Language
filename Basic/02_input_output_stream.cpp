#include <iostream>
#include <iomanip>

/*
	stream(>>, <<)
	- �������� �Է°� ����� �帧�� ǥ���� ��
*/

int main()
{
	/*
		cout, endl
	*/

	int x = 1028;
	double pi = 3.141592;

	std::cout << "x is " << x << " pi is " << pi << std::endl << std::endl;
	
	/*
		cin
	*/

	/*
		>> input operator(stream)
	*/

	int z;
	std::cin >> z;
	std::cout << "input : " << z << std::endl;
	std::cout << std::endl;

	/*
		������ (manipulator)
		- ��� ������ �������� �� �ִ�.
		- �ٲ����� �ʴ� �� ��� �����ȴ�.
	*/

	int num = 100;

	// ���� ��� ���� ������, �ٲ� �Ŀ� �ٸ� �������� �ٲ��ְ� �ʹٸ�, �ݵ�� ���� ��� ���� �����ڸ� �ٲ��־�� �Ѵ�.
	// 8����
	std::cout << std::oct << num << std::endl;
	// 10����
	std::cout << std::dec << num << std::endl;
	// 16����
	std::cout << std::hex << num << std::endl << std::endl;

	/*
		showbase : � ���� ���·� ��µǴ��� ǥ��
		showpos	 : ������ ������ ��ȣ ǥ��
		-> noshowbase, noshowpos�� ���� ���� ����
	*/
	std::cout << std::showbase << std::showpos;	
	std::cout << std::oct << num << std::endl;					// 8����  = 0144	(8������ �տ� 0�� ����)
	std::cout << std::dec << num << std::endl;					// 10���� = +100	(10������ �տ� +�� ����)
	std::cout << std::hex << num << std::endl << std::endl;		// 16���� = 0x64	(16������ �տ� 0x�� ����)
	std::cout << std::noshowbase << std::noshowpos;

	bool is_true = true;
	bool is_false = false;

	std::cout << std::boolalpha;	// true, false �������� ���
	std::cout << is_true << std::endl;
	std::cout << is_false << std::endl;

	std::cout << std::noboolalpha;	// boolalpha ��� (1, 0���� ���)
	std::cout << is_true << std::endl;
	std::cout << is_false << std::endl;

	


	return 0;
}

#include <iomanip>		//������ ���