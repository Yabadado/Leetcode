class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];
    TrieNode() {
        isWord = false;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode *tmp = root;
        for(char c:word){
            if(!tmp->child[c-'a']){
                tmp->child[c-'a'] = new TrieNode();
            }
            tmp = tmp->child[c-'a'];
        }
        tmp->isWord = true;
    }
    
    bool search(string word) {
        return _search(root, word, 0);
    }
    
    bool _search(TrieNode *node, string &word, int idx){
        if(!node)
            return false;
        
        if(idx==word.size()){
            return node->isWord;
        }
        
        if(word[idx]=='.'){
            for(auto next_node:node->child)
                if(_search(next_node, word, idx+1))
                    return true;
        }
        else{
            char ch = word[idx]-'a';
            if(node->child[ch])
                return _search(node->child[word[idx]-'a'], word, idx+1);
        }
        return false;
    }
    
    TrieNode *root = new TrieNode();
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
