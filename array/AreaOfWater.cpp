class Solution {
public:
    int maxArea(vector<int>& height) {
      int ans; 
      int res=INT_MIN;
      int j=height.size()-1;
      int i=0;
      while(i<=j){
        if(height[i]<height[j]){
            ans=height[i]*(j-i);
            res=max(ans,res);
            i++;
        }
        else{
            ans=height[j]*(j-i);
            res=max(res,ans);
            j--;
        }
      }
      return res;
    }
};