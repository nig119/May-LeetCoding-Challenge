func findAnagrams(s string, p string) []int {
    umap := make(map[byte]int)
    for k:=0 ; k < len(p) ; k++ {
        umap[p[k]] -= 1
    }
    j := 0
    var out []int
    for j < len(s) {
        i := j-len(p)
        umap[s[j]] += 1
        if umap[s[j]] == 0 {
            delete (umap,s[j])
        }
        if i>=0 {
            umap[s[i]] -= 1
            if umap[s[i]] ==0 {
                delete(umap,s[i])
            }
        }
        if len(umap) == 0 {
            out = append(out,i+1)
        }
        j++
    }
    return out
}
