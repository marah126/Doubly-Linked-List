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
	Task* m_next; // why public?
	Task* m_previous; // why public ?
	// NOTE: since these vars are public the user can access them.

	Task(string name, int priority, int execTime);
	//Task();
	void setPriority(int priority);
	void setExecutionTime(int time);
	void setName(string name);
	//void setStartTime(chrono::time_point<std::chrono::system_clock> start);
	const int getID() const;
	const int getPriority() const;
	const int getExecutionTime() const;
	const string getName() const;
	const chrono::time_point<std::chrono::system_clock> getStartTime() const;
	// Add const return and const function (cannot edit to class variables)??
};