#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

using namespace std;

int bestTime(vector<int>& nums) {
    int minPrice = INT_MAX; 
    int maxProfit = 0;      

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < minPrice) {
            minPrice = nums[i]; 
        } else if (nums[i] - minPrice > maxProfit) {
            maxProfit = nums[i] - minPrice; 
        }
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
