// https://leetcode.com/problems/implement-trie-prefix-tree/
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26]; // Array size 26 for lowercase letters
    bool endofword;
    
    TrieNode() {
        endofword = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char w : word) {
            int index = (int)(w - 'a'); // Index for lowercase letters
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->endofword = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char w : word) {
            int index = (int)(w - 'a'); // Index for lowercase letters
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node->endofword;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char p : prefix) {
            int index = (int)(p - 'a'); // Index for lowercase letters
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
