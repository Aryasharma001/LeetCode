class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size()==0)
            left.push_back(0);
        if(right.size()==0)
            right.push_back(n);
        return max(*max_element(left.begin(),left.end()),(n-*min_element(right.begin(),right.end())));
        
    }
};