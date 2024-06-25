#include <iostream>
#include <queue>
using namespace std;

class MinHeap
{
public:
    int size = 0;
    int* list;
    MinHeap() {
        size = 0;
        list = new int[(int)1e6 + 1];
    }
    ~MinHeap() {
        delete[] list;
    }
    int leftChild(int pos)
    {
        int left = 2 * pos + 1;
        return left >= size ? -1 : left;
    }
    int rightChild(int pos)
    {
        int right = 2 * pos + 2;
        return right >= size ? -1 : right;
    }
    int getParent(int pos)
    {
        return (pos - 1) / 2;
    }
    void push(int value)
    {
        size++;
        list[size - 1] = value;
        adjustDown2Top(size - 1);
    }
    void adjustTop2Down(int pos)
    {
        int left = leftChild(pos);
        int right = rightChild(pos);
        int min = pos;
        while (left != -1)
        {
            if (list[min] > list[left])
            {
                min = left;
            }
            if (right != -1 && list[min] > list[right])
            {
                min = right;
            }
            if (min == pos) {
                break;
            }
            swap(list[min], list[pos]);
            pos = min;
            left = leftChild(pos);
            right = rightChild(pos);
        }
    }
    void adjustDown2Top(int pos)
    {
        int parent = getParent(pos);
        while (pos != 0 && list[parent] > list[pos])
        {
            swap(list[pos], list[parent]);
            pos = parent;
            parent = getParent(pos);
        }
    }
    void pop()
    {
        swap(list[0], list[size - 1]);
        size--;
        adjustTop2Down(0);
    }
    int top()
    {
        return list[0];
    }
    
};

int minHeapByHand()
{
    int n;
    cin >> n;

    MinHeap minHeap = MinHeap();
    for (int i = 0; i < n; ++i)
    {
        int operation;

        cin >> operation;
        switch (operation)
        {
        case 1:
            int input;
            cin >> input;
            minHeap.push(input);
            break;
        case 2:
            if (minHeap.size > 0)
            {
                cout << minHeap.top() << endl;
            }

            break;
        case 3:
            if (minHeap.size > 0)
            {
                minHeap.pop();
            }

            break;
        }
    }
    return 0;
}

int main( ) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int operation;
        cin >> operation;
        switch (operation)
        {
        case 1:
            int input;
            cin >> input;
            minHeap.push(input);
            break;
        case 2:

                cout << minHeap.top() << endl;

            break;
        case 3:
                minHeap.pop();

            break;
        }
    }
    return 0;
}