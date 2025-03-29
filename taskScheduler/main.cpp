#include "Scheduler.hpp"
#include <iostream>

using namespace std;

int main() {
	Scheduler scheduler;
	string taskName;
	int priority, execTime = 0;
	while (true) {
		cout << "================================" << endl;
		cout << "1. Add a new task." << endl;
		cout << "2. Updae task information." << endl;
		cout << "3. Remove a task." << endl;
		cout << "4. Execute task" << endl;
		cout << "5. Print tasks" << endl;
		cout << "6. Sort By Execution Time" << endl;
		cout << "7. Reschedual Tasks" << endl;
		cout << "8. Cycle Detection" << endl;
		cout << "Enter your choice;" << endl;
		int choice;
		cin >> choice;
		if (cin.fail()) {
			cout << "Enter integer value only!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		else {
			switch (choice) {
			case 1:
				cout << endl;
				cout << "Enter Task Name: ";
				cin.ignore();
				getline(cin, taskName);
				cout << "Enter Task Priority: ";
				cin >> priority;
				if (cin.fail()) {
					cout << "Enter integer value only!" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
				cout << "Enter Task Execution Time: ";
				cin >> execTime;
				if (cin.fail()) {
					cout << "Enter integer value only!" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
				scheduler.addTask(taskName, priority, execTime);
				break;

			case 2:
				cout << endl;
				cout << "Enter task ID :" << endl;
				int id;
				cin >> id;
				if (cin.fail()) {
					cout << "Enter integer value only!" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
				if (scheduler.getTask(id)) {
					cout << "Choose one of the following: " << endl;
					cout << "1. Update Task Name" << endl;
					cout << "2. Update Task Priority" << endl;
					cout << "3. Update Task Execution Time" << endl;
					cout << "4. Back" << endl;
					cout << "Enter your choice please: ";
					cin >> choice;
					if (cin.fail()) {
						cout << "Enter integer value only!" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
					switch (choice) {
					case 1:
						cout << "Enter the new name : " << endl;
						cin.ignore();
						getline(cin, taskName);
						scheduler.setTaskName(id, taskName);
						break;
					case 2:
						cout << "Enter the new priority : " << endl;
						cin >> priority;
						if (cin.fail()) {
							cout << "Enter integer value only!" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							break;
						}
						scheduler.setTaskPriority(id, priority);
						break;
					case 3:
						cout << "Enter the new execution time : " << endl;
						cin >> execTime;
						if (cin.fail()) {
							cout << "Enter integer value only!" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							break;
						}
						scheduler.setTaskExectime(id, execTime);
						break;
					default:
						break;

					}
					break;
				}
			case 3:
				cout << "Enter the task ID to remove:" << endl;
				cin >> id;
				if (cin.fail()) {
					cout << "Enter integer value only!" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
				scheduler.deleteTask(id);
				break;
			case 4:
				scheduler.executeTask();
				break;
			case 5:
				cout << endl;
				scheduler.printINFO();
				break;
			case 6:
				scheduler.sortByExecTime();
				scheduler.printINFO();
				break;
			case 7:
				scheduler.reschedual();
				scheduler.printINFO();
				break;
			case 8:
				scheduler.cycleDetection(scheduler.simulateCycle());
				break;
			}

		}
	}
}