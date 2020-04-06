class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> anagrams;
        
        for(int i=0;i<strs.size();i++) {
            map<char, int> freqmap;
            for(int j=0;j<strs[i].length();j++) {
                freqmap[strs[i][j]] += 1;
            }
            
            if(anagrams.find(freqmap)==anagrams.end()) {
                vector<string> anagramlist;
                anagramlist.push_back(strs[i]);
                anagrams[freqmap] = anagramlist;
            } else {
                anagrams[freqmap].push_back(strs[i]);
            }
        }
        
        vector<vector<string>> result;
        
        std::map<map<char, int>, vector<string>>::iterator it = anagrams.begin();
 
        // Iterate over the map using Iterator till end.
        while (it != anagrams.end()) {
            //cout<<it->second[0]<<endl;
            result.push_back(it->second);
            it++;
        }
        
        return result;
    }
};
