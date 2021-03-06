// ThreadsAndFilesAndNetworks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "writer.h"
#include "thread_data.h"
#include <iostream>
#include <fstream>
#include <list>

int writeResult(std::list<thread_data>& Statistics) {
	while (1) {
		std::ofstream saveResult("result.csv", std::ios::out);
		if (!saveResult) {
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			continue;
		}
		else {
			for (auto iter = Statistics.begin(); iter != Statistics.end(); iter++) {
				saveResult << iter->get_counteExecution() << ";" << iter->get_ID() << ";" << iter->get_timing() << std::endl;
			}
			saveResult.close();
			break;
		}		
	}
	return 0;
}

int main()
{
	thread_data thrData;
	std::list<thread_data> threadStatistics;
	char exit;
	writer write1;
	writer write2;
	writer write3;
	writer write4;
	writer write5;
	std::ofstream SetToExit("exit.txt", std::ios::out);

	std::thread thrd1(&writer::writeToFile, &write1, std::ref(threadStatistics));
	std::thread thrd2(&writer::writeToFile, &write2, std::ref(threadStatistics));
	std::thread thrd3(&writer::writeToFile, &write3, std::ref(threadStatistics));
	std::thread thrd4(&writer::writeToFile, &write4, std::ref(threadStatistics));
	std::thread thrd5(&writer::writeToFile, &write5, std::ref(threadStatistics));

	if (!SetToExit) {
		std::cout << "Can't open file exit.txt" << std::endl;
	}
	else {
		while (1) {
			std::cout << "Enter 'X' for exit." << std::endl;
			std::cin >> exit;
			if (exit == 'X') {
				SetToExit << exit;
				SetToExit.close();
				break;
			}
		}
	}

	thrd1.join();
	thrd2.join();
	thrd3.join();
	thrd4.join();
	thrd5.join();

	writeResult(threadStatistics);

	system("Pause");

    return 0;
}

