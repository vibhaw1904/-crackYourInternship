#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> ans;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            ans.push_back(nums[i]);
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

    vector<int> duplicates = findDuplicates(v);

    cout << "The duplicate elements are: ";
    for (int i : duplicates) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
