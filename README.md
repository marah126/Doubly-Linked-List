# Task Scheduler Project
This project is a simple simulation of processes and scheduling them using the doubly linked list data structure.

## Features
- Adding new task.
- Update task information.
- Remove task based on task ID.
- Execute the highest priority task.
- Print all the tasks with their information.
- Sort the tasks based on the execution time.
- Rescheduling tasks.
- Cycle detection.

  ## Componenets
  - **UniqueID** class reresent a class to generate tasks ID.
    **members**:
    	static int id: represent the ID to be generated and incremented.
    **methods**:
    int static generateID(): a method to increment the ID every time a new task is created.
    int static getLastID(): a method to get the last ID.
    
  - **Task** class represents the task with its information.
    **members:**
    - int m_id: it is an auto-generated ID that represents the task ID.
    - string m_name: represents the task name.
    - int m_priority: represents the task priority (1–5), where 1 represents the highest priority and 5.
    - int m_execution_time: represents the time required to execute the task in seconds. 
    - chrono::time_point<std::chrono::system_clock> m_startTime: represents the time when the task id added.
    - Task* m_next: pointer to the next task.
    - Task* m_previous: pointer to the previous task.
     **methods:**
    - Task(string name, int priority, int execTime): constructor to creat new task.
    - void setPriority(int priority): method to update and set the priority of the task.
    - void setExecutionTime(int time): method to update and set the execution time of the task.
    - void setName(string name): method to update and set the name of the task.
    - int getID(): method to get the task ID.
    - int getPriority(): method to get the task priority.
    - int getExecutionTime(): method to get the task execution time.
    - string getName(): method to get the task name.
    - chrono::time_point<std::chrono::system_clock> getStartTime(): method to get the task start time.
      
  - **Scheduler** class represents the scheduler.
    **members:**
    Task* m_head: represents the head of the doubly linked list.
    **methods:**
    - Scheduler(): default constructor to create scheduler.
    - void setTaskName(int id, string name): method to update and set the name of a task based on its ID.
    - void setTaskPriority(int id, int priority): method to update and set the priority of a task based on its ID.
    - void setTaskExectime(int id, int execTime): method to update and set the execution time of a task based on its ID.
    - bool checkID(int id): method to check an ID if it is exist in the likend list or not and it returns boolean.
    - bool validateTaskInfo(string name, int priority, int exectime): method to check the informations of a task, it checks the task name if it empty, it chacks the priority and make sure its between 1 and 5, and it checks the execution time to be postive.
    - Task* getTask(int id): method that returns a pointer to the specified task based on its ID.
    - void addTask(string name, int priority, int execTime);
    - void deleteTask(int id);
    - void executeTask();
    - void printINFO();
    - void sortByExecTime();
    - Task* addTaskByExecTime(Task* sorted, Task* task);
    - void reschedual();
    - Task* simulateCycle();
    - void cycleDetection(Task* head);
        
