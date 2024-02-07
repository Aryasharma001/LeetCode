class Solution {
public:
    static bool comparePairs(const pair<int, char>& a, const pair<int, char>& b) {
        return a.first > b.first; // Sort in decreasing order of the first element
}
    string frequencySort(string s) {
        string ans = "";
        vector<int> hashvector(256, 0); 
        vector<pair<int,char>> hashMap;
        for (int i = 0; i < s.size(); i++) {
            hashvector[(int)(s[i])]++; 
        }
        for (int i = 0; i < hashvector.size(); i++) {
            if (hashvector[i] > 0) {
                hashMap.push_back({hashvector[i],(char)(i)});
            }
        }
        sort(hashMap.begin(),hashMap.end(),comparePairs);
        for (auto it : hashMap) {
            // cout<<it.first<<" "<<it.second<<endl;
            ans += string(it.first,it.second); 
        }


        return ans;
    }
};
