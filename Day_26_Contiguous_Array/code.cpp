class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> umap ;
        umap[0] = -1 ;
        int sum = 0 ;
        int out = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += (nums[i]==1)?1:-1 ;
            if (umap.find(sum)!=umap.end()){
                out = max (i - umap[sum], out ) ;
            }else {
                umap[sum] = i ;
            }
        }
        return out;

    }
};
