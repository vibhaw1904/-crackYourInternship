#include <iostream>
#include <vector>

using namespace std;

void mergeSorted(vector<int>& nums1, vector<int>& nums2,int n,int m) {
  int i=0;
  int j=0;
  vector<int>res;
  while(1){
    if(i==m){
        while(j<n){
            res.push_back(nums2[j]);
            j++;
        }
    }
    else if(j==n){
        while(i<m){
            res.push_back(nums1[i]);
            i++;
        }
    }

    else {
        if(nums1[i]<nums2[j]){
            res.push_back((nums1[i]));
            i++;

        }
        else{
            res.push_back(nums2[j]);
            j++;
        }
    }
  }

    for(int i=0;i<m+n;i++){
        nums1[i]=res[i];
    }

}

void main() {
    int m;
    cout << "Enter the number of elements: ";
    cin >> m;
   
    
    vector<int> v(m);
    cout << "Enter the elements: ";
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
     int n;
    cout << "Enter the number of elements: ";
    cin >> n;
     vector<int> v1(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }


   return mergeSorted(v,v1,n,m);



}
