/*
You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, 
which may or may not point to a separate doubly linked list. These child lists may have one or more children of their 
own, and so on, to produce a multilevel data structure, as shown in the example below.
Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the 
first level of the list.

Example 1:
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]

Example 2:
Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:
The input multilevel linked list is as follows:

  1---2---NULL
  |
  3---NULL

Example 3:
Input: head = []
Output: []

How multilevel linked list is represented in test case:
We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
The serialization of each level is as follows:
[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the
previous level. The serialization becomes:
[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
Merging the serialization of each level and removing trailing nulls we obtain:
[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 
Constraints:

Number of Nodes will not exceed 1000.
1 <= Node.val <= 10^5
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void TravNodes(Node* head, vector<Node*>& ans){
        ans.push_back(head);   // Insert the current node
		 // if node has a child recursive call to the child
        if(head->child) TravNodes(head->child,ans);  
        if(!head->next) return;  // if next node is NULL return
        TravNodes(head->next,ans);  // Traverse the next node
    }
    
    Node* flatten(Node* head) {
        if(!head) return head;  // If there is node head return
        vector<Node*>ans;  // ans array to store nodes in order
        ans.push_back(NULL); // Let the first element be NULL as head->prev = NULL;
        TravNodes(head,ans);  // Helper function call
		// Iterate from the second element till second last element (1st ele is NULL)
        for(int i = 1;i<ans.size()-1;i++){ 
            ans[i]->prev = ans[i-1];   // set prev ele
            ans[i]->next = ans[i+1];  // set next ele
            ans[i]->child = nullptr;  // remove child ptr
        }
		// Set next and prev for last element
        ans[ans.size()-1]->prev = ans[ans.size()-2];  
        ans[ans.size()-1]->next = NULL;
        ans[ans.size()-1]->child = NULL;
        return ans[1];  // Return the head stored in ans[1]
    }
};
