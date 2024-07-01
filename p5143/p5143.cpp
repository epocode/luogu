#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    int x;
    int y;
    int z;
}arr[50010];

double calcDis(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

bool cmp(const Point a, const Point b) {
    return a.z < b.z;
}
int main() {
    int N;
    cin >> N;
    double totalDis = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }
    sort(arr + 1, arr + N + 1, cmp);
    for (int i = 2 ; i <= N; i++) {
        totalDis += calcDis(arr[i - 1], arr[i]);
    }
    printf("%.3lf", totalDis);
    return 0;
}