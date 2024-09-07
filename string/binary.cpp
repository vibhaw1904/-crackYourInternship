#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int num;
    string binary="";
    cout<<"enter the decimal number"<<endl;
    cin>>num;
    if(num==0){
        binary="0";
    }
    else{
        while(num>0){
            binary+=to_string(num%2);
            num=num/2;
        }
        reverse(binary.begin(),binary.end());
    }
     cout << "Binary representation: " << binary << endl;

    return 0;
}