class Trie {
public:
    /** Initialize your data structure here. */
    Trie* arr[26];
    bool end ;
    Trie() {
        for (int i = 0; i < 26;i++){
            this->arr[i] = nullptr;
        }
        this->end = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto a = this ;
        for(auto w : word) {
            int c = (int)w - 97 ;
            if (a->arr[c] == nullptr){
                a->arr[c] = new Trie() ;
            }
            a = a->arr[c] ;
        }
        a -> end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (this == nullptr) return false  ;
        auto a = this ;
        for(auto w : word){
            int c = (int)w -97 ;
            if(a->arr[c] == nullptr) return false;
            a = a->arr[c] ;
        }
        return a -> end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (this == nullptr) return false;
        auto a = this ;
        for(auto w : prefix){
            int c = (int)w -97 ;
            if(a->arr[c] == nullptr) return false;
            a = a->arr[c] ;
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
