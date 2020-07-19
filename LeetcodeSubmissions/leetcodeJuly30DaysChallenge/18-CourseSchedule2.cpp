/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as 
a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to 
finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, 
return an empty array.

Example 1:
Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .

Example 2:
Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph 
is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

class Solution {
public:
    bool checkReq(vector<int>& reqs, vector<bool>& cells) {
        for (auto n: reqs) if (!cells[n]) return false;
        return true;
    }
    vector<int> findOrder(int nc, vector<vector<int>>& ps) {
        vector<int> res;
        unordered_map<int, vector<int>> paths;
        unordered_map<int, vector<int>> reqs;
        queue<int> layer;
        vector<bool> cells(nc, true);
        for (auto p: ps) {
            paths[p[1]].push_back(p[0]);
            reqs[p[0]].push_back(p[1]);
            cells[p[0]] = false;
        }
        for (int i = 0; i < cells.size(); i++) {
            if (cells[i]) {
                layer.push(i);
                cells[i] = false;
            }
        }
        int len = layer.size(), currCourse;
        bool progressed = true;
        while (progressed && layer.size()) {
            progressed = false;
            for (int i = 0; i < len; i++) {
                currCourse = layer.front();
                layer.pop();
                if (!cells[currCourse]) {
                    if (checkReq(reqs[currCourse], cells)) {
                        progressed = true;
                        res.push_back(currCourse);
                        cells[currCourse] = true;
                        for (auto path: paths[currCourse]) layer.push(path);
                    } else {
                        layer.push(currCourse);
                    }
                }
            }
            len = layer.size();
        }
        return res.size() == nc ? res : vector<int>();
    }
};
