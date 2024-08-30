class Solution {
public:
    void reverseString(vector<char>& s) {
        int high=s.size()-1;
        int low=0;
        while(low<=high){
            swap(s[low],s[high]);
            low++;
            high--;
        }
    }
};
