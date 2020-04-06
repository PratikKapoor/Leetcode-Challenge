class Solution {
public:
    /**
    * Get encoded version of anagram.
    */
    string getEncodedString(string anagram) {
        map<char, int> frequencyMap;
        
        // Count frequency of characters.
        for(int i=0;i<anagram.length();i++) {
            frequencyMap[anagram[i]-'a'] += 1;    
        }
        
        // Create a hashable representation of the type #x#y#z
        // where x,y,z represent frequency of character in that position.
        string encoded_anagram = "";
        for(int i=0;i<26;i++) {
            encoded_anagram += "#" + to_string(frequencyMap[i]);
        }
        
        return encoded_anagram;
    }
    
    /**
    * Method to group all anagrams.
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagramBucket;
        
        // Group all strings with the same hashed representation together.
        for(int i=0;i<strs.size();i++) {
            anagramBucket[getEncodedString(strs[i])].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        std::map<string, vector<string>>::iterator it = anagramBucket.begin();
        
        // Create vectors of anagrams for result.
        while(it != anagramBucket.end()) {
            vector<string> anagrams;
            anagrams = it->second;
            result.push_back(anagrams);
            it++;
        }
        
        return result;
    }
};
