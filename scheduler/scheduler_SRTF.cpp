/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include <vector>
#include <algorithm>
#include "../includes/scheduler_SRTF.h"

bool compareRemaining_cpu_time(PCB pcb1, PCB pcb2);

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	int time = 0;
	if (time >= p.remaining_cpu_time) {
		return true;
	}
	if ((ready_q->empty() == false)
			&& (p.remaining_cpu_time > ready_q->front().remaining_cpu_time)) {
		return true;
	} else {
		return false;
	}
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	std::vector<PCB> newq;
	while (ready_q->empty() == false) {
		newq.push_back(ready_q->front());
		ready_q->pop(); //we need the value so this has to happen
	}
	//do sort method here!
	std::sort(newq.begin(), newq.end(), compareRemaining_cpu_time);

	for (PCB process : newq) { //range based loop
		ready_q->push(process);
	}
}

bool compareRemaining_cpu_time(PCB pcb1, PCB pcb2) {
	if (pcb1.remaining_cpu_time < pcb2.remaining_cpu_time) {
		return true;
	} else {
		return false;
	}

}
