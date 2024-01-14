/*
	Multi Inheritance - 다중 상속
	- 한 클래스가 2개 이상의 클래스를 상속받는
	- 다중 상속이 좋은 방식은 아니기 때문에
	  다른 언어에서는 허용하지 않는 경우도 있음
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

//2개 이상의 클래스를 상속받음 -> 다중 상속
//여러 문제를 야기하기 때문에 왠만하면 사용하지 말자..
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

	//기반 클래스끼리의 멤버 이름이 중복되어 문제 발생
	//device.GetID();		//error : ambiguous

	//해결 방법1 -> 중복된 함수이름 변경(번거로움)

	//해결 방법2 -> namespace 사용
	cout << device.USBDevice::GetID() << endl;
	cout << device.NetworkDevice::GetID() << endl;

	return 0;
}

/*
	과제 : 다중 상속의 문제점 조사, 다이아몬드 상속 조사
*/