#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

vector<int> getNext(string str)
{
    int len = str.length();
    vector<int> next(len);
    next[0] = 0;
    next[1] = 0;
    int i = 0;
    for (int j = 1; j < len;)
    {
        while (str[i] != str[j] && i != 0)
        {
            i = next[i - 1];
        }
        if (str[i] == str[j]) {
            next[j] = i + 1;
            j++;
            i++;
        } else {
            next[j] = 0;
            j++;
        }
    }
    return next;
}

int addOne(int input)
{
    return input + 1;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> next = getNext(s2);
    int mainIndex = 0;
    int matchIndex = 0;
    while (mainIndex < s1.length())
    {
        while (s1[mainIndex] != s2[matchIndex] && matchIndex != 0) {
            matchIndex = next[matchIndex - 1];
        }
        if (s1[mainIndex] == s2[matchIndex]) {
            if (matchIndex == s2.length() -1 ) {
                cout << addOne(mainIndex - s2.length() + 1) << endl;
                matchIndex = next[matchIndex];
                mainIndex++;
            } else {
                matchIndex++;
                mainIndex++;
            }
        } else {
            mainIndex++;
        }
    }
    for (int length : next)
    {
        cout << length << " ";
    }
    return 0;
}