/*
Given an array of numbers arr. A sequence of numbers is called an 
arithmetic progression if the difference between any two consecutive 
elements is the same.
Return true if the array can be rearranged to form an arithmetic 
progression, otherwise, return false.

Example 1:
Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with 
differences 2 and -2 respectively, between each consecutive elements.

Example 2:
Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an 
arithmetic progression.

Constraints:
2 <= arr.length <= 1000
-10^6 <= arr[i] <= 10^6
*/

#include<bits/stdc++.h>
using namespace std;

/*
My Solution - 
Check if the difference between the max and min divided by number of
terms - 1 has no decimal
*/
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        float maxx = *max_element(arr.begin(), arr.end());
        float minn = *min_element(arr.begin(), arr.end());
        int n = arr.size() - 1;
        float x = (maxx-minn)/n;
        cout<<maxx<<" "<<minn<<" "<<maxx-minn<<" "<<n<<" "<<x<<" "<<floor(x);
        if (x==floor(x))
            return true;
        return false;
    }
};

// Second solution
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        if (n==1) return true;
        sort(arr.begin(), arr.end());
        
          int d = arr[1] - arr[0]; 
        for (int i=2; i<n; i++) 
            if (arr[i] - arr[i-1] != d) 
                return false; 
  
        return true;
    }
};

// Discussion - 
class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int>& arr)
    {
        if (arr.size() <= 2) return true;
        int min = INT_MAX, max = INT_MIN;
        for (int num : arr) {
            min = std::min(min, num);
            max = std::max(max, num);
        }
        if ((max - min) % (arr.size() - 1) != 0) return false;
        int d = (max - min) / (arr.size() - 1);

        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == min + i * d) i++;
            else if ((arr[i] - min) % d != 0) return false;
            else {
                int pos = (arr[i] - min) / d;
                if (pos < i || arr[pos] == arr[i]) return false;
                std::swap(arr[i], arr[pos]);
            }
        }
        return true;
    }
};