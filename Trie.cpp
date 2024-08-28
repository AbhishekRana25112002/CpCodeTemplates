#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : child) a = NULL;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string s) {
        TrieNode* p = root;
        for (auto &a : s) {
            int i = a - 'a';
            if (!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    bool search(string key, bool prefix = false) {
        TrieNode* p = root;
        for (auto &a : key) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        if (!prefix) return p->isWord;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
    
    bool deleteWord(string word) {
        return deleteWordHelper(root, word, 0);
    }

private:
    bool deleteWordHelper(TrieNode* node, string& word, int depth) {
        if (!node) return false;

        if (depth == word.length()) {
            if (!node->isWord) return false; // Word not present in the trie

            node->isWord = false;

            // If the node has no other children, it can be deleted
            for (int i = 0; i < 26; i++) {
                if (node->child[i]) return false;
            }
            return true;
        }

        char ch = word[depth];
        TrieNode* childNode = node->child[ch - 'a'];
        if (!childNode) return false; // Word not present in the trie

        // Recursively delete the word
        bool shouldDeleteChild = deleteWordHelper(childNode, word, depth + 1);

        // Delete the child node if necessary
        if (shouldDeleteChild) {
            delete node->child[ch - 'a'];
            node->child[ch - 'a'] = NULL;

            // Check if the current node has no other children and can be deleted
            for (int i = 0; i < 26; i++) {
                if (node->child[i]) return false;
            }
            return !node->isWord;
        }

        return false;
    }
};

int main() {
    Trie trie;
    vector<string> words = {"ravi", "abhi", "abhishek", "ayush", "ayushman", "abhirana"};
    for (auto w : words) {
        trie.insert(w);
    }
    
    trie.deleteWord("abhishek");
    cout << trie.search("abhi") << endl;
}
