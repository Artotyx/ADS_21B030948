#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student {
    string lastname;
    string firstname;
    double totalGPA;
};

int main() {
    int n;
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        int m;
        cin >> students[i].lastname >> students[i].firstname >> m;

        double totalGPA = 0.0;
        int totalCredits = 0;

        for (int j = 0; j < m; j++) {
            int mark, credits;
            cin >> mark >> credits;
            totalGPA += mark * credits;
            totalCredits += credits;
        }

        if (totalCredits > 0) {
            students[i].totalGPA = totalGPA / totalCredits;
        } else {
            students[i].totalGPA = 0.0;
        }
    }

    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        if (a.totalGPA != b.totalGPA) {
            return a.totalGPA > b.totalGPA;
        } else if (a.lastname != b.lastname) {
            return a.lastname < b.lastname;
        } else {
            return a.firstname < b.firstname;
        }
    });

    for (const Student &student : students) {
        cout << student.lastname << " " << student.firstname << " " << fixed << setprecision(3) << student.totalGPA << endl;
    }

    return 0;
}
