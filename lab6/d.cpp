#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>  // Include for setw

using namespace std;

struct Date {
    int day, month, year;
};

bool compareDates(const Date &date1, const Date &date2) {
    if (date1.year != date2.year)
        return date1.year < date2.year;
    if (date1.month != date2.month)
        return date1.month < date2.month;
    return date1.day < date2.day;
}

int main() {
    int n;
    cin >> n;

    vector<Date> dates(n);

    for (int i = 0; i < n; i++) {
        char dash;
        cin >> setw(2) >> dates[i].day >> dash >> setw(2) >> dates[i].month >> dash >> dates[i].year;
    }

    sort(dates.begin(), dates.end(), compareDates);

    for (int i = 0; i < n; i++) {
        cout << setfill('0') << setw(2) << dates[i].day << "-" << setw(2) << dates[i].month << "-" << dates[i].year << endl;
    }

    return 0;
}

