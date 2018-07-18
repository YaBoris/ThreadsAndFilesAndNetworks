#pragma once
#include <locale>
#include <thread>
#include <ctime>
#include <chrono>
#include <iostream>
//#include <cstdlib>
#include <fstream>
#include <sstream>
#include <random>

class writer
{
private:
	const std::string get_file_name();
	int ch_generator(char* content);
	const std::string NAME = get_file_name();	
public:
	writer();
	~writer();
	int writeToFile();
};

