/*
Marvel Aiken
1123543
28/11/2024
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to build a binary tree from level-order input
TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr; // Empty tree or root is null

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Function to calculate the height of a tree and update the diameter
int calculateHeight(TreeNode* root, int& diameter) {
    if (root == nullptr) {
        return 0; // Base case: height of an empty tree is 0
    }

    // Recursively calculate the height of left and right subtrees
    int leftHeight = calculateHeight(root->left, diameter);
    int rightHeight = calculateHeight(root->right, diameter);

    // Update the diameter if the path through the current node is larger
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the current node
    return 1 + max(leftHeight, rightHeight);
}

// Function to calculate the diameter of the tree
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0; // Initialize diameter
    calculateHeight(root, diameter); // Calculate height and update diameter
    return diameter;
}

int main() {
    
    // Input the binary tree in level-order format
    vector<int> nodes;
    int value;
    cout << "Input: ";
    while (cin >> value) {
        nodes.push_back(value);
        if (cin.peek() == '\n') break;
    }

    // Build the tree
    TreeNode* root = buildTree(nodes);

    // Calculate and print the diameter
    int diameter = diameterOfBinaryTree(root);
    cout << "The diameter is: " << diameter << endl;

    return 0;
}
