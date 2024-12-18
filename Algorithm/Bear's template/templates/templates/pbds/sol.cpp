#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <bits/stdc++.h>
using namespace std;
typedef __gnu_pbds::priority_queue<int, greater<int>> heap;
typedef heap::point_iterator iter;

void heap_test() {
    heap h;
    iter it = h.push(2);
    printf("%d\n", h.top());
    h.push(1);
    printf("%d\n", h.top());
    h.modify(it, 0);
    printf("%d\n", h.top());
}

namespace pbds = __gnu_pbds;

typedef __gnu_pbds::tree<int, pbds::null_type, less<int>, pbds::rb_tree_tag, pbds::tree_order_statistics_node_update> tree;

void rbt_test() {
    tree t;
    for (int i = 1; i <= 5; ++i)
        t.insert(2 * i - 1);
    printf("%d\n", t.order_of_key(0));
    printf("%d\n", t.order_of_key(1));
    printf("%d\n", t.order_of_key(2));
    printf("%d\n", *t.find_by_order(0));
    printf("%d\n", *t.find_by_order(1));
    printf("%d\n", *t.find_by_order(2));
}

int main(void){
    rbt_test();
    return 0;
}