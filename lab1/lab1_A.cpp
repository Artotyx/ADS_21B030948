#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void arrangeDeck(int N) {
    if (N < 3) {
        cout << -1 << endl;
        return;
    }

    Node* head = new Node(1);
    Node* tail = head;
    for (int i = 2; i <= N; ++i) {
        Node* newNode = new Node(i);
        tail->next = newNode;
        tail = newNode;
    }

    Node* current = head;
    Node* prev = nullptr;
    int count = 1;

    while (current->next != nullptr) {
        if (count % 2 == 1) {
            if (prev != nullptr) {
                prev->next = current->next;
                cout << current->data << " ";
                delete current;
                current = prev->next;
            } else {
                cout << current->data << " ";
                Node* temp = current;
                current = current->next;
                head = current;
                delete temp;
            }
        } else {
            prev = current;
            current = current->next;
        }
        count++;
    }

    cout << current->data << endl;
    delete current;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;

        arrangeDeck(N);
    }

    return 0;
}



