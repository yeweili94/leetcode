/*
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (29.57%)
 * Total Accepted:    138.6K
 * Total Submissions: 468.7K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int size = intervals.size();
        int cur = 0;
        vector<Interval> ret;
        while (cur < size && intervals[cur].end < newInterval.start) {
            ret.push_back(intervals[cur++]);
        }
        while (cur < size && newInterval.end >= intervals[cur].start) {
            newInterval.start = min(newInterval.start, intervals[cur].start);
            newInterval.end = max(newInterval.end, intervals[cur].end);
            cur++;
        }
        ret.push_back(newInterval);
        while (cur < size) {
            ret.push_back(intervals[cur++]);
        }
        return ret;
    }
};
