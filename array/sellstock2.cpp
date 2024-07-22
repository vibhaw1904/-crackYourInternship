#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

using namespace std;

int bestTime(vector<int>& nums) {
    int start=nums[0];
    int n=nums.size();

    int maxProfit = 0;      

    for (int i = 1; i < n; i++) {
        if (start<nums[i]) {
             maxProfit+=nums[i]-start;
        }
        start=nums[i];
    }

    return maxProfit;
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

    cout << "The max profit is: " << bestTime(v) << endl;

    return 0;
}
