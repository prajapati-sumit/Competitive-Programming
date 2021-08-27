#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree < T ,  null_type ,  less<T> ,  rb_tree_tag ,  tree_order_statistics_node_update >;


int main(){

    ordered_set<int> os;
    os.insert(4);
    os.insert(1);
    os.insert(5);
    cout<<os.order_of_key(4)<<'\n';
    return 0;
}