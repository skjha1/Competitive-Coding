class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {        
        // Return 0 if string is empty
        if( s == "") { return 0; }
        
        // Hash table for storing characters and count dublicates
        std::map<char, int> charactersOfSubstr;       
        
        // Longest sequence that will be returned in the end
        int longest = 0;
        int j = 0;
        
        // Each character from string add to HashTable: for dublicates increase value that used in result calculation
        for (int i = 0; i < s.length(); ++i)
        {
            // Try to find character in the HashTable
            // If current character already exist in the HashTable - increment value
            if ( charactersOfSubstr.find(s[i]) != charactersOfSubstr.end() )
            {
                charactersOfSubstr.find(s[i])->second++;
            }
            // Othervise add it to HashTable
            else
            {
                charactersOfSubstr.insert(pair<char, int>(s[i], 1));
            }
            
            // ONLY if in HashTable exist several same characters:
            // decrease ALL characters between j and i in HashTable AND increase j for calculation while s[i] value in Hash table > 1
            while ( charactersOfSubstr.find(s[i])->second > 1 )
            {
                // Descrease value of existing character
                charactersOfSubstr.find(s[j])->second--;
                // Increase j for future calculation
                ++j;
            }
            
            // longest will be chosen between larger value: old longest OR current sequance (i - j + 1)
            longest = longest >= i - j + 1 ? longest : i - j + 1;
        }
        
        return longest;
    }
};
