/*
Problem statement - 

Given an integer n. Each number from 1 to n is grouped according to the sum of its digits. 
Return how many groups have the largest size.

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.

Input: n = 15
Output: 6

Input: n = 24
Output: 5
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int sum_of_digits(int n) {
    int sum = 0;
    while(n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}
int countLargestGroup(int n) {
    unordered_map<int, int> mp;
    int ms = 0, c = 0;
    for(int i = 1; i <= n; i++)
    {
        int x = i, sum = 0;
        sum = sum_of_digits(x);
        mp[sum]++;
        if(ms < mp[sum]) {
            ms = mp[sum];
            c = 1;
        }
        else if(ms == mp[sum])
            c++;
    }
    return c;
}
