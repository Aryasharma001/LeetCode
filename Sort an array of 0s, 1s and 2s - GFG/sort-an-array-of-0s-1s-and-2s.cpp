//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    private:
        void swap(int nums[], int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
    }
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int mid=0,low=0,high=n-1;
        while(mid<=high){
            if(a[mid]==2){
                swap(a,mid,high);
                high--;
            }
            else if(a[mid]==0){
                swap(a,low,mid);
                low++;
                mid++;
            }
            else if(a[mid]==1)
                mid++;
        }
            
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends