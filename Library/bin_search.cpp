
//  returns first index i, such that fn(i) = true, returns -1 if no true exists
int firstTrue(int l, int r, auto fn, int def = -1) {
    int mid, ans = def;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (fn(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

//  returns last index i, such that fn(i) = true, returns -1 if no true exists
int lastTrue(int l, int r, auto fn, int def = -1) {
    int mid, ans = def;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (fn(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}

auto fn = [&s, &p, &t](int m) {
    string tmp = s;
    for (int i = 0; i <= m; i++)
        tmp[p[i]] = '$';
    string now;
    for (char c : tmp)
        if (c != '$')
            now.pb(c);

    int i = 0, j = 0;
    while (j < t.size() && i < now.size()) {
        if (t[j] == now[i])
            j++;
        i++;
    }
    return j == t.size();

};