#pragma once
#include<vector>
#include <cassert>
#include <type_traits>

namespace otukado {


template<typename T, auto e, auto op>
class SegmentTree {
private:
    int n;
    int size;
    std::vector<T> data;

    static T identity() {
        if constexpr (std::is_invocable_r_v<T, decltype(e)>) {
            return e();
        } else {
            return e;
        }
    }
    
public:
    class Proxy {
    private:
        SegmentTree& seg;
        int index;

    public:
        Proxy(SegmentTree& seg, int index) : seg(seg), index(index) {}
        // 代入時
        Proxy& operator=(const T& val) {
            seg.update(index, val);
            return *this;
        }

        // 値読み取り時
        operator T() const {
            return seg.at(index);
        }

        Proxy& operator=(const Proxy& other) {
            return *this = static_cast<T>(other);
        }
    };

    T at(int p) const {
        assert(0 <= p && p < n);
        p += size;
        return data[p];
    }

    void update (int p, T x) {
        assert(0 <= p && p < n);
        p += size;
        data[p] = x;
        while(p > 1) {
            p /= 2;
            data[p] = op(data[p * 2], data[p * 2 + 1]);
        }
    }


    Proxy operator[](int index) {
        return Proxy(*this, index);
    }

    T operator[](int index) const {
        return at(index);
    }


    SegmentTree(int n) : n(n) {
        assert(n >= 0);
        size = 1;
        while(size < n) size *= 2;
        data.assign(size * 2, identity());
    };

    T range(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);

        T left = identity();
        T right = identity();
        int i = 0;
        while(l != r) {
            if(l & (1 << i)) {
                int target = (size >> i) + (l >> i);
                l += (1 << i);
                left = op(left, data[target]);
            }

            if(r & (1 << i)) {
                int target = (size >> i) + (r >> i) - 1;
                r -= (1 << i);
                right = op(data[target], right);
            }

            i++;
        }

        return op(left, right);
    }

    T all_range() const {
        return data[1];
    }
};

} // namespace otukado
