class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        vector<int>hsh1(1001,0);
        vector<int>hsh2(1001,0);
        for(int i=0;i<nums1.size();i++)
            hsh1[nums1[i]]++;
        for(int j=0;j<nums2.size();j++)
            hsh2[nums2[j]]++;
        for(int i=0;i<1001;i++){
            if(hsh1[i]>0 && hsh2[i]>0){
                for(int j=0;j<min(hsh1[i],hsh2[i]);j++)
                ans.push_back(i);
            }
        }
        return ans;
    }
};