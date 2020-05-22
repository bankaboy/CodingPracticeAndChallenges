#include<bits/stdc++.h>
using namespace std;
/*
Problem - 

You are given the array paths, where paths[i] = [cityAi, cityBi] 
means there exists a direct path going from cityAi to cityBi. 
Return the destination city, that is, the city without any path 
outgoing to another city.
It is guaranteed that the graph of paths forms a line without any 
loop, therefore, there will be exactly one destination city.

Example 1:
Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".

Example 2:
Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".

Example 3:
Input: paths = [["A","Z"]]
Output: "Z"

Constraints:
1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.
*/

/* 
My solution 
Maintain a map of city and boolean ifoutgoing. For every pair
put the first one as true, and for the second, put it to false if
record doesn't exist in map yet.
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // first bool is outgoing 
        unordered_map<string,bool> mp;
        for(vector<string> v: paths) {
            mp[v[0]] = true;
            if (mp[v[1]]==true) continue;
            else mp[v[1]] = false;
        }
        string ans;
        for (auto i : mp) 
            if (i.second==false) {
                ans = i.first;
                break;
            } 
        return ans;
    }
};


/* From Discussion - 
Add all the cities with receiving path and then remove all the
ones with outgoing part. Only the city with no outgoing will
remain
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> s;
        for(auto &x: paths) s.insert(x[1]);
        for(auto &x: paths) s.erase(x[0]);
        return *s.begin();
    }
};