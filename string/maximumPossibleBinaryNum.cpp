class Solution {
    string binary(int n){
        string res="";
        while(n){
            res+='0'+n%2;
            n=n/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    int decimal(string s){
        int res=0;
        for(int i=0;i<s.length();i++){
            res=res*2+(s[i]-'0');
        }
        return res;
    }
public:
    int maxGoodNumber(vector<int>& nums) {
        string a=binary(nums[0]);
        string b=binary(nums[1]);
        string c=binary(nums[2]);
        return max({ decimal(a+b+c),
          decimal(a+c+b),
          decimal(b+a+c),
          decimal(b+c+a),
          decimal(c+a+b),
          decimal(c+b+a)});
    }
};