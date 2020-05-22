/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

public:
    void moveZeroes(vector<int>& nums) {
        for(auto it1=nums.begin(); it1!=nums.end();it1++) {
            if (*it1==0) {
                nums.erase(it1);
                nums.push_back(0);
            }
        }
        for(auto it2=nums.rbegin(); it2!=nums.rend();it2++) {
            if (*it2==0) {
                nums.erase((it2+1).base());
                nums.push_back(0);
            }
        }
        for(auto it=nums.begin(); it != nums.end(); it++) {
            cout<<*it<<"\t";
        }
        cout<<endl;
    }
};
