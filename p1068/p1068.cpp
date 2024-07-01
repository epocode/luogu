#include <iostream>
#include <algorithm>
using namespace std;

struct Participant {
    int id;
    int score;
} list[5010];

bool cmp(const Participant a, const Participant b) {
    if (a.score != b.score) {
        return a.score > b.score;
    } else {
        return a.id < b.id;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int rank = m * 1.5;
    for (int i = 1; i <= n; i++) {
        cin >> list[i].id >> list[i].score;
    }
    sort(list + 1, list + n + 1, cmp);
    int limitScore = list[rank].score;
    cout << limitScore << " ";
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (list[i].score >= limitScore) {
            count++;
        } else {
            break;
        }
    }
    cout << count << endl;
    for (int i = 1; count; i++, count--) {
        cout << list[i].id << " " << list[i].score << endl;
    }
    return 0;
}