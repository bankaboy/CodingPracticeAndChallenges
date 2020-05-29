/*
Problem
Li has planned a bike tour through the mountains of Switzerland. 
His tour consists of N checkpoints, numbered from 1 to N in the 
order he will visit them. The i-th checkpoint has a height of Hi.

A checkpoint is a peak if:
It is not the 1st checkpoint or the N-th checkpoint, and
The height of the checkpoint is strictly greater than the 
checkpoint immediately before it and the checkpoint immediately 
after it.

Please help Li find out the number of peaks.

Input
The first line of the input gives the number of test cases, T. T 
test cases follow. Each test case begins with a line containing the 
integer N. The second line contains N integers. The i-th integer is 
Hi.

Output
For each test case, output one line containing Case #x: y, where x 
is the test case number (starting from 1) and y is the number of 
peaks in Li's bike tour.

Limits
Time limit: 10 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ Hi ≤ 100.

Test set 1
3 ≤ N ≤ 5.

Test set 2
3 ≤ N ≤ 100.

Sample

Input:
4
3
10 20 14
4
7 7 7 7
5
10 90 20 90 10
3
10 3 10

Output : 
Case #1: 1
Case #2: 0
Case #3: 2
Case #4: 0

In sample case #1, the 2nd checkpoint is a peak.
In sample case #2, there are no peaks.
In sample case #3, the 2nd and 4th checkpoint are peaks.
In sample case #4, there are no peaks.
*/

#include<iostream>
#include<vector>
using namespace std;

int testCase(vector<int>& H, int n) {
    int peaks = 0;
    for(int i=1;i<n-1;i++) {
        if (H[i]>H[i-1] && H[i]>H[i+1]) {
            peaks++;
        }
    }   
    return peaks;
}

int main() {
    int t;
    cin>>t;
    vector<pair<int,int>> ans;
    
    for (int i=0;i<t;i++) {
        int n, h;
        vector<int> H;
        cin>>n;
        for (int j=0;j<n;j++) {
            cin>>h;
            H.push_back(h);
        }
        ans.push_back({i+1,testCase(H,n)});
    }
    for (int i=0;i<t;i++) {
        cout<<"Case #"<<ans[i].first<<": "<<ans[i].second<<endl;
    }
}