#include <bits/stdc++.h>
using namespace std;

template<class T, size_t ...sz>
class shit;

template<class T, size_t sz0>
class shit<T, sz0> {
public:
    static const size_t prod = sz0;
    T* ptr;
    T& operator[](size_t off) {
        return ptr[off];
    }  
};


template<class T, size_t sz0, size_t ...sz>
class shit<T, sz0, sz...> {
public:
    static const size_t prod = shit<T, sz...>::prod * sz0;
    T* ptr;
    shit<T, sz...> operator[](size_t off) {
        return shit<T, sz...>{ptr + off * shit<T, sz...>::prod};
    }
};

int main(void) {
    int arr[2][3][5];

    memset(arr, 0, sizeof(arr));

    arr[1][2][3] = 114514;

    int* p = &arr[0][0][0];

    cout << shit<int, 2, 3, 5>{p}[1][2][4] << endl;

    return 0;
}