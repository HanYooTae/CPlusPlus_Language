#include<iostream>
using namespace std;

/*
   anonymous object
   - Ŭ������ �ν��Ͻ�ȭ ���ϰ� ��� �Լ��� ����Ϸ��� �� �� ���.
*/
class A
{
public:
    void print()
    {
        cout << "print" << endl;
    }

    //destructor�� ��� �Լ��� ������ �� �Ŀ� �ϰ������� ����ȴ�.
    ~A()
    {
        cout << "destructor" << endl;
    }
};

int main()
{
    // ����� �ѹ��� �Ұ������� ��ü�� ����� ����Ѵ�. -> ���ŷӴ�.
    A a;
    a.print();

    // �͸� ��ü�� ����ϸ� ���� ���ϰ� ��밡��
    A().print(); // �����ǰ� �Լ� ������ �����

    return 0;
}