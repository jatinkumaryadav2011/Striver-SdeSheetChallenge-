#include<bits/stdc++.h>

bool palindrome(string &s) {
    int i = 0, j = s.size() - 1;
    while (j >= i) {
        if (s[j] != s[i]) return false;
        i++;
        j--;
    }
    return true;
}
int palindromePartitioning(string s) {
    int n = s.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int ans = INT_MAX;
        string temp = "";
        for (int j = i; j < s.size(); j++) {
            temp += s[j];
            if (palindrome(temp)) {
                int cnt = 1 + dp[j + 1];
                ans = min(ans, cnt);
            }
        }
        dp[i] = ans;
    }

    return dp[0] - 1;
}
