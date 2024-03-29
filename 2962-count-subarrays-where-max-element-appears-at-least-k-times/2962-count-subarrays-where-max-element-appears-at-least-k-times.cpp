class Solution {
public:
    long long countSubarrays(vector<int>& v, int k) {
        map<int,int>m;
        int n=v.size();
        int a=0;
        for(auto i:v)
            a=max(a,i);
        int i=0,j=0;
        long long ans=0;
        while(j<n)
        {
            m[v[j]]++;
            while(m[a]>=k) {
                ans=ans+n-j;
                m[v[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};