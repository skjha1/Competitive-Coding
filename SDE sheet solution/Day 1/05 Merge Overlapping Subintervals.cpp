class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector<int>> mergedIntervals; // declearing data structure 
        // edge case 
        if (intervals.size()==0) // when there is no element in intervals we will return empty interval
            return mergedIntervals;
        sort(intervals.begin(),intervals.end()); // 1st of all sort the vector
        vector <int> TempInterval=intervals[0];// store 1st pair from intervals to temp intrvals // vector of size two kept in temp
        for (auto it : intervals) // once sorting done iterate lineraly through all the intervals 
        {
            if(it[0]<=TempInterval[1]) // now check either pairs is merging or or not 
                TempInterval[1]=max(it[1],TempInterval[1]); // whichever is maximum from the rightmost of the it and temp make a pair of that.
            else // if they are not merging 
            {
                mergedIntervals.push_back(TempInterval); // pair which is not merged we are going to take that in merged intervals
                TempInterval=it; // if it does not merges with the pair then replace temp with next iterator 
            }
        }
        mergedIntervals.push_back(TempInterval); // now whatever pair is there in temp data structure will be pushed in fianl result
        return mergedIntervals;
    }
};

// tc o(nlogn)+n
//sc O(n)