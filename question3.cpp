/*
Marvel Aiken
1123543
28/11/2024
*/

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>  // For stringstream to parse the input
#include <climits>

using namespace std;

// A structure to store the element, its array index, and its element index
struct Element {
    int value;
    int arrayIndex;
    int elementIndex;

    // Constructor to initialize the structure
    Element(int v, int arrIdx, int eleIdx) : value(v), arrayIndex(arrIdx), elementIndex(eleIdx) {}

    // Overload the less-than operator to create a Min Heap
    bool operator>(const Element& other) const {
        return value > other.value;  // Min Heap (smaller values have higher priority)
    }
};

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    int k = arrays.size();
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    vector<int> result;

    // Insert the first element of each array into the min-heap
    for (int i = 0; i < k; ++i) {
        if (!arrays[i].empty()) {
            minHeap.push(Element(arrays[i][0], i, 0));  // (value, array index, element index)
        }
    }

    // Process the heap until all elements are merged
    while (!minHeap.empty()) {
        // Get the smallest element from the heap
        Element smallest = minHeap.top();
        minHeap.pop();

        // Add the smallest element to the result array
        result.push_back(smallest.value);

        // If there are more elements in the same array, add the next element to the heap
        int nextElementIndex = smallest.elementIndex + 1;
        if (nextElementIndex < arrays[smallest.arrayIndex].size()) {
            minHeap.push(Element(arrays[smallest.arrayIndex][nextElementIndex], smallest.arrayIndex, nextElementIndex));
        }
    }

    return result;
}

int main() {
    int K;
    cin >> K;  // Number of arrays
    cin.ignore();  // Ignore the newline character after the integer input

    vector<vector<int>> arrays(K);
    string line;

    for (int i = 0; i < K; ++i) {
        getline(cin, line);  // Read each array as a line
        stringstream ss(line);
        int num;

        // Read all integers from the line and add them to the corresponding array
        while (ss >> num) {
            arrays[i].push_back(num);
        }
    }

    vector<int> mergedArray = mergeKSortedArrays(arrays);

    // Output the merged array
    for (int val : mergedArray) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
