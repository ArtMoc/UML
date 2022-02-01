#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
using namespace std::chrono;
//using namespace std;

bool finish = false;

void plus()
{
	while (!finish)
	{
		std::cout << "+ ";
		Sleep(100);
	}
}

void minus()
{
	while (!finish)
	{
		std::cout << "- ";
		Sleep(100);
	}
}

void main()
{
	//plus();
	//minus();

	std::thread plus_thread(plus);
	std::thread minus_thread(minus);

	minus_thread.join();
	plus_thread.join();
}