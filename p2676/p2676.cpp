#include <iostream>
#include <queue>
using namespace std;

int arr[20010];
class MaxHeap {
    public:
    int size;
    MaxHeap() {
        size = 0;
    }
    void push(int x) {
        arr[size++] = x;
        int index = size - 1;
        heapUp(index);
    }
    int top() {
        return arr[0];
    }
    void pop() {
        arr[0] = arr[size - 1];
        size--;
        heapDown(0);
    }
    bool empty() {
        return size == 0 ? true : false;
    }
    int leftChild(int x) {
        return 2 * x + 1;
    }
    int rightChild(int x) {
        return 2 * x + 2;
    }
    int parent(int x) {
        return (x - 1) / 2;
    }
    void heapDown(int x) {
        int max = x;
        while (x < size) {
            int left = leftChild(x);
            int right = rightChild(x);
            if (left < size && arr[left] > arr[max]) {
                max = left;
            }
            if (right < size && arr[right] > arr[max]) {
                max = right;
            }
            if (max == x) {
                break;
            }
            swap(arr[x], arr[max]);
            x = max;
        }
    }
    void heapUp(int x) {
        int p = parent(x);
        while (x > 0 && arr[x] > arr[p]) {
            swap(arr[x], arr[p]);
            x = p;
            p = parent(x);
        }
    }
};

int main() {
    int N;
    long long B;
    cin >> N >> B;
    MaxHeap pq;
    for (int i = 1; i <= N; i++) {
        int h;
        cin >> h;
        pq.push(h);
    }
    long long h = 0;
    int count = 0;
    while (!pq.empty() && h < B) {
        h += pq.top();
        pq.pop();
        count++;
    }
    cout << count;
    return 0;
}