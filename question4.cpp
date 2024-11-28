/*
Marvel Aiken
1123543
28/11/2024
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

// A structure to represent a task
struct Task {
    int profit;
    int deadline;

    Task(int p, int d) : profit(p), deadline(d) {}
};

// Function to compare tasks based on profit in descending order
bool compare(Task &a, Task &b) {
    return a.profit > b.profit;
}

// Function to schedule tasks and maximize profit
void scheduleTasks(vector<Task>& tasks, int n) {
    // Sort tasks in descending order of profit
    sort(tasks.begin(), tasks.end(), compare);

    // To keep track of the scheduled tasks and the time slots
    vector<int> slots(n, -1);  // -1 means slot is available
    int totalProfit = 0;
    vector<int> scheduledTasks;

    // Iterate through the sorted tasks
    for (int i = 0; i < n; ++i) {
        // Try to find the latest available time slot for this task
        for (int j = tasks[i].deadline - 1; j >= 0; --j) {
            if (slots[j] == -1) {
                // Slot found for the task
                slots[j] = i;  // Schedule task at slot j
                totalProfit += tasks[i].profit;
                scheduledTasks.push_back(i);
                break;
            }
        }
    }

    // Output the total maximum profit
    cout << endl << "Maximum Profit: " << totalProfit << endl;

    // Output the scheduled tasks (by their original indices)
    cout << "Scheduled Tasks: [";
    for (int taskIdx : scheduledTasks) {
        cout << tasks[taskIdx].profit << " ";
    }
    cout << "]" << endl;
}

int main() {
    int n;
    cin >> n;  // Number of tasks

    vector<Task> tasks;
    for (int i = 0; i < n; ++i) {
        int profit, deadline;
        cin >> profit >> deadline;
        tasks.push_back(Task(profit, deadline));
    }

    // Schedule tasks to maximize profit
    scheduleTasks(tasks, n);

    return 0;
}
