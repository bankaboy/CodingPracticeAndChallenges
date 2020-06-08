/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people in front of this person who have a height greater 
than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

/*
Find people with tallest height first and order according to index
Coninue for each height
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto comp = [](const vector<int>& p1, const vector<int>& p2)
                        { return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]); };
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res;
        for (auto& p : people) 
            res.insert(res.begin() + p[1], p);
        return res;
    }
};
