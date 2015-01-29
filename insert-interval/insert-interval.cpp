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
// After implementing merge-intervals, you only need to insert the newInterval and then merge
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    // insert
    int insertIndex = getInsertIndex(intervals, newInterval);
    vector<Interval>::iterator it = intervals.begin() + insertIndex;
    intervals.insert(it, newInterval);
    
    vector<Interval> ret;
    // merge
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
    // push the last interval
    Interval merged (intervals[index].start, intervals[index].end);
    ret.push_back(merged);
    return ret; 
}
    
private:
// Binary search
int getInsertIndex(vector<Interval> &intervals, Interval newInterval) {
    if (intervals.size() == 0) {
        return 0;
    }
    if (intervals.size() == 1) {
        if (intervals[0].start > newInterval.start) {
            return 0;
        } else {
            return 1;
        }
    }
    int start = 0;
    int end = intervals.size() - 1;
    int mid = (start + end) / 2;
    while (start + 1 < end) {
        mid = (start + end) / 2;
        if (intervals[mid].start > newInterval.start) {
            end = mid;
        } else {
            start = mid;
        }
    }
    return getInsertIndex(intervals, start, end, newInterval);
}

// search the exact position between startIndex and endIndex
int getInsertIndex(vector<Interval> &intervals, int startIndex, int endIndex, Interval newInterval) {
    int index = startIndex;
    while (index <= endIndex) {
        if (newInterval.start < intervals[index].start) {
            break;
        }
        index++;
    }
    return index;
}

};