//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends

class Solution{
    private:
    int getRandom(int l, int r){
        srand(time(0));
        return l + (rand() % (r - l + 1));
    }
    
    int partition (int a[], int low, int high){
        int randomidx = getRandom(low, high);
        swap(a[randomidx], a[high]);
        int j = low - 1, pivot = a[high];
        for(int i = low; i <= high - 1; i++){
            if(a[i] <= pivot){
                j++;
                swap(a[i], a[j]);
            }
        }
        swap(a[j + 1], a[high]);
        return j + 1;
    }
    
    public:
    void quickSort(int a[], int low, int high){
        if(low >= high)
            return;
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
};
        



//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends