//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int uneatenLeaves(int arr[],int n,int k);


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
         
        int n;
        cin>>n;
        int k;
        cin>>k;
        int arr[k];
        for(int i=0;i<k;i++)
        cin>>arr[i];
        cout<<uneatenLeaves(arr,n,k)<<endl;
    }
 }
    
        
// } Driver Code Ends


int uneatenLeaves(int arr[],int n,int k)
{
    // Your code goes here
    set<int>s;
    int hsh[n]={0};
    for(int i=0;i<k;i++){
        if(arr[i]==1) return 0;
        for(int j=arr[i];j<=n;j=j+arr[i]){
            hsh[j-1]++;
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(hsh[i]==0)
            count++;
    }

    return count;
}
