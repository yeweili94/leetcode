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
        int size = intervals.size();
        vector<Interval> ret;
        if (size <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), mycompare);
        int left = intervals[0].start, right = intervals[0].end;
        for (int i = 1; i < size; i++) {
            if (intervals[i].start >= left && intervals[i].end <= right) {
                continue;
            } else if (intervals[i].start > right) {
                Interval tmp(left, right);
                ret.push_back(tmp);
                left = intervals[i].start;
                right = intervals[i].end;
            } else {
                right = intervals[i].end;
            }
        }
        Interval tmp(left, right);
        ret.push_back(tmp);
        return ret;
    }

    static bool mycompare(const Interval& I1, const Interval& I2) {
        return I1.start < I2.start;
    }
};
