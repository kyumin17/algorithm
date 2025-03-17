#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int arr[MAX];
int dp[MAX];

int lis(int n) {
    dp[0] = arr[0];
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > dp[idx]) {
            dp[++idx] = arr[i];
        } else {
            dp[lower_bound(dp, dp+(idx+1), arr[i]) - dp] = arr[i];
        }
    }

    return ++idx;
}