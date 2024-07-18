#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(target - nums[i]) == mp.end()) {
            mp[nums[i]] = i;
        } else {
            return {mp[target - nums[i]], i};
        }
    }
    return {-1, -1};
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

    int target;
    cout << "Enter the target: ";
    cin >> target;

    vector<int> result = twoSum(v, target);
    cout << "The indices are: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
