class Solution {
private: 
  bool check(char ch){
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
        return 1;
    }
    return 0;
  }
    
  char toLowerCase(char ch){
    if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
  }

bool checkPalindrome(string a) {
  int s=0;
  int e=a.length()-1;
  while(s<=e){
    if(a[s]!=a[e]){
        return false;
    }
    else{
        s++;
        e--;
    }
  }
  return true;
}
public:
    bool isPalindrome(string s) {
        
        //Remove all non-alphanumeric character
       string temp="";
       for(int j=0;j<s.length();j++){
        if(check(s[j])){
            temp.push_back(s[j]);
        }
       }
        //convert all uppercase letter into lowercase
      for(int j=0;j<temp.length();j++){
        temp[j]=toLowerCase(temp[j]);
      }
        
        //check palindrome or not
        return checkPalindrome(temp);
    }
};