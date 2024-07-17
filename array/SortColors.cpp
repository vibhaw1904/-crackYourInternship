#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SortColors(vector<int>& nums) {
  int low=0;
  int mid=0;
  int high=nums.size()-1;
  while(mid<=low){
    if(nums[mid]==0){
        swap(nums[mid],nums[low]);
        mid++;
        low++;
    }
    else if(nums[mid]==1){
        mid++;
    }
    else{
        swap(nums[mid],nums[high]);
        high--;
    }
  }
}

void main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v(n); 
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout <<  SortColors(v) << endl;

   
}
