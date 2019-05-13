class Trie {
public:
    /** Initialize your data structure here. */
    // runtime 76ms storage 47.2mb
    struct TrieNode
    {
        TrieNode** children;
        
        // set to false by default
        bool endOfWord;
        
        TrieNode()
            :children(new TrieNode* [26]), endOfWord(false)
            {
                for (int i = 0; i < 26; ++i)
                {
                    children[i] = nullptr;
                }
            }
    };
    
    TrieNode* root;
    
    Trie() 
        :root(new TrieNode())
    {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        // iterate through all characters in word, and traverse the trie at the same time. if the current TrieNode has an entry for the current character, go into it. but if not, create an entry and go into that
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            // if there isn't an entry for this character, make one.
            if (!temp->children[index])
            {
                temp->children[index] = new TrieNode();
            }
            // go into the TrieNode entry for this character
            temp = temp->children[index];
        }
        // inserted the entire word, mark this node as the end of a word.
        temp->endOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            // did not find the current letter in trie; return false
            if (!temp->children[index])
                return false;
            // found current letter in trie; enter that TrieNode
            temp = temp->children[index];
        }
        // reached the end of word, and all letters were found in trie. however, the word is found only if the ending TrieNode is an 'end of word' node. 
        return temp->endOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            int index = prefix[i] - 'a';
            if (!temp->children[index])
                return false;
            temp = temp->children[index];
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