#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    return(nums[nums.size()/2]);
        
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

    cout << "The majority element is: " << majorityElement(v) << endl;

    return 0;
}




