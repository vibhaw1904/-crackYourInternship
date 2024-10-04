class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int size=skill.size();
        sort(skill.begin(),skill.end());
        int high=size-1;
        int low=0;
        long long ans=0;
        int chem=skill[low]+skill[high];
        while(low<high){
           int chem1=skill[low]+skill[high];
            if(chem!=chem1)return -1;
            ans+=(long long)skill[low]*skill[high];
            low++;
            high--;
        }
        return ans;
    }
};