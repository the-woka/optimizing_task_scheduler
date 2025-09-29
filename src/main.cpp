#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int id, duration, deadline, priority;
};

int main()
{
    int choice;
    vector<Task> tasks;

    while (true)
    {
        cout << "Menu: " << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Update Task" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. See Tasks" << endl;
        cout << "5. Optimize Task" << endl;
        cout << "0. End Program" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                int n;
                cout << "Numbers of Data: ";
                cin >> n;

                for (int i = 0; i < n; i++) {
                    Task t;
                    cout << "Task " << i+1 << endl;
                    cout << "ID: ";
                    cin >> t.id;
                    cout << "Duration (in days): ";
                    cin >> t.duration;
                    cout << "Deadline (in days): ";
                    cin >> t.deadline;
                    cout << "Priority (in scale 1-3): ";
                    cin >> t.priority;
                    tasks.push_back(t);
                }
                break;
            case 2: {
                int searchId;
                cout << "Which ID: ";
                cin >> searchId;
                bool found = false;
                for (auto &t : tasks) {
                    if (t.id == searchId) {
                        cout << "Editing the Task " << t.id << endl;
                        cout << "Duration (current is " << t.duration << "): ";
                        cin >> t.duration;
                        cout << "Deadline (current is " << t.deadline << "): ";
                        cin >> t.deadline;
                        cout << "Priority (current is " << t.priority << "): ";
                        cin >> t.priority;
                        cout << "Task updated successfully" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "ID " << searchId << " not found!" << endl;
                }
                break;
            }
            case 3: {
                int searchId;
                cout << "Which ID: ";
                cin >> searchId;
                bool found = false;
                auto it = tasks.begin();
                for (; it != tasks.end(); ++it) {
                    if (it->id == searchId) {
                        tasks.erase(it);
                        cout << "Task " << searchId << " deleted successfully" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "ID " << searchId << " not found!" << endl;
                }
                break;
            }
            case 4: {
                cout << "Data Tasks:" << endl;
                cout << endl;
                int i = 1;
                for (auto &t : tasks) {
                    cout << "Task " << i++ << endl;
                    cout << "ID: " << t.id << ", ";
                    cout << "Duration: " << t.duration << ", ";
                    cout << "Deadline: " << t.deadline << ", ";
                    cout << "Priority: " << t.priority << endl;
                    cout << endl;
                }
                break;
            }
            case 5:{
                int choiceOptimize;
                cout << "Choose Optimization" << endl;
                cout << "1. EDF (Earliest Deadline First)" << endl;
                cout << "2. HPF (Highest Priority First)" << endl;
                cout << "3. SJF (Shortest Job First)" << endl;
                cout << "4. Most Optimized Scheduler" << endl;
                cout << "Choice: ";
                cin >> choiceOptimize;

                switch (choiceOptimize)
                {
                    case 1: {
                        if (tasks.empty()) {
                            cout << "Tasks Not Found" << endl;
                            break;
                        }
                        sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b) {
                            return a.deadline < b.deadline;
                        });
                        int i = 1;
                        cout << "EDF Sorted Tasks:" << endl;
                        for (auto &t : tasks) {
                            cout << "Task " << t.id << endl;
                        }
                        cout << endl;
                        break;
                    }
                    case 2: {
                        if (tasks.empty()) {
                            cout << "Tasks Not Found" << endl;
                            break;
                        }
                        sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b) {
                            return a.priority > b.priority;
                        });
                        int i = 1;
                        cout << "HPF Sorted Tasks:" << endl;
                        for (auto &t : tasks) {
                            cout << "Task " << t.id << endl;
                        }
                        cout << endl;
                        break;
                    }
                    case 3: {
                        if (tasks.empty()) {
                            cout << "Tasks Not Found" << endl;
                            break;
                        }
                        sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b) {
                            return a.duration < b.duration;
                        });
                        int i = 1;
                        cout << "SJF Sorted Tasks:" << endl;
                        for (auto &t : tasks) {
                            cout << "Task " << t.id << endl;
                        }
                        cout << endl;
                        break;
                    }
                    case 4: {
                        cout << "Most Optimized" endl;
                        break;
                    }
                    default:
                        cout << "Wrong Input" << endl;
                        break;
                }
                break;
            }
            case 0:
                cout << "Task Selesai" << endl;
                return 0;
            default:
                cout << "Wrong Input" << endl;
                break;
        }
    }
}