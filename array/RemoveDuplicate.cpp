#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int RemoveDupliacte(vector<int>& nums) {
   if(nums.empty()) return 0;
   int last=0;
   for(int i=0;i<nums.size();i++){
    if(nums[last]!=nums[i]){
        last++;
        nums[last]=nums[i];
    }
   }
   nums.resize(last+1);
   return nums.size();
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v(n); 
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "The duplicate element is: " << RemoveDupliacte(v) << endl;

    return 0;
}
