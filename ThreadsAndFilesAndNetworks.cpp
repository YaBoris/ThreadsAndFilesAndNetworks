// ThreadsAndFilesAndNetworks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "writer.h"
#include <thread>
#include <iostream>

using namespace std;

int main()
{
	writer writeToFile;
	//thread writerThread;
	this_thread::sleep_for(chrono::milliseconds(3000));
	writeToFile.writeToFile();

	system("Pause");

    return 0;
}

