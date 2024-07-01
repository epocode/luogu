#include <iostream>
#include <algorithm>
using namespace std;

struct Stu {
    int id;
    string name;
    int year;
    int month;
    int day;
} arr[110];

bool cmp(const Stu a, const Stu b) {
    if (a.year != b.year) {
        return a.year < b.year;
    } else if (a.month != b.month) {
        return a.month < b.month;
    } else if (a.day != b.day) {
        return a.day < b.day;
    } else {
        return a.id > b.id;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].name >> arr[i].year >> arr[i].month >> arr[i].day;
        arr[i].id = i;
    }
    sort(arr + 1, arr + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << arr[i].name << endl;
    }
    return 0;
}