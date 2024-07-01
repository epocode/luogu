#include <iostream>
#include <algorithm>
using namespace std;
struct Grade{
    int id;
    int chinese;
    int math;
    int en;
    int sum;
} grades[310];

bool cmp(const Grade a, const Grade b) {
    if (a.sum != b.sum) {
        return a.sum > b.sum;
    } else if (a.chinese != b.chinese) {
        return a.chinese > b.chinese;
    } else {
        return a.id < b.id;
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> grades[i].chinese >> grades[i].math >> grades[i].en;
        grades[i].id = i;
        grades[i].sum = grades[i].chinese + grades[i].math + grades[i].en;
    }
    sort(grades + 1, grades + n + 1, cmp);
    for (int i = 1; i <= 5; i++) {
        cout << grades[i].id << " " << grades[i].sum << endl;
    }
    return 0;
}