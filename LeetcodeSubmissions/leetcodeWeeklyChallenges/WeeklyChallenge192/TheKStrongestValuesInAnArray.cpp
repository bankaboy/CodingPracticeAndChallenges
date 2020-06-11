/*
Given an array of integers arr and an integer k.

A value arr[i] is said to be stronger than a value arr[j] if 
|arr[i] - m| > |arr[j] - m| where m is the median of the array.
If |arr[i] - m| == |arr[j] - m|, then arr[i] is said to be stronger 
than arr[j] if arr[i] > arr[j].

Return a list of the strongest k values in the array. return the 
answer in any arbitrary order.

Median is the middle value in an ordered integer list. More formally, 
if the length of the list is n, the median is the element in 
position ((n - 1) / 2) in the sorted list (0-indexed).

For arr = [6, -3, 7, 2, 11], n = 5 and the median is obtained by 
sorting the array arr = [-3, 2, 6, 7, 11] and the median is arr[m] 
where m = ((5 - 1) / 2) = 2. The median is 6.
For arr = [-7, 22, 17, 3], n = 4 and the median is obtained by 
sorting the array arr = [-7, 3, 17, 22] and the median is arr[m] 
where m = ((4 - 1) / 2) = 1. The median is 3.
 
Example 1:
Input: arr = [1,2,3,4,5], k = 2
Output: [5,1]
Explanation: Median is 3, the elements of the array sorted by the strongest are [5,1,4,2,3]. The strongest 2 elements are [5, 1]. [1, 5] is also accepted answer.
Please note that although |5 - 3| == |1 - 3| but 5 is stronger than 1 because 5 > 1.

Example 2:
Input: arr = [1,1,3,5,5], k = 2
Output: [5,5]
Explanation: Median is 3, the elements of the array sorted by the strongest are [5,5,1,1,3]. The strongest 2 elements are [5, 5].

Example 3:
Input: arr = [6,7,11,7,6,8], k = 5
Output: [11,8,6,6,7]
Explanation: Median is 7, the elements of the array sorted by the strongest are [11,8,6,6,7,7].
Any permutation of [11,8,6,6,7] is accepted.

Example 4:
Input: arr = [6,-3,7,2,11], k = 3
Output: [-3,11,2]

Example 5:
Input: arr = [-7,22,17,3], k = 2
Output: [22,17]

Constraints:
1 <= arr.length <= 10^5
-10^5 <= arr[i] <= 10^5
1 <= k <= arr.length
*/

#include<bits/stdc++.h>
using namespace std;
/* 
My Solution 1 - 
Find median, two pointers, from start and end.
check rule and append accordingly
Error for last test case
*/
class Solution {
public:
    int getMedian (vector<int> arr, int n) {
        int median = 0;
        if (n%2==0) {
            median = (arr[(n-1)/2] + arr[(n)/2])/2;
        } else {
            median = arr[n/2];
        }
        return median;
    }
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int median = getMedian(arr,n);
        int i=0, j=n-1;
        vector<int> ans;

        for(int l=0; l<k; l++) {
            
            int iVal = abs(arr[i]-median);
            int jVal = abs(arr[j]-median);
            
            if (arr[i]<0 && arr[j]>=0) {
                ans.push_back(arr[j]);
                j--;
                continue;
            } else if (arr[j]<0 && arr[i]>=0) {
                ans.push_back(arr[i]);
                i++;
                continue;
            }
            
            if(iVal>jVal) {
                ans.push_back(arr[i]);
                i++;
            } else if (jVal>iVal) {
                ans.push_back(arr[j]);
                j--;
            } else {
                if (arr[i]>arr[j]) {
                    ans.push_back(arr[i]);
                    i++;
                } else if (arr[j]>arr[i]) {
                    ans.push_back(arr[j]);
                    j--;
                } 
                else {
                    // ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                    j--;
                    // i++;
                }
            }
        }
        return ans;
    }
};

// Discussion
class Solution {
public:
    vector<int> getStrongest(vector<int> A, int k) {
        sort(A.begin(), A.end());
        int n = A.size(), i = 0, j = n - 1, m = A[(n - 1) / 2];
        while (k--) {
            if (A[j] - m >= m - A[i])
                j--;
            else
                i++;
        }
        A.erase(A.begin() + i, A.begin() + j + 1);
        return A;
    }
};