/*
Question# + Difficulty + Topic + Company + Similar_Question
[56] [Merge Intervals] [Medium] [Array Sort] 
[Google Facebook Microsoft Bloomberg LinkedIn Twitter Yelp ] 
[57 252 253 495 616].cpp
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return intervals;
        vector<Interval> res;
        sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){return a.start<b.start;});  
        //lambda expression for generic sort compare function
        res.push_back(intervals[0]);
        
        for(int i = 1;i<intervals.size();i++)
        {
            if(intervals[i].start>res.back().end) res.push_back(intervals[i]);//disconnected
            else res.back().end = max(res.back().end, intervals[i].end);
        }
               
        return res;   
    }
};
