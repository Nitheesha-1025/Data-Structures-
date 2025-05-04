#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> s(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    int max1 = INT_MIN, max2 = INT_MIN;

    // Find the two largest distinct values
    for (int i = 0; i < n; i++) {
        if (s[i] > max1) {
            max2 = max1;
            max1 = s[i];
        } else if (s[i] > max2 && s[i] < max1) {
            max2 = s[i];
        }
    }

    // If max2 remains INT_MIN, all elements are the same
    if (max2 == INT_MIN) max2 = max1;

    // Compute and print results
    for (int i = 0; i < n; i++) {
        if (s[i] == max1) {
            printf("%d ", s[i] - max2);
        } else {
            printf("%d ", s[i] - max1);
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    
    return 0;
}
