#pragma once
#include <thread>

class thread_data
{
	std::thread::id ID;
	int timing;
	int countExecution;
public:
	thread_data();
	~thread_data();
	int set_ID(std::thread::id currentID);
	int set_timing(int time);
	int set_counteExecution(int countEx);
	std::thread::id get_ID();
	int get_timing();
	int get_counteExecution();
};

