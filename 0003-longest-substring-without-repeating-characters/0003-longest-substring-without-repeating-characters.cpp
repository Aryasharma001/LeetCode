class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        // maxLen will calculate the length of the substring
        //start is the index from where our substring with no repeated chars is started
        int maxLen = 0, start = -1;

        for(int i = 0; i < s.size(); i++){
            // if the element is already visited then mark the index because our new substring with no repeated chars will start from that index
            // here we did not use dict[s[i]] != -1 because once we update the start to some value let say 5, we can consider the chars that were repeated before 5 so we use dict > start 
            if(dict[s[i]] > start){
                start = dict[s[i]];
            }
            // update the dict array with the position where the char is found
            dict[s[i]] = i;
            // Keep calculating the maxLen
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};