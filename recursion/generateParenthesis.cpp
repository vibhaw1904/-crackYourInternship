class Solution {
    void solve(int n,vector<string>&ans,string res,int open ,int close ){
        if(res.length()==2*n){
            ans.push_back(res);
        }
        if(open<n)solve(n,ans,res+'(',open+1,close);
        if(close<open)solve(n,ans,res+')',open,close+1);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string res="";
        solve(n,ans,res,0,0);
        return ans;

    }
};