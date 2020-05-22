#include<bits/stdc++.h>
using namespace std;

/* 
Problem - 

Given an array target and an integer n. In each iteration, you will 
read a number from  list = {1,2,3..., n}.

Build the target array using the following operations:
Push: Read a new element from the beginning list, and push it in the array.
Pop: delete the last element of the array.
If the target array is already built, stop reading more elements.

You are guaranteed that the target array is strictly increasing, 
only containing numbers between 1 to n inclusive.
Return the operations to build the target array.
You are guaranteed that the answer is unique.

Example 1:
Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: 
Read number 1 and automatically push in the array -> [1]
Read number 2 and automatically push in the array then Pop it -> [1]
Read number 3 and automatically push in the array -> [1,3]

Example 2:
Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]

Example 3:
Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: You only need to read the first 2 numbers and stop.

Example 4:
Input: target = [2,3,4], n = 4
Output: ["Push","Pop","Push","Push","Push"]

Constraints:
1 <= target.length <= 100
1 <= target[i] <= 100
1 <= n <= 100
target is strictly increasing.
*/


// My solution
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int num) {
        vector<string> ans;
        int n = target.size();
        int current_index = 0;
        for(int i=1;i<=num;i++) {
            ans.push_back("Push");
            if (i!=target[current_index]) {
                ans.push_back("Pop");
            } else {
                current_index++;
            }
            if (target[n-1]==i) {
                break;
            }
        }
        return ans;
    }
};

// Top answer - 

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
    vector<string> buildArray(vector<int>& target, int n) {
		int is[101]={};
		FORR(t,target) is[t]=1;
		vector<string> T;
		for(int i=1;i<=n;i++) {
			T.push_back("Push");
			if(is[i]==0) T.push_back("Pop");
			if(target.back()==i) break;
		}
		return T;
        
    }
};