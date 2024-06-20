#include <iostream>
#include <stdlib.h>
#include <unordered_map>

using namespace std;
#define SIZE 100001
int main()
{
    unordered_map<int, int> bags[SIZE]; 
    int n, q;
    cin >> n >> q;
    int operate, bagIndex, gridIndex, data;
    while (q--)
    {
        cin >> operate >> bagIndex >> gridIndex;
        if (operate == 1)
        {
            cin >> data;
            if (data == 0) {
                bags[bagIndex].erase(gridIndex);
            } else {
                bags[bagIndex][gridIndex] = data;
            }
        } else {
            int res = bags[bagIndex][gridIndex];
            cout << res << endl;
        }
    }
    return 0;
}