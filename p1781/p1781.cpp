#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct President {
    int id;
    string ticket;
}list[21];

bool cmp(const President a, const President b) {
    bool res;
    if (a.ticket.length() != b.ticket.length()) {
        res =  a.ticket.length() > b.ticket.length();
    } else {
        for (int i = 0; i < a.ticket.length(); i++) {
            if (a.ticket[i] == b.ticket[i]) {
                continue;
            } 
            res = a.ticket[i] > b.ticket[i];
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> list[i].ticket;
        list[i].id = i;
    }
    sort(list + 1, list + n + 1, cmp);
    cout << list[1].id << endl;
    cout << list[1].ticket;
    return 0;
}