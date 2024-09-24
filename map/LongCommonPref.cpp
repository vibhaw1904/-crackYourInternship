class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp;
        for(int num:arr1){
            string strNum1=to_string(num);
            string pref="";
            for(char ch:strNum1){
                pref+=ch;
                mp[pref]++;
            }
        }
        int length=0;
        for(int num:arr2){
            string strNum2=to_string(num);
            string pref="";
            for(char ch:strNum2){
                pref+=ch;
                if(mp.find(pref)!=mp.end()){
                    length=max(length,static_cast<int>(pref.length()));
                }
            }
        }
        return length;
    }
};