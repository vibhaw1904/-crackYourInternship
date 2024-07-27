//recursive code for KnapSack

int knapSack(vector<int>&wt,vector<int>&val,int W,int n){
    if(n==0||w==0){
        return 0;

    }
    if(wt[n-1]<=W){
        return max(wt[n-1]+knapSack(wt,val,W-wt[n-1],n-1),knapSack(wt,val,W,n-1));
    }
    else if(wt[n-1]>W){
        return knapSack(wt,val,W,n-1);
    }

}