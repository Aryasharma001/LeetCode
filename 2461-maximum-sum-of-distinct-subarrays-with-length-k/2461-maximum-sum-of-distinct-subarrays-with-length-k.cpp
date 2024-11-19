// two main conditions:
//1. length of subarray is k
//2. all the elements of subarray are unique
// can't sort (array is not sorted priorly)


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash; 
        long long sum = 0;           
        long long ans = 0;           
        int start_i = 0;            

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;         
            sum += nums[i];        

            // Shrink the window if it exceeds size k
            if (i - start_i + 1 > k) {
                hash[nums[start_i]]--; 
                if (hash[nums[start_i]] == 0) {
                    hash.erase(nums[start_i]); 
                }
                sum -= nums[start_i];        
                start_i++;                    
            }

            
            if (i - start_i + 1 == k && hash.size() == k) {
                ans = max(ans, sum); 
            }
        }

        return ans;
    }
};
