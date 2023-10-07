#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int x, int p) {
        Node* newNode = new Node(x);
        if (p == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* curr = head;
            for (int i = 0; i < p - 1; ++i) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    void remove(int p) {
        if (p == 0) {
            if (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        } else {
            Node* curr = head;
            for (int i = 0; i < p - 1; ++i) {
                curr = curr->next;
            }
            if (curr->next) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
        }
    }

    void print() {
        if (!head) {
            cout << -1 << endl;
        } else {
            Node* curr = head;
            while (curr) {
                cout << curr->value << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }

    void replace(int p1, int p2) {
        if (p1 == p2) {
            return;
        }
        if (p1 == 0) {
            Node* node1 = head;
            head = head->next;
            node1->next = nullptr;
            if (p2 == 0) {
                node1->next = head;
                head = node1;
            } else {
                Node* curr = head;
                for (int i = 0; i < p2 - 1; ++i) {
                    curr = curr->next;
                }
                node1->next = curr->next;
                curr->next = node1;
            }
        } else {
            Node* curr1 = head;
            for (int i = 0; i < p1 - 1; ++i) {
                curr1 = curr1->next;
            }
            Node* node1 = curr1->next;
            curr1->next = curr1->next->next;
            node1->next = nullptr;
            if (p2 == 0) {
                node1->next = head;
                head = node1;
            } else {
                Node* curr2 = head;
                for (int i = 0; i < p2 - 1; ++i) {
                    curr2 = curr2->next;
                }
                node1->next = curr2->next;
                curr2->next = node1;
            }
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    void cyclic_left(int x) {
        if (!head) {
            return;
        }
        x = x % length();
        if (x == 0) {
            return;
        }
        Node* curr = head;
        for (int i = 0; i < x - 1; ++i) {
            curr = curr->next;
        }
        Node* newHead = curr->next;
        curr->next = nullptr;
        Node* temp = newHead;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head;
        head = newHead;
    }

    void cyclic_right(int x) {
        if (!head) {
            return;
        }
        x = x % length();
        if (x == 0) {
            return;
        }
        int count = length() - x - 1;
        Node* curr = head;
        for (int i = 0; i < count; ++i) {
            curr = curr->next;
        }
        Node* newHead = curr->next;
        curr->next = nullptr;
        Node* temp = newHead;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head;
        head = newHead;
    }

private:
    int length() {
        int len = 0;
        Node* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        return len;
    }
};

int main() {
    LinkedList linkedList;

    while (true) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            break;
        } else if (cmd == 1) {
            int x, p;
            cin >> x >> p;
            linkedList.insert(x, p);
        } else if (cmd == 2) {
            int p;
            cin >> p;
            linkedList.remove(p);
        } else if (cmd == 3) {
            linkedList.print();
        } else if (cmd == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            linkedList.replace(p1, p2);
        } else if (cmd == 5) {
            linkedList.reverse();
        } else if (cmd == 6) {
            int x;
            cin >> x;
            linkedList.cyclic_left(x);
        } else if (cmd == 7) {
            int x;
            cin >> x;
            linkedList.cyclic_right(x);
        }
    }

    return 0;
}