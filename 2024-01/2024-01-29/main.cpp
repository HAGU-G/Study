#include <iostream>
#include <string>
using namespace std;

class Image {
public:
	operator string() {
		return "����";
	}
};

class Message
{
protected:
	int sendTime;
	string sendName;
public:
	Message(int sendTime, string sendName)
		:sendTime(sendTime), sendName(sendName)
	{
	}
	virtual ~Message()
	{
		std::cout << "~Message()";
	}

	int GetSendTime() const { return sendTime; }
	string GetSendName() const { return sendName; }

	virtual void Print()
	{
		cout << "���� �ð� : " << GetSendTime() << endl;
		cout << "���� ��� : " << GetSendName() << endl;
	}
	virtual string GetMessage() const = 0;

};

class TextMessage : public Message {
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName), text(text)
	{
		//this->sendTime = sendTime;
		//this->sendName = sendName;
		//this->text = text;
	}
	virtual ~TextMessage()
	{
		std::cout << "~TextMessage()";
	}

	string GetText() const { return text; }


	string GetMessage() const override
	{
		return text;
	}

	void Print() override
	{
		Message::Print();
		cout << "  �� ��   : " << GetText() << endl;
	}

protected:

	string text;
};

class ImageMessage : public TextMessage {
public:
	ImageMessage(int sendTime, string sendName, string text, Image* image)
		: TextMessage(sendTime, sendName, text), image(image)
	{
		//this->sendTime = sendTime;
		//this->sendName = sendName;
		//this->image = image;
	}
	virtual ~ImageMessage()
	{
		std::cout << "~ImageMessage()";
	}


	Image* GetImage() const { return image; }

	string GetMessage() const override
	{
		return (string)*image + ", " + text;
	}
	void Print() override
	{
		Message::Print();
		cout << "  �� ��   : " << (string)*image << endl;
	}

private:

	Image* image;
};


int main() {

	//Image* dogImage = new Image;  // Image ��ü�� �̸� ����� �д�.
	//
	//Message* testMsg = new Message(0, "TEST");
	//TextMessage* hello = new TextMessage(10, "�̸�", "�ȳ�");
	//// ����� �� ��ü�� �����͸� �������� �μ��� ���� �ִ´�.
	//ImageMessage* dog = new ImageMessage(20, "�̸�", dogImage);

	//testMsg->Print();
	//hello->Print();
	//dog->Print();
	//
	//cout << endl;
	//Message* ptr = testMsg;
	//ptr->Print();
	//ptr = hello;
	//ptr->Print();
	//ptr = dog;
	//ptr->Print();

	//--------------------�ǽ�2---------------------
	//delete dogImage;
	//delete hello;
	//delete dog;

	//Image* image = new Image();
	//Message* msg = new ImageMessage(10, "IMG MSG", "...", image);

	//msg->Print();

	//delete msg; //�����ϰ� �ִ� ���������� �Ҹ��ڸ� ȣ���Ѵ�.
	////Ŭ������ �Ҹ��� �տ� virtual�� �ٿ�����Ѵ�. �� ��� ��� Ŭ������ �Ҹ��ڿ� virtual�� ���̴� ������ ���̴� ���� ����.
	////�����Ҵ� ���� ���� ���� �� �޸� ������ �Ǵ� ���� ���� �� �ִ�.
	//delete image;

	//----------�ǽ�3---------
	Image* image = new Image();
	Message* msg = new ImageMessage(10, "IMG MSG", "...", image);

	msg->Print();
	cout << msg->GetMessage();
}