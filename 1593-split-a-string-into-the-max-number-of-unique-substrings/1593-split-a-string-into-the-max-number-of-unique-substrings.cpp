class Solution {
public:
    int maxUniqueSplit(string s) {
        return backtrack(s, 0, {});
    }
    
    int backtrack(const string& s, int start, set<string> used) {
        if (start == s.size()) return used.size();
        
        int maxSplit = 0;
        string current = "";
        
        for (int i = start; i < s.size(); i++) {
            current += s[i];
            if (used.find(current) == used.end()) {
                used.insert(current);
                maxSplit = max(maxSplit, backtrack(s, i + 1, used));
                used.erase(current); // Backtrack
            }
        }
        
        return maxSplit;
    }
};
