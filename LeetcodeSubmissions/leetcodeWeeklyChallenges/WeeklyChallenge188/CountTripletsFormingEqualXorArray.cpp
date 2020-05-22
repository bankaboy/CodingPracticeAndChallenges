#include<bits/stdc++.h>
using namespace std;
/*
Problem - 

Given an array of integers arr.
We want to select three indices i, j and k where 
(0 <= i < j <= k < arr.length).

Let's define a and b as follows:
a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.
Return the number of triplets (i, j and k) Where a == b.

Example 1:
Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)

Example 2:
Input: arr = [1,1,1,1,1]
Output: 10

Example 3:
Input: arr = [2,3]
Output: 0

Example 4:
Input: arr = [1,3,5,7,9]
Output: 3

Example 5:
Input: arr = [7,11,12,9,5,2,7,17,22]
Output: 8

Constraints:
1 <= arr.length <= 300
1 <= arr[i] <= 10^8
*/

// Try 1 - time limit exceeded, brute force
class Solution {
    int returnXOR (vector<int> arr,int i,int j) {
        int m = arr[i];
        for (int x=i+1;x<j;x++) {
            m = m^arr[x];
        }
        return m;
    }
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for(int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                for (int k=j;k<n;k++) {
                    if (returnXOR(arr,i,j)==returnXOR(arr,j,k+1)) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

// Try using given relation between i,j,k - wrong answer
class Solution {
    int returnXOR (vector<int> arr,int i,int j) {
        int m = arr[i];
        for (int x=i+1;x<j;x++) {
            m = m^arr[x];
        }
        return m;
    }
public:
    int countTriplets(vector<int>& arr) {
        int i,k;
        int ans = 0, n = arr.size();
        for(int j=0;j<n;j++) {
            for (i=0,k=j;(i<j && k<n);i++,k++) {
                if (returnXOR(arr,i,j)==returnXOR(arr,j,k+1)) {
                        ans++;
                }
            }
        }
        return ans;
    }
};

// Try 3 - Used Tries (GeeksForGeeks)
// https://www.geeksforgeeks.org/number-of-triplets-in-array-having-subarray-xor-equal/
class Solution {
    struct TrieNode { 
        TrieNode* children[2]; 
        int sum_of_indexes; 
        int number_of_indexes; 
        TrieNode() { 
            this->children[0] = nullptr; 
            this->children[1] = nullptr; 
            this->sum_of_indexes = 0; 
            this->number_of_indexes = 0; 
        } 
    };
    void insert(TrieNode* node, int num, int index) { 
        for (int bits = 31; bits >= 0; bits--) { 
            int curr_bit = (num >> bits) & 1; 
            if (node->children[curr_bit] == nullptr) { 
                node->children[curr_bit] = new TrieNode(); 
            } 
            node = node->children[curr_bit]; 
        } 
        node->sum_of_indexes += index; 
        node->number_of_indexes++; 
    } 
    int query(TrieNode* node, int num, int index) { 
        for (int bits = 31; bits >= 0; bits--) { 
            int curr_bit = (num >> bits) & 1; 
            if (node->children[curr_bit] == nullptr) { 
                return 0; 
            } 
            node = node->children[curr_bit]; 
        } 
        int sz = node->number_of_indexes; 
        int sum = node->sum_of_indexes; 
        int ans = (sz * index) - (sum); 
        return ans; 
    }
    
public:
    int countTriplets(vector<int> arr) { 
        int n = arr.size();
        int curr_xor = 0;
        int number_of_triplets = 0; 
        TrieNode* root = new TrieNode(); 
        for (int i = 0; i < n; i++) { 
            int x = arr[i]; 
            insert(root, curr_xor, i); 
            curr_xor ^= x; 
            number_of_triplets += query(root, curr_xor, i); 
        } 
        return number_of_triplets; 
    }
};


// Top answer

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ret=0;
        int x,y,z;
        int N=arr.size();
        for(x=0;x<N;x++) {
			int a=0;
			for(y=x;y<N;y++) {
				a^=arr[y];
				int b=0;
				for(z=y+1;z<N;z++) {
					b^=arr[z];
					if(a==b) ret++;
				}
			}
		}
        return ret;
    }
};
