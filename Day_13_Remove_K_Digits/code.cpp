class Solution {
public:
  string removeKdigits(string num, int k) {
      if (k==0) return num;
      if (k == num.size()) return "0";

        string out = "";
        int i = 0;
        while(i < num.size()){
            while (out.size() > 0 && k > 0 && out[out.size()-1]> num[i] ) {
                out.pop_back();
                k--;
            }
            out.push_back(num[i]);
            i++ ;
        }
      while(k!=0){
          out.pop_back();
          k--;
      }
      int j = 0 ;
      while(out[j]=='0'){
          j++;
      }
      if(out.substr(j).size()==0){
          return "0";
      }
      return out.substr(j);
    }
};
