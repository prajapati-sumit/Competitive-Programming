#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<assert.h>


class MinHeap {
    const int max_size = 1e4 + 2;
    int cur_size;
    T* a;
    int p(int idx) {
        return idx >> 1;
    }
    int l(int idx) {
        return (idx << 1);
    }
    int r(int idx) {
        return (idx << 1) + 1;
    }
    void swap(T& A, T& B) {
        T W = A;
        A = B;
        B = W;
    }
    void up_heapify(int idx) {

        while (idx > 1 && a[idx] < a[p(idx)]) {
            swap(a[idx], a[p(idx)]);
            idx = p(idx);
        }
    }
    void down_heapify(int idx) {
        while (l(idx) <= cur_size) {
            int lc = l(idx), rc = r(idx);
            int child = (lc == cur_size || a[lc] <= a[rc] ? lc : rc);

            if (a[child] < a[idx]) {
                swap(a[child], a[idx]);
                idx = child;
            }
            else
                break;
        }
    }
public:
    MinHeap(int n) {
        a = new T[n + 1];
    }
    MinHeap() {
        cur_size = 0;
        a = new T[max_size];
    }
    MinHeap(T b[], int n) {

        a = new T[n + 1];
        cur_size = n;
        for (int i = 1; i <= n; i++)
            a[i] = b[i];
        for (int i = n / 2 + 1; i >= 1; i--)
            down_heapify(i);

        for (int i = 1; i <= n; i++)
            b[i] = a[i];
    }

    void push(T x) {

        if (cur_size >= max_size) {
            cout << "Heap Overflow\n";
            return;
        }
        cur_size++;
        a[cur_size] = x;
        up_heapify(cur_size);
    }
    void pop() {
        if (cur_size == 0) {
            cout << "Heap UnderFlow\n";
            return;
        }
        a[1] = a[cur_size];
        cur_size--;
        down_heapify(1);
    }
    T top() {
        if (cur_size == 0) {
            cout << "Heap UnderFlow\n";
            return T();
        }
        return a[1];
    }
    bool empty() {
        return cur_size == 0;
    }
    int size() {
        return cur_size;
    }
};


int main() {

    return 0;
}