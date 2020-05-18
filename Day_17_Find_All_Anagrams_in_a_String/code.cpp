class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> umap ;
        for( auto c : p){
            umap[c] -= 1;
        }

        int j = 0 ;
        vector<int> out ;
        while(j < s.size()){
            int i = j-p.size() ;
            umap[s[j]] += 1;
            if(umap[s[j]] == 0){
                umap.erase(s[j]) ;
            }
            if (i>=0){
                umap[s[i]] -= 1;
                if(umap[s[i]] == 0){
                    umap.erase(s[i]) ;
                }
            }

            if(umap.size()==0){
                out.push_back(i+1);
            }
            j++;
        }
        return out;
    }
};
