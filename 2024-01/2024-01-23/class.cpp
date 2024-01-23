#include <iostream>
#include <string>


//�� �κ��� struct.cpp�� ������ �����ϰ� struct�� class�� ���̰� �ִ�.
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
		//���Ἲ �˻縦 �־��� �� �ִ�.
		//if (chn >= 1 && chn <= 999)
		//{
		//channel = chn;
		//}
		//AND�� �º��� �캯 ��� �˻縦 �ؾ�������
		//OR�� �տ������� �ϳ��� �˻��Ͽ� ������ �����Ǹ� �Ѿ��.
		//���� ���ǽ��� OR�� Ȱ���ϴ°��� ����.

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
	//������ �ؿ��� �� ��� ����� �� �ִ�.


	tv1.SetChannel(1000);
	tv1.SetVolume(-1);

	std::cout << tv1.IsPowerOn() << std::endl;
	std::cout << tv1.GetChannel() << std::endl;
	std::cout << tv1.GetVolume() << std::endl;



	return 0;
}