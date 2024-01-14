/*
	Multi Inheritance - ���� ���
	- �� Ŭ������ 2�� �̻��� Ŭ������ ��ӹ޴�
	- ���� ����� ���� ����� �ƴϱ� ������
	  �ٸ� ������ ������� �ʴ� ��쵵 ����
*/

#include <iostream>
using namespace std;

class USBDevice
{
public:
	USBDevice() = default;
	USBDevice(int id) : id(id) {}

	auto GetID() const { return id; }
	void PlugAndPlay() {}

private:
	int id;
};

class NetworkDevice
{
public:
	NetworkDevice() = default;
	NetworkDevice(int id) : id(id) {}

	auto GetID() const { return id; }
	void Networking() {}

private:
	int id;
};

//2�� �̻��� Ŭ������ ��ӹ��� -> ���� ���
//���� ������ �߱��ϱ� ������ �ظ��ϸ� ������� ����..
class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(int usb_id, int net_id)
		:USBDevice(usb_id)
		, NetworkDevice(net_id)
	{

	}

	USBNetworkDevice(int id)
		:USBDevice(id)
		, NetworkDevice(id)
	{

	}
};

int main()
{
	USBNetworkDevice device(1.10, 2.10);
	device.PlugAndPlay();
	device.Networking();

	//��� Ŭ���������� ��� �̸��� �ߺ��Ǿ� ���� �߻�
	//device.GetID();		//error : ambiguous

	//�ذ� ���1 -> �ߺ��� �Լ��̸� ����(���ŷο�)

	//�ذ� ���2 -> namespace ���
	cout << device.USBDevice::GetID() << endl;
	cout << device.NetworkDevice::GetID() << endl;

	return 0;
}

/*
	���� : ���� ����� ������ ����, ���̾Ƹ�� ��� ����
*/