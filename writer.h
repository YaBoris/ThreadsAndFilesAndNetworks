#pragma once
#include <locale>
#include <thread>
#include <ctime>
#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <mutex>
#include <list>
#include "thread_data.h"

class writer
{
private:
	const std::string get_file_name();
	int ch_generator(char* content);
	std::string NAME;
public:
	writer();
	~writer();
	int writeToFile(std::list<thread_data>& thrStatistics);
};

