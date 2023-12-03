#include <iostream>
#include <vector>

using namespace std;

struct Operation {
    int value;
    int operationType;
};

void printOperations(const vector<Operation>& operations) {
    cout << operations.size() << endl;
    for (size_t i = 0; i < operations.size(); ++i) {
        cout << operations[i].value;
        if (i < operations.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void minOperations(int A, int B) {
    vector<Operation> operations;

    while (A != B) {
        if (A < B) {
            if (B % 2 == 0) {
                B /= 2;
                Operation op;
                op.value = B;
                op.operationType = 0;
                operations.push_back(op);
            } else {
                B++;
                Operation op;
                op.value = B;
                op.operationType = 1;
                operations.push_back(op);
            }
        } else {
            A--;
            Operation op;
            op.value = A;
            op.operationType = 1;
            operations.push_back(op);
        }
    }

    printOperations(operations);
}

int main() {
    int A, B;
    cin >> A >> B;

    minOperations(A, B);

    return 0;
}
