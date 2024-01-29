#include <iostream>
#include <string>
using namespace std;

class Image {
public:
	operator string() {
		return "사진";
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
		cout << "보낸 시간 : " << GetSendTime() << endl;
		cout << "보낸 사람 : " << GetSendName() << endl;
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
		cout << "  내 용   : " << GetText() << endl;
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
		cout << "  내 용   : " << (string)*image << endl;
	}

private:

	Image* image;
};


int main() {

	//Image* dogImage = new Image;  // Image 객체를 미리 만들어 둔다.
	//
	//Message* testMsg = new Message(0, "TEST");
	//TextMessage* hello = new TextMessage(10, "이름", "안녕");
	//// 만들어 둔 객체의 포인터를 생성자의 인수로 집어 넣는다.
	//ImageMessage* dog = new ImageMessage(20, "이름", dogImage);

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

	//--------------------실습2---------------------
	//delete dogImage;
	//delete hello;
	//delete dog;

	//Image* image = new Image();
	//Message* msg = new ImageMessage(10, "IMG MSG", "...", image);

	//msg->Print();

	//delete msg; //참조하고 있는 포인터형의 소멸자만 호출한다.
	////클래스의 소멸자 앞에 virtual을 붙여줘야한다. → 평소 모든 클래스의 소멸자에 virtual을 붙이는 습관을 들이는 것이 좋다.
	////동적할당 해준 것이 있을 때 메모리 누수가 되는 것을 막을 수 있다.
	//delete image;

	//----------실습3---------
	Image* image = new Image();
	Message* msg = new ImageMessage(10, "IMG MSG", "...", image);

	msg->Print();
	cout << msg->GetMessage();
}