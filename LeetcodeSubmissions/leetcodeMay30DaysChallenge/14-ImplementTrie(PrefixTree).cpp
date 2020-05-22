/*
Implement a trie with insert, search, and startsWith methods.

Example:
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note:
You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

class Node {
public:
    char c; // the character in the node
    bool isend; // the node is end of a word
    int shared; // the number of node shared
    vector<Node*> children; // the children of the node
    
    Node():c(' '), isend(false), shared(0) {}
    Node(char ch):c(ch), isend(false), shared(0) {}
    Node* subNode(char ch) {
        if (!children.empty()) {
            for (auto child:children) {
                if (child->c == ch) 
                    return child;
            }
        }
        return nullptr;
    }
    ~Node() {
        for(auto child:children)
            delete child;
    }
};
    
    
class Trie {
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (search(word)) return;
        Node* curr = root;
        for (auto ch:word) {
            Node* child = curr->subNode(ch);
            if (child!=nullptr) {
                curr = child;
            } else {
                Node *newnode = new Node(ch);
                curr->children.push_back(newnode);
                curr = newnode;
            }
            ++curr->shared;
        }
        curr->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *curr = root;
        for (auto ch:word) {
            curr = curr->subNode(ch);
            if (curr == nullptr) 
                return false;
        }
        return curr->isend == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for (auto ch : prefix) {
            curr = curr->subNode(ch);
            if (curr == nullptr)
                return false;
        }
        return true;
    }
    
    ~Trie() {
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
