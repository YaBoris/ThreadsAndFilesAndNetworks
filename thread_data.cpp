#include "stdafx.h"
#include "thread_data.h"

thread_data::thread_data(){
	timing = 0;
	countExecution = 0;
}

thread_data::~thread_data(){
}

int thread_data::set_ID(std::thread::id currentID){
	ID = currentID;
	return 0;
}

int thread_data::set_timing(int time){
	timing = time;
	return 0;
}

int thread_data::set_counteExecution(int countEx){
	countExecution = countEx;
	return 0;
}

std::thread::id thread_data::get_ID(){
	return ID;
}

int thread_data::get_timing(){
	return timing;
}

int thread_data::get_counteExecution(){
	return countExecution;
}
