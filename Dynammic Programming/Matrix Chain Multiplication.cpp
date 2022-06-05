#include<bits/stdc++.h>

int rec(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    if (i == j) return 0;

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = 1e9;
    for (int k = i; k < j; k++) {
        ans = min(ans, arr[i - 1] * arr[k] * arr[j] + rec(i, k, arr, dp) + rec(k + 1, j, arr, dp));
    }
    return dp[i][j] = ans;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return rec(1, N - 1, arr, dp);
}