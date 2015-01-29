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
vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() <= 1) {
        return intervals;
    }
    vector<Interval> ret;
    // sort input according to start
    sort(intervals.begin(), intervals.end(), intervalCompare);
    
    int index = 0;
    
    while (intervals.size() - 1 > index) {
        if (intervals[index].end < intervals[index + 1].start) {
            Interval merged (intervals[index].start, intervals[index].end);
            ret.push_back(merged);
        } else {
            intervals[index + 1].start = intervals[index].start;
            intervals[index + 1].end = max(intervals[index].end, intervals[index + 1].end);
        }
        index++;
    }
    Interval merged (intervals[index].start, intervals[index].end);
    ret.push_back(merged);

    return ret;     
}
    
private:
static bool intervalCompare(Interval small, Interval large) {
    return small.start < large.start;
}

};