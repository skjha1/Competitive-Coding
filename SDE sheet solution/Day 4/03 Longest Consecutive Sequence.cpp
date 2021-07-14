class Solution {
public:
   int longestConsecutive(vector<int> &num) {
    if(num.empty()){
        return 0;
    }
    unordered_set<int> set;
    for(int i = 0; i < num.size(); i++){
        set.insert(num[i]);
    }
    int maxLength = 0;
    while(!set.empty()){
        int length = 1;
        unordered_set<int>::iterator seed = set.begin();
        for(int i = *seed;; i--){
            if(set.find(i - 1) != set.end()){
                length++;
                set.erase(i - 1);
            }
            else{
                break;
            }
        }
        for(int i = *seed;; i++){
            if(set.find(i + 1) != set.end()){
                length++;
                set.erase(i + 1);
            }
            else{
                break;
            }
        }
        set.erase(*seed);
        maxLength = max(maxLength, length);
    }
    return maxLength;
}
        
    
};
