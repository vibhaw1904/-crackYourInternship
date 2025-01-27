class Solution {
public:
     void generate( int n,vector<string>&ans,int open,int close,string curr_str){
        if(curr_str.size()==2*n){
            ans.push_back(curr_str);
            return;
        }
        if(open<n)  generate(n,ans,open+1,close,curr_str+"(");
        if(close<open)  generate(n,ans,open,close+1,curr_str+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(n,ans,0,0,"");
        return ans;
    }
};