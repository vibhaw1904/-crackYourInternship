class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isValid(int pg[],int n,int m,int mid){
        int pageSum=0;
        int count=1;
        for(int i=0;i<n;i++){
            pageSum+=pg[i];
            if(pageSum>mid){
                 count++;
             if(count>m||pg[i]>mid)return false;
                pageSum=pg[i];
            }
        }
      
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        int s=1;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        int e=sum;
        int res=-1;
        if(M>N)return res;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isValid(A,N,M,mid)){
                res=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return res;
    }
};