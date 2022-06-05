#include <bits/stdc++.h>
int rec(int i, int j, vector<vector<int>> &dp) {
    if (i == 1 && j == 1) {
        return 1;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int up = 0, left = 0;
    if (i - 1 >= 0) up = rec(i - 1, j, dp);
    if (j - 1 >= 0) left = rec(i, j - 1, dp);

    return dp[i][j] = up + left;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return rec(m, n, dp);
}