#pragma once

#include "Task.hpp"

using namespace std;

class Scheduler {
private:
	static int id;
public:
	Task* m_head;
	Scheduler();
	void setTaskName(int id, string name);
	void setTaskPriority(int id, int priority);
	void setTaskExectime(int id, int execTime);
	bool checkID(int id);
	bool validateTaskInfo(string name, int priority, int exectime);
	Task* getTask(int id);
	void addTask(string name, int priority, int execTime);
	void deleteTask(int id);
	void executeTask();
	void printINFO();
	void sortByExecTime();
	Task* addTaskByExecTime(Task* sorted, Task* task);
	void reschedual();
	Task* simulateCycle();
	void cycleDetection(Task* head);
};