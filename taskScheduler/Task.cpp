#include "Task.hpp"
#include "UniqueID.hpp"
#include<iostream>

Task::Task(string name, int priority, int execTime): m_id(UniqueID::generateID()), m_name(name), 
m_priority(priority), m_execution_time(execTime), m_startTime(chrono::system_clock::now()), m_next(nullptr), m_previous(nullptr) {}

//Task::Task(): m_id(UniqueID::generateID()) , m_name(""), m_priority(5), m_execution_time(10), startTime(chrono::system_clock::now()), m_next(nullptr), m_previous(nullptr) {}

void Task::setPriority(int priority) {
	if (priority <= 0 || priority > 5) {
		cout << "Priority should be from 1 to 5 only!" << endl;
		return;
	}
	m_priority = priority;
}

void Task::setExecutionTime(int time) {
	if (time <= 0) {
		cout << "Execution time cannot be 0 or negative" << endl;
		return;
	}
	m_execution_time = time;
}

void Task::setName(string name) {
	if (name.empty()) {
		cout << "Nmae can't be empty" << endl;
		return;
	}
	m_name = name;
}


const int Task::getID() const {
	return m_id;
}

const int Task::getPriority() const {
	return m_priority;
}

const int Task::getExecutionTime() const {
	return m_execution_time;
}

const string Task::getName() const {
	return m_name ;
}

const chrono::time_point<std::chrono::system_clock> Task::getStartTime() const{
	return m_startTime;
}
