/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the 
itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when 
read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string> > tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;         
        for (auto& a : tickets)  m[a[0]].insert(a[1]);
        string start("JFK");
        dfs(m, start, res);  
        return {res.rbegin(), res.rend()}; 
    }
    
    void dfs(unordered_map<string, multiset<string> > &m, string& s, vector<string> &res) {    
        while (m[s].size()) {
            auto cur = m[s].begin();
            string t = *cur;
            m[s].erase(cur);  
            dfs(m, t, res);
        }
        res.emplace_back(s);
    }
};
