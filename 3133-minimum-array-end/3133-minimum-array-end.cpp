#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        // Start with the initial value as `x`
        long long last = x;

        // Iterate n-1 times to find the minimum `nums[n - 1]`
        for (int i = 1; i < n; i++) {
            // Increment last to make sure it's greater than the previous value
            last++;
            
            // Use OR with x to maintain the AND condition on all bits of x
            last |= x;
        }

        // `last` now represents the minimum value of `nums[n - 1]`
        return last;
    }
};
