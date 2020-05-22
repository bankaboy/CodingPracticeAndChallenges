/* 
Problem Statement - 

Given a number s in their binary representation. Return the number 
of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.
If the current number is odd, you have to add 1 to it.
It's guaranteed that you can always reach to one for all testcases.

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal 
representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.

Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  

Input: s = "1"
Output: 0

My code - 

int numSteps(string s) {
    long decimal = 0, len=s.length(), power = 0;
    int steps = 0;
    for(int i=len-1;i>=0;i--) {
        cout<<s[i]<<endl;
        decimal += (s[i]-'0')*pow(2,power);
        power++;
    }
    while (decimal!=1) {
        if (decimal%2==0) {
            decimal = decimal/2;
            steps++;
        }
        else {
            decimal = decimal+1;
            steps ++;
        }
    }
    return steps;
}
*/

#include<iostream>
using namespace std;

int numSteps(string &s) {
    int res = 0, rem = 0;
    for (; s != "1"; s.pop_back()) {
        if (s.back() - '0' + rem == 1) {
            rem = 1;
            res += 2;
        } 
        else
            res += 1;   
    }
    return res + rem;
}