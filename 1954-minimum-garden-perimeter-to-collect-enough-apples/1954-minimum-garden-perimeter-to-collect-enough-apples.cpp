class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long apples=0;
        long long n=0;
        while(apples<neededApples){
            apples+=12*n*n;
            n++;
        }
        return 8*(n-1);
}

    
};