class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long s=0;
        long long e=n;
        long long ans=0;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(mid*mid==n){
                return mid;
            }
            else if (mid*mid>n){
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
    }
};