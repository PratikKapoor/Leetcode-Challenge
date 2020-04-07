class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int> elementCount;
        
        for(int i=0;i<arr.size();i++) {
            elementCount[arr[i]] += 1;
        }
        
        int count = 0;
        
        for(int i=0;i<arr.size();i++) {
            count += elementCount[arr[i] - 1];
            elementCount[arr[i] - 1] = 0;
        }
        
        return count;
    }
};
