#pragma once

#include <cassert>
#include <type_traits>

namespace otukado {


template<typename T, typename F>
T BinarySearch(T ng, T ok, F pred) {
    assert(ng != ok);
    T mid;
    while(std::abs(ng - ok) > 1) {
        mid = (ng + ok) / 2;

        if(pred(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok;
}


} // namespace otukado
