#include <iostream>
#include <string>


//이 부분은 struct.cpp와 완전히 동일하고 struct와 class만 차이가 있다.
class TV
{
private:
	bool powerOn = false;
	int channel = 1;
	int volume = 100;
public:
	bool IsPowerOn()
	{
		return powerOn;
	}
	void On()
	{
		powerOn = true;
	}
	void Off()
	{
		powerOn = false;
	}

	void SetChannel(int chn)
	{
		//무결성 검사를 넣어줄 수 있다.
		//if (chn >= 1 && chn <= 999)
		//{
		//channel = chn;
		//}
		//AND는 좌변과 우변 모두 검사를 해야하지만
		//OR는 앞에서부터 하나씩 검사하여 조건이 만족되면 넘어간다.
		//따라서 조건식은 OR를 활용하는것이 좋다.

		if (chn < 0 || chn > 999)
		{
			return;
		}
		channel = chn;
	}
	int GetChannel()
	{
		return channel;
	}

	void SetVolume(int vol)
	{
		if (vol < 0 || vol > 100)
		{
			return;
		}
		volume = vol;
	}
	int GetVolume()
	{
		return volume;
	}
};

int main()
{

	TV tv1;
	TV tv2;
	TV tv3;
	TV tvs[1000];
	TV* tvPtr = tvs;
	TV& tvRef = tv2;
	sizeof(TV);
	//기존에 해오던 것 모두 사용할 수 있다.


	tv1.SetChannel(1000);
	tv1.SetVolume(-1);

	std::cout << tv1.IsPowerOn() << std::endl;
	std::cout << tv1.GetChannel() << std::endl;
	std::cout << tv1.GetVolume() << std::endl;



	return 0;
}