class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        long long c = 0;
        int l = 0, r = n-1;
        int l_max = 0,r_max = 0;
        
        while(l<=r){
            if(height[l] <= height[r]){
                if(height[l]>=l_max) l_max = height[l];
                else c += l_max - height[l];
                
                l++;
            }
            else{
                if(height[r] >= r_max) r_max = height[r];
                else c += r_max - height[r];
                
                r--;
            }
        }
        return c;
    }
    
};