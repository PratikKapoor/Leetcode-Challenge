class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Converting vector into a heap 
        // using make_heap() 
        make_heap(stones.begin(), stones.end()); 
        
        while(stones.size() >= 2) {
            // Get heavier stone from heap.
            int heavy_stone = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back(); 
            
            // Get second heavier stone.
            int light_stone = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back(); 
            
            // If both are equal, both will be destroyed. 
            // If not, the difference in weights will be the weight
            // of the stone added.
            if (heavy_stone != light_stone) {
                stones.push_back(heavy_stone - light_stone);
                push_heap(stones.begin(), stones.end());
            }
        }
        
        if(stones.size()>0) {
            return stones.front();
        } else {
            return 0;
        }
    }
};
