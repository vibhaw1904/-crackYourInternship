class Solution {
private:
    bool valid(int mid,int h,vector<int> piles){
        int hours=0;
        for(int i=0;i<piles.size(a);i++){
            hours+=piles[i]/mid;
            piles[i]%=mid;
            if(piles[i]>0)hours++;
            if(hours>h)return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=0;
        int mid=s+(e-s)/2;

        int res=-1;
        for(int i=0;i<piles.size();i++){
            e=max(e,piles[i]);
        }
        while(s<=e){
            if(valid(mid,h,piles)){
                res=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return res;
    }
};