#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
//int dx[]={0,0,-1,1};
//int dy[]={-1,1,0,0};
void faster()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
}
#define testCase \
    int t;       \
    cin >> t;    \
    while (t--)



// construction suffix array
vector<int> suffixArrayConstruction(const string &s)
{
    int n = s.size();
    vector<int> suffixArr(n), c(n), cnt(max(256, n), 0), p(n);
    for (int i = 0; i < n; ++i)
        cnt[s[i]]++;
    for (int i = 1; i < 256; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i)
        suffixArr[--cnt[s[i]]] = i;

    c[suffixArr[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; ++i)
    {
        if (s[suffixArr[i]] != s[suffixArr[i - 1]])
            classes++;
        c[suffixArr[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h)
    {
        for (int i = 0; i < n; ++i)
        {
            pn[i] = suffixArr[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }

        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; ++i)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i)
            suffixArr[--cnt[c[pn[i]]]] = pn[i];

        cn[suffixArr[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; ++i)
        {
            pair<int, int> curr = {c[suffixArr[i]], c[(suffixArr[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[suffixArr[i - 1]], c[(suffixArr[i - 1] + (1 << h)) % n]};
            if (curr != prev)
                ++classes;
            cn[suffixArr[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return suffixArr;
}

// Function to construct the LCP("longest common prefix")array using the Kasai algorithm:.......
vector<int> kasaiLCP(const string &s, const vector<int> &suffixArr)
{
    int n = s.size();
    vector<int> lcp(n, 0), rank(n, 0);

    for (int i = 0; i < n; ++i)
    {
        rank[suffixArr[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; ++i)
    {
        if (rank[i] > 0)
        {
            int j = suffixArr[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h])
                ++h;
            lcp[rank[i]] = h;
            if (h > 0)
                --h;
        }
    }
    return lcp;
}
// count distinct substring ..............
int countDistinctSubstrings(const string &s)
{
      int n = s.size();
    auto suffixArr = suffixArrayConstruction(s);
    auto lcp = kasaiLCP(s, suffixArr);

    int totalSubstrings = n * (n + 1) / 2;
    for (int i = 1; i < n; ++i)
    {
        totalSubstrings -= lcp[i];
    }
    return totalSubstrings;
}
int32_t main()
{
     faster();
     string s;
     cin>>s;
     s+='$';
     cout << countDistinctSubstrings(s) << endl;

             
}