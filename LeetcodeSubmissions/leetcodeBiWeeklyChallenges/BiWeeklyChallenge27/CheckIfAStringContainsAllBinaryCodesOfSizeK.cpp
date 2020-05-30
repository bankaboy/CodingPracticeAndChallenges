#include<bits/stdc++.h>
using namespace std;

/*
Given a binary string s and an integer k.
Return True if any binary code of length k is a substring of s. 
Otherwise, return False.

Example 1:
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.

Example 2:
Input: s = "00110", k = 2
Output: true

Example 3:
Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 

Example 4:
Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and doesn't exist in the array.

Example 5:
Input: s = "0000000001011100", k = 4
Output: false
*/

/*
Attempt 1 - Generate all k bits strings and compare
Time limit exceeded
*/
class Solution {
public:
    vector<string> BinarySubsets(int k) {
        vector<string> list;
        int n = 0;
        string bin_str = "";
        for(int i = 0; i<k; i++){
            bin_str += "0";
        }
        int limit = pow(2, k);
        list.push_back(bin_str);
        for(int i=1; i<limit; i++){
              int j = 0;
              while(j <= k) {
                 if(bin_str[k-1-j] == '0'){
                    bin_str[k - 1 - j] = '1';
                    break;
                } else {
                    bin_str[k - 1 - j] = '0';
                    j++;
                }
            }
            list.push_back(bin_str);
        }
        return list;
    }
    bool hasAllCodes(string s, int k) {
        vector<string> list = BinarySubsets(k);
        for(int i = 0; i<list.size(); i++){
            string substr = list[i];
            std::size_t found = s.find(substr);
            if(found == std::string::npos){
                 return false;
            }
        }
        return true;
    }
};


// Attempt 2 - combine both functions - TLE
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<string> list;
        int n = 0;
        string bin_str = "";
        for(int i = 0; i<k; i++){
            bin_str += "0";
        }
        int limit = pow(2, k);
        size_t found = s.find(bin_str);
        if (found==string::npos) {
            return false;
        }
        for(int i=1; i<limit; i++){
              int j = 0;
              while(j <= k) {
                 if(bin_str[k-1-j] == '0'){
                    bin_str[k - 1 - j] = '1';
                    break;
                } else {
                    bin_str[k - 1 - j] = '0';
                    j++;
                }
            }
            found = s.find(bin_str);
            if (found==string::npos) {
                return false;
            }
        }
        return true;
    }
};

/* 
Attempt 3 - Use builtin functions and stl.
convert each substring of k length to decimal and check if it is 
less than 2^k. Keep record of all the numbers seen already.
If number is already seen , skip
*/
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int count = pow(2,k), n = s.length(), answer = 0, number;
        set<int> check;
        for (int i=0;i<n-1;i++) {
            string bin_string = s.substr(i,k);
            number = stoi(bin_string,0,2);
            // check if number is already seen 
            if (check.find(number)==check.end() && number<=count) {
                answer++;
                check.insert(number);
            }
        }
        return answer==count;
    }
};

// Discussion
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int d = 0;
        unordered_set<int> hset;
        for (int i = 0; i < s.length(); i++) {
            d = (d << 1) | (s[i] - '0');
            if (i >= k - 1) {
                hset.insert(d);
                d -= (s[i - (k - 1)] - '0') << (k - 1);
            }
        }
        return hset.size() == (1 << k);
    }
};