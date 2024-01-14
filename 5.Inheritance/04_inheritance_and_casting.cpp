/*
	Up Casting
	- �ڽ� Ŭ������ �θ� Ŭ���� �����ͷ� ����Ű�� ��
	- �ڽ� Ŭ������ �� ũ�� ������ ���������� �� ū �������� ���� ���̶�
	  �Ͻ��� ����ȯ ����
	- �پ��� �ڽ� Ŭ������ �ϳ��� �θ� Ŭ���� �ڷ������� �ٷ� �� �ְ� �ȴ�.

	Down Casting
	- �θ� Ŭ���� �����Ͱ� ����Ű�� ��ü�� �ڽ� Ŭ���� �����ͷ� ����Ű�� ��
	- �θ� Ŭ���� �����Ͱ� �θ��� ��ü�� ����ų ���, �ڽ� Ŭ������ �����ͷ� ��ȯ�� ���� ����.
	- ���������� �Ʒ��� ���� ���̱⿡ ����� ����ȯ�� ����
*/

#include <iostream>
using namespace std;

class Snack {};

class Chitos : public Snack {};
class ChocoChip : public Snack {};
class Homerunball : public Snack {};

int main()
{
	//up-casting : �Ͻ��� ����ȯ ����
	Snack* chocochip = new ChocoChip();
	Snack* chitos = new Chitos();

	//���� �ٸ� �ڽ� Ŭ������ ����� �θ� Ŭ������ ���� ����� ����
	Snack* snack[2] = { chitos, chocochip };

	Chitos* test = static_cast<Chitos*>(chitos);		//����� ����ȯ�� ����

	return 0;
}