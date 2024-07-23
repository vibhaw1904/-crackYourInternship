
#include <iostream>
#include <vector>
#include<string>

using namespace std;



class Solution {


public:
    string intoString(int n){
        string ones[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens[10] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};   
        
        if(n>=1000000000) return intoString(n/1000000000)+" Billion" + intoString(n%1000000000);
        if(n>=1000000) return intoString(n/1000000)+" Million" + intoString(n%1000000);
        if(n>=1000) return intoString(n/1000)+" Thousand" + intoString(n%1000);
        if(n>=100) return intoString(n/100)+" Hundred" + intoString(n%100);
        if(n>=20) return " " + tens[n/10-2]+ intoString(n%10);
        if(n>=1) return " "+ones[n];

        return "";




         }


    string numberToWords(int num) {
        if(num==0)return  "Zero";
        return intoString(num).substr(1);

    }
};