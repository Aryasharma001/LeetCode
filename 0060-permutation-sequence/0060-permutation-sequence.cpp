#include <iostream>
#include <vector>

class Solution {
public:
    int fact(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f = f * i;
        return f;
    }

    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        string result = "";
        k = k - 1; // Convert to 0-based index

        while (n > 0) {
            int index = k / fact(n - 1);
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k = k % fact(n - 1);
            n--;
        }

        return result;
    }
};