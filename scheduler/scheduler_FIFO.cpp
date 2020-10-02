/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#include "../includes/scheduler_FIFO.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p) {
	int time = 0;
	if (time >= p.remaining_cpu_time) {
		return true;
	} else {
		return false;
	}
}

//FIFO - not preemptive - no sorting needed
void Scheduler_FIFO::sort() {
//do not put anything here, but function still needed to make everything happy
}
