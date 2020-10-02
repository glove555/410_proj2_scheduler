/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */
#include <numeric>
#include <math.h>
#include <algorithm>
#include <vector>
#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector) {
	vec = &finished_vector;
	av_wait_time = 0.0;
	av_turnaround_time = 0.0;
	av_response_time = 0.0;
}
double avg = 0.0;
//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo() {
	for (unsigned int i = 0; i < vec->size(); i++) {
		std::cout << "Process" << " " << vec->at(i).process_number
				<< " " << "required CPU time:" << vec->at(i).required_cpu_time
				<< " " << "arrived:" << vec->at(i).arrival_time
				<< " " << "started:" << vec->at(i).start_time
				<< " " << "finished:" << vec->at(i).finish_time
				<< std::endl;
	}

}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the avg over all processes
float Stats::get_av_response_time() {
	for (unsigned int i = 0; i < vec->size(); i++) {
		av_response_time = vec->at(i).start_time - vec->at(i).arrival_time;
		avg = avg + av_response_time;
	}
	avg = avg / vec->size();
	return avg;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the avg over all processes
float Stats::get_av_turnaround_time() {
	for (unsigned int i = 0; i < vec->size(); i++) {
		av_turnaround_time = vec->at(i).finish_time - vec->at(i).arrival_time;
		avg = avg + av_turnaround_time;
	}
	avg = avg / vec->size();
	return avg;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the avg over all processes
float Stats::get_av_wait_time() {
	for (unsigned int i = 0; i < vec->size(); i++) {
		av_wait_time = vec->at(i).finish_time - vec->at(i).arrival_time
				- vec->at(i).required_cpu_time;
		avg = avg + av_wait_time;
	}
	avg = avg / vec->size();
	return avg;
}
