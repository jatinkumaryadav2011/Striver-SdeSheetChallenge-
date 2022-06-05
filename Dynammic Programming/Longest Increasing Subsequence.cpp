#include<bits/stdc++.h>

int longestIncreasingSubsequence(int nums[], int n)
{
    vector<int> temp;
    temp.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (temp.back() < nums[i]) {
            temp.push_back(nums[i]);
        } else {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }

    return temp.size();
}

