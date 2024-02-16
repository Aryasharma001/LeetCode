class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        multiset<int> uniqueCounts;
        for (auto& entry : freq) {
            uniqueCounts.insert(entry.second);
        }
        
        int numUnique = freq.size();
        for (auto it = uniqueCounts.begin(); it != uniqueCounts.end(); ++it) {
            if (k >= *it) {
                k -= *it;
                numUnique--;
            } else {
                break;
            }
        }
        
        return numUnique;
    }
};