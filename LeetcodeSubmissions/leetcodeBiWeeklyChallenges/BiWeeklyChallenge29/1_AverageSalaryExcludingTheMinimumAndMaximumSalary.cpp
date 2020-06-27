/*
1_Easy

Given an array of unique integers salary where salary[i] 
is the salary of the employee i.
Return the average salary of employees excluding the 
minimum and maximum salary.

Example 1:
Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 
and 4000 respectively.
Average salary excluding minimum and maximum salary is 
(2000+3000)/2= 2500

Example 2:
Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000)/1= 2000

Example 3:
Input: salary = [6000,5000,4000,3000,2000,1000]
Output: 3500.00000

Example 4:
Input: salary = [8000,9000,2000,3000,6000,1000]
Output: 4750.00000

Constraints:
3 <= salary.length <= 100
10^3 <= salary[i] <= 10^6
salary[i] is unique.
Answers within 10^-5 of the actual value will be accepted as correct.
*/

#include<bits/stdc++.h>
using namespace std;

// My solution
class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        if(n<=2) {return 0;}
        n = n-2; // minimum and maximum will not be counted
        double sum = accumulate(salary.begin(), salary.end(), 0);
        sum -= (*max_element(salary.begin(), salary.end())+*min_element(salary.begin(), salary.end()));
        return sum/n;
    }
};

// Discussion - Same but more compact
double average(vector<int>& s) {
    return (accumulate(begin(s), end(s), 0.) - *min_element(begin(s), end(s)) 
        - *max_element(begin(s), end(s))) / (s.size() - 2);
}