#pragma once

#include <string>
#include <chrono>

using namespace std;

class Task {
private:
	int m_id;
	string m_name;
	int m_priority;
	int m_execution_time;
	chrono::time_point<std::chrono::system_clock> m_startTime;

public:
	Task* m_next;
	Task* m_previous;

	Task(string name, int priority, int execTime);
	//Task();
	void setPriority(int priority);
	void setExecutionTime(int time);
	void setName(string name);
	//void setStartTime(chrono::time_point<std::chrono::system_clock> start);
	int getID();
	int getPriority();
	int getExecutionTime();
	string getName();
	chrono::time_point<std::chrono::system_clock> getStartTime();

};