#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[25];
bool cmp(string a, string b)
{
    return a + b > b + a;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i];
    }
    return 0;
}