class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n=v.size();
        set<int> s;
        for(auto i:v)
            s.insert(i);
        for(int i=1;i<=100001;i++) {
            if(s.find(i)==s.end())
                return i;
        }
        return 0;
    }
};