#include "stdafx.h"
#include "writer.h"

int const SIZE_CONTENT = 100000;
int const SIZE_BUFFER = 80;

writer::writer(){

}

writer::~writer(){
}

int writer::writeToFile() {
	auto temp_id = std::this_thread::get_id();
	std::mutex mtx;
	{
		std::lock_guard<std::mutex> guard(mtx);
		NAME = get_file_name();
	}
	//begin time
	//auto begin = std::chrono::system_clock::now();
	char arrContentForFile[SIZE_CONTENT] = { 0 };
	while (1) {
		//read exit.txt file for control when thread must be terminate
		char exit;
		std::ifstream isExit("exit.txt", std::ios::in);
		if(!isExit)
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		else {
			isExit.get(exit);
			if (exit == 'X') {
				isExit.close();
				break;
			}
			else isExit.close();
		}

		//work with file with array of chars
		std::ofstream openToRight(NAME, std::ios::out);// | std::ios::app
		if (!openToRight) {
			{
				std::lock_guard<std::mutex> guard(mtx);				
				std::cout << temp_id << " - Can't open file \"" << NAME << "\". Wait for next trying." << std::endl;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			continue;
		}
		else {
			ch_generator(arrContentForFile);
			{
				for (int i = 0; i < SIZE_CONTENT; i++) {
					openToRight << arrContentForFile[i];
				}
				openToRight.close();
			}
			//end time
			//auto end = std::chrono::system_clock::now();
			//auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			//{
			//	std::lock_guard<std::mutex> guard(mtx);
			//	std::cout << millisec.count() << " msec. File is OK!" << std::endl;
			//}
			//REMOVE WHEN WILL CREATED READER
			//break;
			//
		}
	}
	return 0;
}

const std::string writer::get_file_name() {
	std::ostringstream strStream;
	strStream << std::this_thread::get_id();
	//save to temp arraye current data about date and time for future name of file for current thread
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
		}
	return 0;
}