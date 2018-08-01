// ThreadsAndFilesAndNetworks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "writer.h"
#include <iostream>
#include <fstream>

//using namespace std;

int main()
{
	char exit;
	writer write;
	std::ofstream SetToExit("exit.txt", std::ios::out);
	std::thread thrd1([&]() {write.writeToFile();});
	std::thread thrd2([&]() {write.writeToFile();});
	std::thread thrd3([&]() {write.writeToFile();});
	std::thread thrd4([&]() {write.writeToFile();});
	std::thread thrd5([&]() {write.writeToFile();});

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

	system("Pause");

    return 0;
}

