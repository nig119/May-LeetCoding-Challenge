class StockSpanner {
public:
    stack<pair<int,int>> stk ;
    StockSpanner() {
        while (!stk.empty()){
            stk.pop();
        }
    }

    int next(int price) {
        int out = 1 ;
        while(!stk.empty() && stk.top().first <= price ){
            out += stk.top().second ;
            stk.pop();
        }
        stk.push(make_pair(price,out));
        return out;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
