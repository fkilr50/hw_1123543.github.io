/*
Marvel Aiken
1123543
28/11/2024
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

// Structure to store task information
struct Task {
    string name;
    int priority;
    
    Task(string n, int p) : name(n), priority(p) {}
};

// Max-Heap class
class MaxHeap {
private:
    vector<Task> heap;

    // Helper function to heapify up
    void heapifyUp(int index) {
        while (index > 0 && heap[index].priority > heap[(index - 1) / 2].priority) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Helper function to heapify down
    void heapifyDown(int index) {
        int size = heap.size();
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left].priority > heap[largest].priority) {
            largest = left;
        }

        if (right < size && heap[right].priority > heap[largest].priority) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Add task to the heap
    void addTask(const string& name, int priority) {
        heap.push_back(Task(name, priority));
        heapifyUp(heap.size() - 1);
    }

    // Get the highest priority task and remove it from the heap
    string getTask() {
        if (heap.empty()) {
            return "No tasks available";
        }
        string taskName = heap[0].name;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return taskName;
    }

    // Display all remaining tasks in descending order of priority
    void displayRemainingTasks() {
        vector<Task> remainingTasks = heap;
        sort(remainingTasks.begin(), remainingTasks.end(), [](const Task& a, const Task& b) {
            return a.priority > b.priority;  // Sort by priority in descending order
        });

        cout << endl << "Remaining Task: " ;
        for (const Task& task : remainingTasks) {
            cout << task.name << " " << task.priority << ", ";
        }
    }
};

int main() {
    MaxHeap pq;  // Create the priority queue (max-heap)
    
    int N;  // Number of operations
    cin >> N;
    cin.ignore();  // Ignore the newline after reading N
    
    for (int i = 0; i < N; ++i) {
        string operation;
        getline(cin, operation);
        
        // Process ADD operation
        if (operation.substr(0, 3) == "ADD") {
            istringstream ss(operation);
            string command, name;
            int priority;
            ss >> command >> name >> priority;
            pq.addTask(name, priority);
        }
        // Process GET operation
        else if (operation == "GET") {
            cout << pq.getTask() << endl;
        }
    }
    
    // At the end, display remaining tasks in descending order of priority
    pq.displayRemainingTasks();
    
    return 0;
}
