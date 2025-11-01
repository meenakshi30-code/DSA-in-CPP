#include <bits/stdc++.h>
using namespace std;

void fillPrimes(vector<int>& prime, int high)
{
    vector<bool> ck(high+1, true);
    ck[0] = false;
    ck[1] = false;

    for (int i = 2; (i * i) <= high; i++) {
        if (ck[i] == true) {
            for (int j = i * i; j <= high; j = j + i) {
                ck[j] = false;
            }
        }
    }

    for (int i = 2; i <= high; i++) {
        if (ck[i] == true) {
            prime.push_back(i);
        }
    }
}

void segmentedSieve(int low, int high)
{
    if (low < 2 && high >= 2){
        low = 2;
    }

    vector<bool> prime(high - low + 1, true);
    vector<int> chprime;
    fillPrimes(chprime, sqrt(high));

    for (int i : chprime) {
        int base = (low / i) * i;
        if (base < i * 2) base = i * 2;
        if (base < low) base += i;

        for (int j = base; j <= high; j += i) {
            prime[j - low] = false;
        }
    }

    for (int i = low; i <= high; i++) {
        if (prime[i - low] == true) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int low, high;
    cout << "Enter low: ";
    cin >> low;
    cout << "Enter high: ";
    cin >> high;

    segmentedSieve(low, high);
  return 0;
}
