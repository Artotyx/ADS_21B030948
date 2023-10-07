#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* insert(Node* head, int x) {
    Node* newNode = new Node(x);
    if (head == nullptr) {
        return newNode;
    }
    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = newNode;
    return head;
}

void findMode(Node* head) {
    Node* current = head;
    int maxCount = 1;
    
    while (current != nullptr) {
        Node* runner = current;
        int currentCount = 0;

        while (runner != nullptr) {
            if (runner->val == current->val) {
                currentCount++;
            }
            runner = runner->next;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
        }

        current = current->next;
    }

    current = head;
    vector<int> modes;
    
    while (current != nullptr) {
        Node* runner = current;
        int currentCount = 0;
        
        while (runner != nullptr) {
            if (runner->val == current->val) {
                currentCount++;
            }
            runner = runner->next;
        }

        if (currentCount == maxCount) {
            modes.push_back(current->val);
        }

        current = current->next;
    }

    sort(modes.rbegin(), modes.rend());

    for (int mode : modes) {
        cout << mode << " ";
    }
}

int main() {
    Node* head = nullptr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insert(head, x);
    }

    findMode(head);

    Node* cur = head;
    while (cur != nullptr) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    return 0;
}