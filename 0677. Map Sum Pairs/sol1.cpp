/*
using trie
*/

class MapSum {
public:
    /* Trie */
    struct TrieNode{
        char c;
        int sum=0;
        TrieNode *child[26];
    };
    
    TrieNode *root = NULL;
    
    TrieNode *CreateNode(char c){
        TrieNode *tmp = new TrieNode;
        tmp->c = c;
        for(int i=0;i<26;i++)
            tmp->child[i]=NULL;
        return tmp;
    }
    
    void insertNode(string key, int val){
        TrieNode *tmp = root;
        for(auto &c: key){
            if(tmp->child[c-'a']==NULL)
                tmp->child[c-'a'] = CreateNode(c);
            tmp = tmp->child[c-'a'];
        }
        tmp->sum = val;
    }
    
    int getSum(TrieNode* start){
        if(!start)    
            return 0;
        int sum = start->sum;
        for(int i=0; i<26; i++)
            sum += getSum(start->child[i]);
        return sum;
    }
    
    
    /** Initialize your data structure here. */
    MapSum() {
        root = CreateNode('*');
    }
    
    void insert(string key, int val) {
        insertNode(key, val);
    }
    
    int sum(string prefix) {
        TrieNode* pCrawl = root;
        for(char &ch : prefix) {
            if(pCrawl->child[ch-'a'] == NULL)
                return 0;
            pCrawl = pCrawl->child[ch-'a'];
        }
        
        return pCrawl == NULL ? 0 : getSum(pCrawl);
    }
    
    
};