#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers arr and an integer k. Find the least 
number of unique integers after removing exactly k elements.

Example 1:
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.

Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 
1 and 3 will be left.
 
Constraints:
1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length
*/

// My Solution - remove the elements with least frequency(most unique)
// Time limit exceeded
class Solution {
public:
    unordered_map<int, vector<int>> mp;
    int leastElement() {
        int unique, minFreq = INT_MAX;
        for (auto elem:mp) {
            int idxVectorSize = elem.second.size();
            if (idxVectorSize>0 && idxVectorSize<minFreq ) {
                unique = elem.first;
                minFreq = elem.second.size();
            }
        }
        return unique;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        
        // create index map of elements, frequency is size of index vector
        for (int i=0;i<n;i++) {
            mp[arr[i]].push_back(i);
        }
        
        for (int i=0;i<k;i++) {
            // find the most unique element
            int elemDelete = leastElement();
            // remove it from the first occurence in the array
            mp[elemDelete].erase(mp[elemDelete].begin());
            mp[elemDelete].shrink_to_fit();
        }
        
        int count = 0;
        for (auto elem:mp) {
            if (elem.second.size()>0) {
                count++;
            }
        }
        return count;
    }
};


/*
Geeksforgeeks
1- Count the occurrence of elements and store in the hash.
2- Sort the hash.
3- Start removing elements from hash.
4- Return the number of values left in the hash.
*/
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        vector<pair<int,int>> v;
        int n = arr.size(), count = 0;
        
        for (int i=0;i<n;i++) {
            mp[arr[i]]++;
        }
        
        for (auto it = mp.begin(); it != mp.end(); it++)  {
            v.push_back(make_pair(it->second, it->first));
        }
        
        sort(v.begin(), v.end());
        int size = v.size();
        
        for(int i=0;i<size;i++) {
            if (v[i].first <= k) {
                k-=v[i].first;
                count++;
            } else {
                return size-count;
            }
        }
        return size-count;
    }
};