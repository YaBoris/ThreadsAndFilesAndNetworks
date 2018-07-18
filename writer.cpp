#include "stdafx.h"
#include "writer.h"

int const SIZE_CONTENT = 100000;
int const SIZE_BUFFER = 80;

writer::writer()
{
}

writer::~writer()
{
}

int writer::writeToFile() {
	auto begin = std::chrono::system_clock::now();
	std::ofstream openToRight(NAME, std::ios::out);
	char arrContentForFile[SIZE_CONTENT] = { 0 };
	if (!openToRight) {
		std::cout << "Can't open file \"" << NAME << "\". Wait for next trying." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	else {
		//openToRight << get_file_name();
		ch_generator(arrContentForFile);

		for (int i = 0; i < SIZE_CONTENT; i++) {
			openToRight << arrContentForFile[i];
		}
		openToRight.close();
		std::cout << "File is OK!" << std::endl;
		auto end = std::chrono::system_clock::now();
		auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << millisec.count() << std::endl;
	}
	return 0;
}

const std::string writer::get_file_name() {
	std::ostringstream strStream;
	strStream << std::this_thread::get_id();
	char arrBufferForDateTime[SIZE_BUFFER] = { 0 };
	//get_date and time
	auto now = std::chrono::system_clock::now();
	time_t t = std::chrono::system_clock::to_time_t(now);
	tm* nowTM = std::localtime(&t);
	strftime(arrBufferForDateTime, SIZE_BUFFER, "%d.%m.%Y_%H-%M-%S\n", nowTM);
	std::string resultString = std::string(arrBufferForDateTime, arrBufferForDateTime + strlen(arrBufferForDateTime) - 1);
	//create filename
	const std::string fileName = "id_" + strStream.str() + "_" + resultString +".log";
	
	return fileName;
}

int writer::ch_generator(char* arrContentForFile) {
	std::default_random_engine dre;
	std::uniform_int_distribution<int> uidi(65, 90);
	for (int i = 0; i < SIZE_CONTENT; i++) {
		arrContentForFile[i] = (char)uidi(dre);
		//std::cout << arrContentForFile[i] << "\n";
	}
	//std::cout << std::endl;
	return 0;
}