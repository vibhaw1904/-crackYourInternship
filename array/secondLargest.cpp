 int print2largest(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        if(arr[0]==arr[n-1]){
            return -1;
            
        }
        else{
           for(int i=n-1;i>=1;i--){
               if(arr[i]!=arr[i-1]){
                   return arr[i-1];
               }
               else{
                   continue;
               }
           } 
        }
    }