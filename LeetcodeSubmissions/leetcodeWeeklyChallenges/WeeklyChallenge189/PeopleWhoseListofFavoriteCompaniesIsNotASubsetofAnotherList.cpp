#include<bits/stdc++.h>
using namespace std;

/*
Given the array favoriteCompanies where favoriteCompanies[i] is the 
list of favorites companies for the ith person (indexed from 0).
Return the indices of people whose list of favorite companies is 
not a subset of any other list of favorites companies. You must 
return the indices in increasing order.

Example 1:
Input: favoriteCompanies = [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
Output: [0,1,4] 
Explanation: 
Person with index=2 has favoriteCompanies[2]=["google","facebook"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"] corresponding to the person with index 0. 
Person with index=3 has favoriteCompanies[3]=["google"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"] and favoriteCompanies[1]=["google","microsoft"]. 
Other lists of favorite companies are not a subset of another list, therefore, the answer is [0,1,4].

Example 2:
Input: favoriteCompanies = [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
Output: [0,1] 
Explanation: In this case favoriteCompanies[2]=["facebook","google"] is a subset of favoriteCompanies[0]=["leetcode","google","facebook"], therefore, the answer is [0,1].

Example 3:
Input: favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
Output: [0,1,2,3]

Constraints:
1 <= favoriteCompanies.length <= 100
1 <= favoriteCompanies[i].length <= 500
1 <= favoriteCompanies[i][j].length <= 20
All strings in favoriteCompanies[i] are distinct.
All lists of favorite companies are distinct, that is, If we sort alphabetically each list then favoriteCompanies[i] != favoriteCompanies[j].
All strings consist of lowercase English letters only.
*/


/* 
My solution - Time limit exceeded
For every item check if it is a subset of another item, skip if 
both are same
*/
class Solution {
public:
    bool isSubset(vector<string> arr1, vector<string> arr2) { 
        int i = 0; 
        int j = 0; 
        int m = arr1.size(), n = arr2.size();
        for (i = 0; i < n; i++) { 
            for (j = 0; j < m; j++) { 
                if(arr2[i] == arr1[j]) 
                    break; 
            } 
/* If the above inner loop was not broken at all then arr2[i] is not present in arr1[] */
            if (j == m) 
                return false; 
        } 
/* If we reach here then all elements of arr2[] are present in arr1[] */
        return true; 
    } 

    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        bool itIsSubset = false, subset = false;
        vector<int> ans;
        int len = favoriteCompanies.size();
        for (int i=0;i<len;i++) {
            subset = false;
            itIsSubset = false;
            for (int j=0;j<len;j++) {
                if (i==j) { continue; } // do not compare same items
                // check if favoriteCompanies[i] is subset of favoriteCompanies[j]
                subset = isSubset(favoriteCompanies[j], favoriteCompanies[i]);
                if (subset) {
                    itIsSubset = true;
                    break;
                }
            }
            if (itIsSubset) { continue; }
            ans.push_back(i);
        }
        return ans;
    }
}; 

// Try 2 - unordered set - time exceeded
class Solution {
public:
    bool isSubset(vector<string> arr1, vector<string> arr2) { 
        int m = arr1.size(), n = arr2.size();
        unordered_set<string> uset;
        
        for(int i = 0; i < m; i++) { 
            if(uset.find(arr1[i])==uset.end()) 
                uset.insert(arr1[i]); 
        } 
        // loop to check if all elements of arr2 also 
        // lies in arr1 
        for(int i = 0; i < n; i++) { 
            if(uset.find(arr2[i])==uset.end()) 
                return false; 
        } 
        return true; 
    } 

    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        bool itIsSubset = false, subset = false;
        vector<int> ans;
        int len = favoriteCompanies.size();
        for (int i=0;i<len;i++) {
            subset = false;
            itIsSubset = false;
            for (int j=0;j<len;j++) {
                if (i==j) { continue; } // do not compare same items
                // check if favoriteCompanies[i] is subset of favoriteCompanies[j]
                subset = isSubset(favoriteCompanies[j], favoriteCompanies[i]);
                if (subset) {
                    itIsSubset = true;
                    break;
                }
            }
            if (itIsSubset) { continue; }
            ans.push_back(i);
        }
        return ans;
    }
};  

/*
Discussion - 
Same logic , but used inbuilt function "includes" instead of custom
*/
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favs) {
	    for (auto &comps : favs)
    		sort(begin(comps), end(comps));
	    vector<int> res;
	    for (auto i = 0; i < favs.size(); ++i) {
    		bool notSubset = true;
    		for (auto j = 0; j < favs.size() && notSubset; ++j) {
    			if (i == j)
    				continue;
    			notSubset = !includes(begin(favs[j]), end(favs[j]), begin(favs[i]), end(favs[i]));
    		}
    		if (notSubset)
    			res.push_back(i);
    	}
    	return res;
    }
};  