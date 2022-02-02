#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
//using namespace std::chrono;
using namespace std::literals::chrono_literals;
//using namespace std;

bool finish = false;
bool flag = true;

void plus()
{
	while (!finish)
	{
		//if(flag)
			std::cout << "+ ";
		//Sleep(100);
		std::this_thread::sleep_for(10ms);
		//flag = false;
	}
}

void minus()
{
	while (!finish)
	{
		//if(!flag)
			std::cout << "- ";
		//Sleep(100);
		std::this_thread::sleep_for(10ms);
		//flag = true;
	}
}

void main()
{
	//plus();
	//minus();

	std::thread plus_thread(plus);
	std::thread minus_thread(minus);

	std::cin.get(); //ожидает нажатия Enter
	finish = true;

	minus_thread.join();
	plus_thread.join();
}