#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


void  search(vector<int> &list, int index, int leftBrain, int rightBrain, int &minCost) {
    if (index == list.size()) {
        minCost = min(minCost, max(leftBrain, rightBrain));
        return;
    }
    leftBrain += list[index];
    search(list, index + 1, leftBrain, rightBrain, minCost);
    leftBrain -= list[index];
    rightBrain += list[index];
    search(list, index + 1, leftBrain, rightBrain, minCost);
    rightBrain -= list[index];
}
int main() {
    int ss[4];
    cin >> ss[0] >> ss[1] >> ss[2] >> ss[3];
    int finalCost = 0;
    for (int num: ss) {
        int minCost = INT32_MAX;
        vector<int> questions;
        while (num--) {
            int time;
            cin >> time;
            questions.push_back(time);
        }
        unordered_set<int> visited;
        search(questions, 0, 0, 0, minCost);
        finalCost += minCost;
    }
    cout << finalCost;
    return 0;  
}