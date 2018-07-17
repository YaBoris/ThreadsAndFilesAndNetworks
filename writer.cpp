#include "stdafx.h"
#include "writer.h"

writer::writer()
{
}

writer::~writer()
{
}

int writer::writeToFile(){
	std::ofstream openToRight(NAME, std::ios::out);
	if (!openToRight) {
		std::cout << "Can't open file \"" << "fileName" << "\"" << std::endl;
	}
	else {
		openToRight << get_file_name();
		openToRight.close();
		std::cout << "File is OK!" << std::endl;
	}
	return 0;
}

const std::string writer::get_file_name() {
	std::ostringstream strStream;
	strStream << std::this_thread::get_id();
	char buffer[80] = { 0 };
	//get_date and time
	auto now = std::chrono::system_clock::now();
	time_t t = std::chrono::system_clock::to_time_t(now);
	tm* nowTM = std::localtime(&t);
	strftime(buffer, 80, "%d.%m.%Y_%H-%M-%S\n", nowTM);
	std::string resultString = std::string(buffer, buffer + strlen(buffer) - 1);
	//create filename
	const std::string fileName = "id_" + strStream.str() + "_" + resultString +".log";
	
	return fileName;
}