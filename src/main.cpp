#include <iostream>
#include <vector>

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
                    cout << "Task " << i+1 << ": " << endl;
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
            case 2:
                cout << "Second Menu" << endl;
                break;
            case 3:
                cout << "Third Menu" << endl;
                break;
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
                }
                break;
            }
            case 5:
                cout << "Fifth Menu" << endl;
                break;
            case 0:
                cout << "Task Selesai" << endl;
                return 0;
            default:
                cout << "Wrong Input" << endl;
                break;
        }
    }
}