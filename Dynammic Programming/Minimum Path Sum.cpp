#include<bits/stdc++.h>

int dp[205][205];

int minPath(int i, int j, vector<vector<int>>& grid) {
    if (i == 0 && j == 0) {
        return grid[i][j];
    }

    if (dp[i][j] != -1) return dp[i][j];

    int ans1 = INT_MAX, ans2 = INT_MAX;

    if (i - 1 >= 0) ans1 = minPath(i - 1, j, grid) + grid[i][j];
    if (j - 1 >= 0) ans2 = minPath(i, j - 1, grid) + grid[i][j];

    return dp[i][j] = min(ans1, ans2);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    memset(dp, -1, sizeof(dp));
    return minPath(n - 1, m - 1, grid);
}