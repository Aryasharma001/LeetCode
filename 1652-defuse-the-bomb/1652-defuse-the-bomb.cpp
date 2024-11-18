class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>r(n);
        k=k%n;
        if(k<0){
            for(int i=0;i<n;i++){
                int sum=0;
                for(int j=1;j<=abs(k);j++){
                    sum+=code[(i-j+n)%n];
                }
                r[i]=sum;
            }
        }else{
            for(int i=0;i<n;i++){
                int sum=0;
                for(int j=1;j<=k;j++){
                    sum+=code[(i+j)%n];
                }
                r[i]=sum;
            }
            
        }
        return r;
    }
};