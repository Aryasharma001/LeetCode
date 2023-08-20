class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = s.size() - 1;
        int ans = 0;
        
        vector<int> hash(256, -1); // Initialize hash with -1
        
        for (int i = 0; i <= end; i++) {
            if (hash[s[i]] != -1) {
                start = max(start, hash[s[i]] + 1);
            }
            
            ans = max(ans, i - start + 1);
            hash[s[i]] = i; // Store the index of the character
        }
        
        return ans;
    }
};

