#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int ans=0;
   sort(nums.begin(),nums.end());
   for(int i=0;i<nums.size()-1;i++){
    if(nums[i]==nums[i+1]){
        ans=nums[i];
        break;
    }
   }
   return ans;
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

    cout << "The duplicate element is: " << findDuplicate(v) << endl;

    return 0;
}
