#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class SegmentTree
{
    private:

    int size;
    vector<int> val;

    /* Change this function for updating nodes */

    int update(int f, int s)
    {
        return (f + s);
    }

    int get(int l, int r, int x, int lx, int rx)
    {
        if(lx>=r||rx<=l) return 0;
        if(lx>=l&&rx<=r)
        {
            return val[x];
        }

        int m = (lx + rx)/2;

        int a = get(l, r, 2*x + 1, lx, m);
        int b = get(l, r, 2*x + 2, m, rx);

        return update(a, b);
    }

    
    void set(int l, int r, int v, int x, int lx, int rx)
    {
        if( lx >= r || rx <= l) return;
        if( lx >= l && rx <= r)
        {
            val[x] += v;
            return;
        }

        int m = (lx + rx)/2;

        set(l, r, v, 2*x + 1, lx, m);
        set(l, r, v, 2*x + 2, m, rx);

        val[x] = update(val[2*x + 1], val[2*x + 2]);
    }

    void init(int n)
    {
        size = 1;
        while(size<=n) size *= 2;
        val.assign(2*size, 0LL);
    }

    public:

    SegmentTree(int n)
    {
        init(n);
    }

    int get(int l, int r)
    {
        return get(l, r, 0, 0, size);
    }
    void set(int l, int v)
    {
        set(l, l + 1, v, 0, 0, size);
    }
};
