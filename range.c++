#include <iostream>
using namespace std;

class Range{
private:
    int lo;
    int hi;

public:
    Range() {
        lo = hi = 0;
    }

    Range(int start, int end) {
        lo = min(start, end);
        hi = max(start, end);
    }

    Range(int end) {
        lo = 0;
        hi = end;
    }

    int getLo() {
        return lo;
    }

    int getHi() {
        return hi;
    }

    void reset() {
        lo = hi = 0;
    }

    void rStretch() {
        hi++;
    }

    void rStretch(int n) {
        hi += n;
    }

    void lStretch() {
        lo--;
    }

    void lStretch(int n) {
        lo -= n;
    }

    void stretch() {
        lo--;
        hi++;
    }

    void stretch(int n) {
        lo -= n;
        hi += n;
    }

    void squeeze() {
        lo++;
        hi--;
        if (lo > hi) {
            reset();
        }
    }

    void squeeze(int n) {
        lo += n;
        hi -= n;
        if (lo > hi) {
            reset();
        }
    }

    void shift(int n) {
        lo += n;
        hi += n;
    }

    int length() {
        return hi - lo + 1;
    }

    bool contains(int x) {
        return lo <= x && x < hi;
    }

    bool contains(Range r) {
        return lo <= r.lo && r.hi <= hi;
    }

    bool equals(Range r) {
        return lo == r.lo && hi == r.hi;
    }

    bool isDisjoint(Range r) {
        return lo > r.hi || hi < r.lo;
    }

    bool isOverlapping(Range r) {
        return !isDisjoint(r);
    }

    bool lessThan(Range r) {
        return lo < r.lo;
    }

    Range merge(Range r) {
        if (isDisjoint(r)) {
            Range* mergedRange = new Range();
            return *mergedRange;
        }

        int a = min(lo, r.lo);
        int b = max(hi, r.hi);

        Range* mergedRange = new Range(a, b);
        return *mergedRange;
    }

    // Range common(Range r) {
    //     if (isDisjoint(r)) {
    //         Range* commonRange = new Range();
    //         return *commonRange;
    //     }

    //     std::vector<std::int> extremes(4);
    //     extremes[0] = lo;
    //     extremes[1] = r.lo;
    //     extremes[2] = hi;
    //     extremes[3] = r.hi;

    //     sort(extremes.begin(), extremes.end());

    //     Range* commonRange = new Range(extremes[1], extremes[2]);
    //     return *commonRange;
    // }
};