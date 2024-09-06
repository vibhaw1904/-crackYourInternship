class Solution {
public:
    string largestOddNumber(string num) {
        int len=num.size();
        int r;
        bool flag=false;
        for(int i=len-1;i>=0;i--){
            if((num[i]-'0')&1){
                r=i;
                flag=true;
                break;
            }
        }
        if(flag){
            return num.substr(0,r+1);
        }
        else{
            return "";
        }
    }
};