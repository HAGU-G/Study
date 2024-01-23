#include <iostream>
#include <string>

namespace myname1
{
	int n;
	void set()
	{
		n = 20;
	}
}

namespace myname2
{
	int n;
	void set()
	{
		n = 30;
	}
	namespace myname3
	{
		int n;
		void set()
		{
			n = 40;
		}
	}
}

using namespace myname1;

int main()
{


	set();
	myname2::set();
	myname2::myname3::set();

	std::cout << n << std::endl;
	std::cout << myname2::n << std::endl;
	std::cout << myname2::myname3::n << std::endl;



	return 0;
}