struct TrieNode{
    TrieNode *child[26];
    bool isWord=false;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for(auto &c:word){
            if(!cur->child[c-'a']){
                cur->child[c-'a'] = new TrieNode();
            }
            cur = cur->child[c-'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(auto &c:word){
            if(!cur->child[c-'a']){
                return false;
            }
            cur = cur->child[c-'a'];
        }
        if(cur->isWord)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(auto &c:prefix){
            if(!cur->child[c-'a']){
                return false;
            }
            cur = cur->child[c-'a'];
        }
        
        return true;
    }
private:
    TrieNode *root;
};
