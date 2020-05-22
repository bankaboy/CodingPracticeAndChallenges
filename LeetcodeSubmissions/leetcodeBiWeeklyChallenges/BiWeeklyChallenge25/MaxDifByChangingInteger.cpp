#include<bits/stdc++.h>
using namespace std;

// My solution

class Solution {
    int newNumber (int num, int actual, int replaceBy) {
        int result = 0, decimalPlace =1;
        if (num==actual) {
            result += (replaceBy*decimalPlace);
            return result;
        }
        while (num) { 
            int dig = num % 10;
            if (dig == actual) 
                result += (replaceBy * decimalPlace); 
            else
                result += (dig * decimalPlace);
            num /= 10; 
            decimalPlace *= 10; 
        } 
        return result;
    }
    int firstDigit(int n) { 
        while (n >= 10)  
            n /= 10; 
        return n; 
    } 

public:
    int maxDiff(int num) {
        int bnum, snum, num1=num, num2=num ,sreplace, breplace;
        
        while (num1) { // find the correct samller digit to replace with
            // If first digit is 1 then we can replace occurences of next digit with 0
            sreplace = firstDigit(num1);
            if (sreplace==1) 
                num1 /= 10;
            else
                break;
        }
        while (num2) { // find the correct bigger digit to replace with
            // If first digit is 9 then we can replace occurences of next digit with 9
            breplace = firstDigit(num2);
            if (breplace==9) 
                num2 /= 10;
            else 
                break;
        }
        cout<<sreplace<<" "<<breplace<<"\n";
        
        if (num1==0) {
            snum = num;
        } else {
            snum = newNumber(num,sreplace,1);
        }
        
        if (num2==0) {
            bnum = num;
        } else {
            bnum = newNumber(num,breplace,9);
        }
        
        cout<<bnum<<" "<<snum;
        return bnum-snum;
    }
};

// Discussion

class Solution {
public:
    int maxDiff(int num) {
        
        auto a_str = to_string(num);
        
        int biggest_digit = 9;
        // find the next biggest digit after 9
        for (int i = 0; i < a_str.length(); ++i) {
            if (a_str[i] - '0' < biggest_digit) {
                biggest_digit = a_str[i] - '0';
                break;
            }
        }
        
        // replace all of its occurences with 9
        for (int i = 0; i < a_str.length(); ++i)
            if (a_str[i] - '0' == biggest_digit) {
                a_str[i] = '9';
            }
        
        int a = stoi(a_str);
        
        // find the next smallest to replace after 1
        auto b_str = to_string(num);
        int smallest_digit = 1;
        for (int i = 0; i < b_str.length(); ++i) {
            if (b_str[i] - '0' > smallest_digit) {
                smallest_digit = b_str[i] - '0';
                break;
            }
        }
        
        // check if first digit is 1
        char to_replace = (b_str[0] - '0' == smallest_digit) ? '1' : '0';
        for (int i = 0; i < b_str.length(); ++i) {
            if (b_str[i] - '0' == smallest_digit) {
                b_str[i] = to_replace;
            }
        }
        
        int b = stoi(b_str);
        
        return a - b;
    }
};