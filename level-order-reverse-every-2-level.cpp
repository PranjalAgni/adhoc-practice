#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node* left;
    int data;
    struct Node* right;
};



Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void modifiedLevelOrder(Node* root) {
    vector<vector<int>> answer;
    deque<Node*> dq;
    dq.push_back(root);

    int count = 0;
    bool leftToRight = true;

    while (!dq.empty()) {
        int N = dq.size();
        vector<int> level;
        for (int idx = 0; idx < N; idx++) {

            Node* curr = NULL;
            if (leftToRight) {
                curr = dq.front();
                dq.pop_front();
            } else {
                curr = dq.back();
                dq.pop_back();
            }

            level.push_back(curr->data);

            if (leftToRight) {
                if (curr->left) dq.push_back(curr->left);
                if (curr->right) dq.push_back(curr->right);
            } else {
                if (curr->right) dq.push_front(curr->right);
                if (curr->left) dq.push_front(curr->left);
            }

        }

        count += 1;
        if (count == 2) {
            leftToRight = !leftToRight;
            count = 0;
        }
        answer.push_back(level);
    }

    for (vector<int> level : answer) {
        for (int vertex : level) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(2);
    root->left->right->left->left = newNode(16);
    root->left->right->left->right = newNode(17);
    root->right->left->right->left = newNode(18);
    root->right->right->left->right = newNode(19);

    modifiedLevelOrder(root);

    return 0;
}