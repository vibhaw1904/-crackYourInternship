class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(c>0){
                    ans+=s[i];
                }
                c++;
                }
                else {
                    if(c>1){
                      ans+=s[i];  
                    }
                    c--;
                }
            
        }
        return ans;

    }
};