/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        int i, j, t, sum, jie;
        jie = 1;
        for (i = 1; i <= n; i++){
            jie = i * jie;
            ans += to_string(i);
        }
        for (i = 0; i < n; i++){
            jie /= n - i;
            for (sum = 0, j = 1; j <= n; j++){
                if (sum + jie >= k) break;
                sum += jie;
                swap(ans[i], ans[i + j]);
            }
            k -= sum;
        }
        return ans;
    }
};
