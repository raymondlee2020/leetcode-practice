struct TrieNode {
    TrieNode* children[26];
    bool isEnd = false;
    TrieNode* get(char c) {
        return children[c - 'a'];
    }
    void add(char c) {
        children[c - 'a'] = new TrieNode();
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(): root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode* curr = root;
        for (const char c: word) {
            if (curr->get(c) == NULL) {
                curr->add(c);
            }
            curr = curr->get(c);
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (const char c: word) {
            if (curr->get(c) == NULL) {
                return false;
            }
            curr = curr->get(c);
        }
        return curr->isEnd == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (const char c: prefix) {
            if (curr->get(c) == NULL) {
                return false;
            }
            curr = curr->get(c);
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