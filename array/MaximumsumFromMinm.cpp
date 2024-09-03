 int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int n=arr.size()-1;
        int i=0;
        int j=1;
        int maxi=INT_MIN;
        while(j<=n){
           maxi=max(maxi,arr[i]+arr[j]);
           i++;
           j++;
        }
        return maxi;
    }