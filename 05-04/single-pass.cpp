class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int size = prices.size();
        
        for(int i=0;i<size;i++) {
            int temp = i+1;
            
            while(temp<size && prices[temp]>prices[temp-1]) {
                temp += 1;
            }
            //cout<<i<<" "<<temp-1<<endl;
            sum += prices[temp-1] - prices[i];
            i = temp-1;            
        }
        
        return sum;
    }
};
