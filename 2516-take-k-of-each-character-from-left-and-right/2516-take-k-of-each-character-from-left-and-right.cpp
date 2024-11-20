class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();

        // If not enough characters to satisfy k of each, return -1
        vector<int> total(3, 0);
        for (char c : s) total[c - 'a']++;
        if (total[0] < k || total[1] < k || total[2] < k) return -1;

        // Sliding window to find the longest valid subarray we can skip
        vector<int> freq(3, 0);
        int max_window = 0, left = 0;

        for (int right = 0; right < n; ++right) {
            freq[s[right] - 'a']++;
            
            // Shrink the window if we can't skip this subarray
            while (freq[0] > total[0] - k || freq[1] > total[1] - k || freq[2] > total[2] - k) {
                freq[s[left] - 'a']--;
                left++;
            }

            // Update the maximum window size
            max_window = max(max_window, right - left + 1);
        }

        // Minimum minutes = Total string size - Largest skippable window
        return n - max_window;
    }
};
