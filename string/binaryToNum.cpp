#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int binaryToDecimal(int num){
    int n=num;
    int dec_val=0;
    int base=1;
    int temp=n;
    while(temp){
        int digit=temp%10;
        temp=temp/10;
        dec_val+=digit*base;
        base=base*2;
    }
    return dec_val;
}

int main() {
   int num;
   cout<<"enter the number"<<endl;
   cin>>num;
   cout<<binaryToDecimal(num);
}