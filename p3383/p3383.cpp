#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int prime[100000010];
bool isPrime[100000010];
int cnt;
void genPrime(int n)
{
    isPrime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            prime[++cnt] = i;
        }
        for (int j = 1; i * prime[j] <= n; j++)
        {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        isPrime[i] = true;
    }
    genPrime(n);
    while (q--) {
        int input;
        cin >> input;
        cout << prime[input] << endl;
    }
    return 0;
}