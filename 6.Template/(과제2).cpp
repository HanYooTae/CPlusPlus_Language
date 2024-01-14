// ���� 2
/*
   �Ʒ��� Ŭ������ ���� ���ø� ���ڿ� ���� �����͸� 8�� �������ִ� Ŭ�����̴�.

   ���⼭ ������ ����µ� bool���� ���� �� ������ �����ϰ� �ȴ�.
   -> bool���� 1����Ʈ ũ�⸸���ε� 8������ ǥ���� �� ������ �Ʒ���
   ���� ������ ��� 1����Ʈ * 8�� ũ�⸦ ������.

   �Ʒ��� Ŭ������ ���ø� Ư��ȭ�� bool���Ͻ�
   1����Ʈ�� ������ 8���� �Ұ��� ó���� �� �ְ� ������

   template <class T>
class Storage8
{
public:
    void Set(int index, const T& value)
    {
        arr[index] = value;
    }

    const T& Get(int index) { return arr[index]; }

private:
    T arr[8];
};
*/

#include <iostream>
using namespace std;

template <class T>
class Storage8
{
public:
    void Set(int index, const T& value)
    {
        arr[index] = value;
    }

    const T& Get(int index) { return arr[index]; }

private:
    T arr[8];
};


template <>
class Storage8<bool>
{
public:
    void Set(int index, const bool& value) {
        if (value == true) {
            arr = arr | (1 << index);
        }
        else {
            arr = arr & (255 - (1 << index));
        }
    }

    const bool& Get(int index) {
        return arr & (1 << index);
    }

private:
    char arr;
};

int main()
{
    Storage8<bool> str;

    cout << boolalpha;
    cout << str.Get(5) << endl;

    str.Set(5, true);

    cout << str.Get(5) << endl;

    return 0;
}