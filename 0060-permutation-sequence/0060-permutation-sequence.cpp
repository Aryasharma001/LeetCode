class Solution {
public:

    string getPermutation(int n, int k) {
        set<vector<int>>s;
        vector<int>temp;
        for(int i=1;i<=n;i++){
            temp.push_back(i);
        }
        s.insert(temp);
        for(int i=0;i<k-1;i++){
            next_permutation(temp.begin(),temp.end());
       }
        string wa="";
        for(auto it:temp){
            wa+=to_string(it);
        }
        return wa;
    }
};