#include <iostream>
using namespace std;

int main(){
    int a=7;
    int b=9;

    a=a^b;
    b=a^b;
    a=a^b;

    cout<<"a is :"<<a<<endl;
    cout<<"b is :"<<b<<endl;
}