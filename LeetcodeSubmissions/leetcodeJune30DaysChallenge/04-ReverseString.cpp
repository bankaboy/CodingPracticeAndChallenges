/*
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

// Solution 1 - use inbuilt function
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) {
            return;
        }
        reverse(s.begin(), s.end());
    }
};

//Solution 2 - treat like array
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) {
            return;
        }
        int n = s.size();
        for (int i=0;i<n/2;i++) {
            swap(s[i], s[n-1-i]);
        }
    }
};

// Solution 3 - Two pointers
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) {
            return;
        }
        auto fit = s.begin();
        auto bit = s.rend();
        for (auto fit = s.begin(), bit = prev(s.end()); fit<bit; fit++, bit--) {
            swap(*fit, *bit);
        }
    }
};
