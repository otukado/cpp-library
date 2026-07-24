#pragma once
#include<vector>

namespace otukado {


template<typename T>
class Prefix2D {
private:
    std::vector<std::vector<T>> data;
    std::vector<std::vector<T>> prefix_data;
    int h;
    int w;
    
public:
    Prefix2D() = delete;
    Prefix2D(std::vector<std::vector<T>> _data) : data(_data){
        assert(!data.empty());
        h = data.size();
        w = data[0].size();

        prefix_data.resize(h + 1, std::vector<T>(w + 1));
        for(int i = 0; i < h; ++i) {
            assert(w == data[i].size());
            for(int j = 0; j < w; ++j) {
                prefix_data[i + 1][j + 1] = data[i][j];
            }
        }
        calculate();
    };

    void calculate(){
        for(int i = 1; i <= h; ++i) {
            for(int j = 1; j <= w; ++j) {
                prefix_data[i][j] += prefix_data[i][j-1]; // TODO: op
            }
        }
        for(int j = 1; j <= w; ++j) {
            for(int i = 1; i <= h; ++i) {
                prefix_data[i][j] += prefix_data[i-1][j];
            }
        }
    }

    // 閉区間で指定する
    T get(int a, int b, int c, int d) {
        assert(0 <= a && a < h);
        assert(0 <= c && c < h);
        assert(0 <= b && b < w);
        assert(0 <= d && d < w);

        assert(a <= c && b <= d);

        return prefix_data[c + 1][d + 1] + prefix_data[a][b] - prefix_data[a][d + 1] - prefix_data[c + 1][b];
    }

    auto data(){
        return prefix_data;
    }
};


} // namespace otukado
