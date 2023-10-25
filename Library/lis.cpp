template<typename T>
int lis(vector<T>v) {
    set<T>st;
    for (T x : v) {
        auto it = st.lower_bound(x);
        if (it != st.end())
            st.erase(it);
        st.insert(x);
    }
    return (int)(st.size());
}