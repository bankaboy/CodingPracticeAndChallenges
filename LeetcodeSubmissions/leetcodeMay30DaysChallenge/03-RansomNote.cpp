/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function 
that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

/*
My Solution -
Create a multiset to store the magazine letters (set will remove copies and later give wrong answers).
Maintain a boolean for answer. We need only false once for the return of the function to be false.
For every letter in note, if the letter is in the multiset, remove it and keep the answer as true.
Otherwise remove false
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        multiset<char> mag;
        bool ans;
        for (char c:magazine) {
            mag.insert(c);
        }
        for (char c: ransomNote) {
            auto it = mag.find(c);
            if (it!=mag.end()) {
                mag.erase(it);
                ans = true;
            } else 
                return false;
        }
        return ans;
    }
};
