#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int>&arr){
    int count=0;
    int size=arr.size()-1;
    for(int i=1;i<size+1;i++){
        if(arr[i-1]>arr[i]){
            count++;
        }
    }
    if(arr[size]>arr[0]){
        count++;
    }
    return count<=1;
}

int main(){

}