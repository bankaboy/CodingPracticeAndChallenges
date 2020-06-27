/*
Given an array of strings names of size n. You will create n 
folders in your file system such that, at the ith minute, you will 
create a folder with the name names[i].

Since two files cannot have the same name, if you enter a folder 
name which is previously used, the system will have a suffix 
addition to its name in the form of (k), where, k is the smallest 
positive integer such that the obtained name remains unique.

Return an array of strings of length n where ans[i] is the actual 
name the system will assign to the ith folder when you create it.

Example 1:
Input: names = ["pes","fifa","gta","pes(2019)"]
Output: ["pes","fifa","gta","pes(2019)"]
Explanation: Let's see how the file system creates folder names:
"pes" --> not assigned before, remains "pes"
"fifa" --> not assigned before, remains "fifa"
"gta" --> not assigned before, remains "gta"
"pes(2019)" --> not assigned before, remains "pes(2019)"

Example 2:
Input: names = ["gta","gta(1)","gta","avalon"]
Output: ["gta","gta(1)","gta(2)","avalon"]
Explanation: Let's see how the file system creates folder names:
"gta" --> not assigned before, remains "gta"
"gta(1)" --> not assigned before, remains "gta(1)"
"gta" --> the name is reserved, system adds (k), since "gta(1)" is also reserved, systems put k = 2. it becomes "gta(2)"
"avalon" --> not assigned before, remains "avalon"

Example 3:
Input: names = ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]
Output: ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)"]
Explanation: When the last folder is created, the smallest positive valid k is 4, and it becomes "onepiece(4)".

Example 4:
Input: names = ["wano","wano","wano","wano"]
Output: ["wano","wano(1)","wano(2)","wano(3)"]
Explanation: Just increase the value of k each time you create folder "wano".

Example 5:
Input: names = ["kaido","kaido(1)","kaido","kaido(1)"]
Output: ["kaido","kaido(1)","kaido(2)","kaido(1)(1)"]
Explanation: Please note that system adds the suffix (k) to current name even it contained the same suffix before.
 
Constraints:
1 <= names.length <= 5 * 10^4
1 <= names[i].length <= 20
names[i] consists of lower case English letters, digits and/or 
round brackets.
*/

/* 
thought 1 - keep a set of all the new names encountered 
when an old name is encountered, modify it accordingly
Gives correct output , but Time Limit Exceeded
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getNewName(string name, unordered_set<string> files) {
        string newName = "";
        int i = 1;
        while (true) {
            string k = to_string(i);
            string tryName = name+'('+k+')';
            if (files.find(tryName)==files.end()) { // modified name does not already exist
                newName = tryName;
                break;
            } else { // modified name already exists
                i++;
            }
        }
        return newName;
    }
    
    vector<string> getFolderNames(vector<string>& names) {
        unordered_set<string> files;
        vector<string> ans;
        for (string name:names) {
            auto ptr = files.find(name);
            // filename not encountered before
            if (ptr==files.end()) {
                files.insert(name);
                ans.push_back(name);
            } else { // case where filename encountered before
                string newName = getNewName(name, files);
                ans.push_back(newName);
                files.insert(newName);
            }
        }
        return ans;
    }
};

// Discussion - 
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> map;
        vector<string> result;
        
        for (auto name: names) {
            if (map.find(name) != map.end()) {
                int k = map[name];
                k++;
                string s = name + "(" + to_string(k) + ")";
                while (map.find(s) != map.end()) {
                    k++;
                    s = name + "(" + to_string(k) + ")";
                }
                result.push_back(s);
                map[s] = 0;
                map[name] = k;
            } else {
                map[name] = 0;
                result.push_back(name);
            }
        }
        return result;
    }
};