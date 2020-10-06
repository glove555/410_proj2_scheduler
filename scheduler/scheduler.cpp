/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */
#include <vector>
#include <queue>
#include "../includes/scheduler.h"
#include "../includes/constants.h"
#include "../includes/PCB.h"

using namespace std;
//FOR REFERENCE
//Scheduler::Scheduler(std::queue<PCB> &queue, bool preemptive, int time_slice) :
//ready_q(&queue), preemptive(preemptive), time_slice(time_slice){
//}

//add a process --> this means using queue
//had been running on the CPU and has been preempted
void Scheduler::add(PCB p) {
	ready_q->push(p);
	sort();
}

//get next process
PCB Scheduler::getNext() {
	PCB next = ready_q->front();
	ready_q->pop();
	return next;
}

//returns true if there are no  jobs in the readyQ
//false otherwise
bool Scheduler::isEmpty() {
	if (ready_q->empty()) {
		return true;
	} else {
		return false;
	}
}

//if process has completed (used all its remaining_cpu_time) or
//if we are using a preemptive scheduling algorithm and the
//timeslice is over then its time to switch processes
//returns:
//true - switch processes
//false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	int time = 0;
	if (time >= p.remaining_cpu_time) {
		return true;
	} else {
		return false;
	}
}

// sort  ready_q based on the scheduler algorithm used whenever add(PCB p) is called
void Scheduler::sort() {
	sort();
}

