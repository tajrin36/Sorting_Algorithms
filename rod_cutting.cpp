#include <iostream>
#include <climits>
using namespace std;

int rodCutting(int price[], int n) {
    int val[n + 1];
    val[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, price[j] + val[i - j - 1]);
        }
        val[i] = max_val;
    }

    return val[n];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);

    cout << "Maximum obtainable value by cutting the rod: " << rodCutting(price, n) << endl;

    return 0;
}
