#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    void primeSieve(const std::vector<int>& nums, std::vector<bool>& prime) {
        int n = *max_element(nums.begin(), nums.end());
        prime.resize(n + 1, true);  // Resize to n + 1 and initialize all as true
        prime[0] = prime[1] = false;  // 0 and 1 are not prime

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }
    }

    bool primeSubOperation(std::vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        std::vector<bool> prime;
        primeSieve(nums, prime);  // Generate prime sieve up to max(nums)

        for (int i = 0; i < nums.size(); i++) {
            int sub = 0;

            // Loop to find the largest prime j to subtract, ensuring (nums[i] - j) > nums[i - 1]
            for (int j = nums[i] - 1; j >= 2; j--) {
                if (prime[j] && (i == 0 || (nums[i] - j) > nums[i - 1])) {
                    sub = j;
                    break;
                }
            }

            nums[i] -= sub;
            std::cout << nums[i] << " ";
        }

        std::cout << std::endl;

        // Check if nums is strictly increasing
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1])
                return false;
        }

        return true;
    }
};
