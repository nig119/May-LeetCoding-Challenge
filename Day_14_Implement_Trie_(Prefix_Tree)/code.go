type Trie struct {
    arr []*Trie
    end bool
}


/** Initialize your data structure here. */
func Constructor() Trie {
    trie := Trie{}
    trie.arr = make([]*Trie , 26)
    trie.end = false
    return trie
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
    temp := this
    for _,c := range word {

        k := int(c)-'a'
        if temp.arr[k] == nil {
            nxt := Constructor()
            temp.arr[k] = &nxt
        }
        temp = temp.arr[k]
    }
    temp.end = true
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
    if this == nil {
        return false
    }
    temp := this
    for _,c := range word {
        if temp.arr[c-'a'] == nil {
            return false
        }
        temp = temp.arr[c-'a']
    }
    return temp.end
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
     if this == nil {
        return false
    }
    temp := this
    for _,c := range prefix {
        if temp.arr[c-'a'] == nil {
            return false
        }
        temp = temp.arr[c-'a']
    }
    return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
