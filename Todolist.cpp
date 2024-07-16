#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Task structure to hold task details
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function prototypes
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    char Choice;

    do {
        cout << "\n========== ToDo List Manager ==========\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> Choice;
        cin.ignore(); // Clear the input buffer

        switch (Choice) {
            case '1':
                addTask(tasks);
                break;
            case '2':
                viewTasks(tasks);
                break;
            case '3':
                markCompleted(tasks);
                break;
            case '4':
                removeTask(tasks);
                break;
            case '5':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter again.\n";
        }
    } while (Choice != '5');

    return 0;
}

// Function to add a task to the list
void addTask(vector<Task>& tasks) {
    string taskDesc;
    cout << "Enter task description: ";
    getline(cin, taskDesc);
    tasks.push_back(Task(taskDesc));
    cout << "Task added successfully!\n";
}

// Function to view all tasks with their status
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found!\n";
    } else {
        cout << "===== Task List =====\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            cout << (tasks[i].completed ? "[Completed] " : "[Pending] ");
            cout << tasks[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    int index;
    cout << "Enter the task number to mark as completed (1-" << tasks.size() << "): ";
    cin >> index;
    cin.ignore(); // Clear the input buffer

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!\n";
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    int index;
    cout << "Enter the task number to remove (1-" << tasks.size() << "): ";
    cin >> index;
    cin.ignore(); // Clear the input buffer

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!\n";
    }
}