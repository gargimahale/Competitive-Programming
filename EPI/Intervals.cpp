#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start, end;
    Interval(int _start, int _end): start(_start), end(_end) {}
};

class MergeAddIntervals {
public:
    void display(vector<Interval>& t) const {
        for (int i = 0; i < t.size(); ++i) {
            cout << t[i].start << " " << t[i].end << "\n";
        }
    }

    void addInterval(vector<Interval>& times, Interval& slot) const {
        int n = times.size();
        if (n == 0) return;
        vector<Interval> ans;

        for (int i = 0; i < n; ++i) {
            if (slot.start > times[i].end) {
                ans.push_back(times[i]);
            }
            else if (slot.end < times[i].start) {
                ans.push_back(slot);
                slot.start = times[i].start;
                slot.end = times[i].end;
            }
            else {
                slot.start = min(slot.start, times[i].start);
                slot.end = max(slot.end, times[i].end);
            }
        }
        ans.push_back(slot);
        display(ans);
    }

    void mergeIntervals(vector<Interval>& times) const {
        int n = times.size();
        vector<Interval> ans;
        if (n == 0) return;

        sort(times.begin(), times.end(), [&](const Interval & a, const Interval & b) {
            return a.start == b.start ? a.end < b.end : a.start < b.start;
        });

        int first = times[0].start, second = times[0].end;

        for (int i = 1; i < n; ++i) {
            if (times[i].start > second) {
                ans.emplace_back(first, second);
                first = times[i].start;
                second = times[i].end;
            }
            else if (times[i].start >= first && times[i].start <= second) {
                first = min(first, times[i].start);
                second = max(second, times[i].end);
            }
        }
        ans.emplace_back(first, second);
        cout << "Non-Overlapping Intervals:\n";
        display(ans);


        int a, b;
        cin >> a >> b;
        Interval inp(a, b);
        cout << "After adding New Interval, Non-Overlapping Intervals:\n";
        addInterval(ans, inp);
    }
};

int main(void) {
    MergeAddIntervals ma;
    vector<Interval> arr;
    for (int i = 0; i <= 5; ++i) {
        int a, b;
        cin >> a >> b;
        Interval in(a, b);
        arr.emplace_back(in);
    }
    cout << "\n";
    ma.mergeIntervals(arr);
}