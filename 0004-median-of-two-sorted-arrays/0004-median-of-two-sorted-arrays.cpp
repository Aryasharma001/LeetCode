class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        double pro;
        for(auto it:nums1)
            ans.push_back(it);
        for(auto it:nums2)
            ans.push_back(it);
        sort(ans.begin(),ans.end());
        int n=ans.size();
        if(n%2==0){
            pro=(ans[n/2-1]+ans[n/2]);
            pro=(double(pro))/2.0;
        }
        else
            pro=ans[((n+1)/2)-1];
        return pro;
            
        
    }
};