#include "Scheduler.hpp"
#include "UniqueID.hpp"
#include <iostream>
#include <thread>
#include <unordered_set>

Scheduler::Scheduler() : m_head(nullptr) {}

void Scheduler::setTaskName(int id, string name) {
	Task* task = getTask(id);
	if (task) {
		task->setName(name);
	}
}

void Scheduler::setTaskPriority(int id, int priority) {
	Task* task = getTask(id);
	if (task) {
		task->setPriority(priority);
	}
}

void Scheduler::setTaskExectime(int id, int execTime) {
	Task* task = getTask(id);
	if (task) {
		task->setExecutionTime(execTime);
	}
}

bool Scheduler::checkID(int id)
{	
	if (id <= 0) {
		cout << "id cannot be 0 or negative" << endl;
		return false;
	}
	if (id > UniqueID::getLastID()) {
		cout << "This ID doesn't exist!" << endl;
		return false;
	}
	return true;
}
// given list with ID 1 -> 2 -> 3 , remove 2 and try to get it, what the above function will return ?

bool Scheduler::validateTaskInfo(string name, int priority, int exectime) {
	if (name.empty()) {
		cout << "Task name cannot be empty!!" << endl;
		return false;
	}

	if (priority <= 0 || priority > 5) {
		cout << "Priority should be from 1 to 5 only!" << endl;
		return false;
	}

	if (exectime <= 0) {
		cout << "Execution time cannot be 0 or negative" << endl;
			return false;
	}
	return true;
}

Task* Scheduler::getTask(int id)
{
	if (!checkID(id)) return nullptr;
	Task* current = m_head;
	while (current) {
		if (current->getID() == id) {
			return current;
		}
		current = current->m_next;
	}
	return nullptr;
}

void Scheduler::addTask(string name, int priority, int execTime) {
	if (!validateTaskInfo(name, priority, execTime)) return;
	Task* task = new Task(name, priority, execTime);
	if (!m_head) {
		m_head = task;
	}
	else {
		if (priority < m_head->getPriority() || priority == m_head->getPriority() && execTime <= m_head->getExecutionTime()) {
			task->m_next = m_head;
			task->m_previous = nullptr;
			m_head->m_previous = task;
			m_head = task;
		}
		else {
			Task* current = m_head;
			Task* previous = nullptr;
			while (current) {
				if ((task->getPriority() < current->getPriority()) ||
					(task->getPriority() == current->getPriority() && task->getExecutionTime() <= current->getExecutionTime())) {
					current->m_previous->m_next = task;
					task->m_previous = current->m_previous;
					task->m_next = current;
					current->m_previous = task;
					break;
				}
				else {
					previous = current;
					current = current->m_next;
				}
			}
			if (!current) {
				cout << "Last";
				previous->m_next = task;
				task->m_previous = previous;
			}
		}	
	}
	cout << "A new task with ID : " << task->getID() << " is added." << endl;
}

void Scheduler::deleteTask(int id) {
	Task* current = getTask(id);
	if (!current) return;
	if (m_head->getID() == id) {
		if (m_head->m_next) {
			m_head = m_head->m_next;
			m_head->m_next->m_previous = nullptr;
		}
		else {
			m_head = nullptr;
		}
		
		
	}
	else {
		if (current->m_next) {
			current->m_previous->m_next = current->m_next;
			current->m_next->m_previous = current->m_previous;
		}
		else {
			current->m_previous->m_next = nullptr;
		}
		current = nullptr;
		delete current;
	}
	cout << "The task with ID : " << id << " is deleted." << endl;
}

void Scheduler::executeTask() {
	if (!m_head) { 
		cout << "There is no tasks to be executed1" << endl;
		return;
	}
	int time = m_head->getExecutionTime();
	cout << "Start to execute the task with the ID :" << m_head->getID() << "and it will take " << m_head->getExecutionTime() << endl;
	cout << "Execution in progress . . ." << endl;
	this_thread::sleep_for(chrono::seconds(time));
	cout << "Done executing the task with the ID :" << m_head->getID() << endl;
	m_head = m_head->m_next;
}

void Scheduler::printINFO() {
	if (!m_head) {
		cout << "No tasks avilable to print" << endl;
		return;
	}
	Task* current = m_head;
	while (current) {
		cout << "ID: " << current->getID() << "\t" << "Name: " << current->getName() << "\t" <<
			"Priority: " << current->getPriority() << "\t" << "Execution Time: " << current->getExecutionTime() << endl;
		current = current->m_next;
	}
}

Task* Scheduler::addTaskByExecTime(Task*sorted, Task* task) {
	if (!sorted) {
		sorted = task;
		sorted->m_previous = nullptr;
		sorted->m_next = nullptr;
	}
	else {
		if (task->getExecutionTime() <= sorted->getExecutionTime()) {
			task->m_next = sorted;
			task->m_previous = nullptr;
			sorted->m_previous = task;
			sorted = task;
		}
		else {
			Task* current = sorted;
			Task* previous = nullptr;
			while (current) {
				if (task->getExecutionTime() <= current->getExecutionTime()) {
					current->m_previous->m_next = task;
					task->m_previous = current->m_previous;
					task->m_next = current;
					current->m_previous = task;
					break;
				}
				else {
					previous = current;
					current = current->m_next;
				}
			}
			if (!current) {
				cout << "Last";
				previous->m_next = task;
				task->m_previous = previous;
				task->m_next = nullptr;
			}
		}
	}
	return sorted;
}

void Scheduler::sortByExecTime()
{
	if (!m_head) {
		cout << "No available tasks to be sorted";
		return ;
	}
	Task* sorted = nullptr;
	Task* current= m_head;
	Task* next = nullptr;
	while (current->m_next) {// 1->2->3
		next = current->m_next;
		sorted = addTaskByExecTime(sorted, current);
		current = next;
	}
	sorted = addTaskByExecTime(sorted, next);
	m_head = sorted;
}

void Scheduler::reschedual() {
	if (!m_head) {
		cout << "No available tasks!";
		return;
	}
	auto nowTime = chrono::system_clock::now();
	Task* current = m_head;
	while (current) {
		chrono::duration<int> duration = chrono::duration_cast<std::chrono::seconds>(nowTime - current->getStartTime());
		if (duration.count() > 10) {
			int priority = current->getPriority();
			if (priority > 1) {
				priority--;
				current->setPriority(priority);
				cout << "The PRIORITY of the Task with ID = " << current->getID() << "has updated to : " << priority << endl;
				deleteTask(current->getID());
				addTask(current->getName(), current->getPriority(), current->getExecutionTime());

			}
			else {
				cout << "The PRIORITY of the Task with ID = " << current->getID() << "CANNOT BE REDUCED" << endl;
			}
		}
		current = current->m_next;
	}
}

Task* Scheduler::simulateCycle() {
	Task* one = new Task("one", 3, 30);
	Task* two = new Task("two", 4, 40);
	Task* three = new Task("three", 3, 30);
	Task* four = new Task("one", 2, 30);

	one->m_previous = nullptr;
	one->m_next = two;
	two->m_previous = one;
	two->m_next = three;
	three->m_previous = two;
	three->m_next = four;
	four->m_previous = three;
	four->m_next = two;

	return one;
}

void Scheduler::cycleDetection(Task* head) {
	if (!head) {
		cout << "NO available tasks!" << endl;
		return;
	}
	Task* current = head;
	Task* previous = nullptr;
	unordered_set<Task*> visited;
	while (current) {
		if (visited.find(current) != visited.end()) {
			cout << "Cycle detected between task ID: "<< current->getID() << " and task ID: "<< previous->getID() << endl;
			break;
		}
		else {
			visited.insert(current);
		}
		previous = current;
		current = current->m_next;
	}
}
