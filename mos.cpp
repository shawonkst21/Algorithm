#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXQ = 50000;

int arr[MAXN], freq[MAXN], answers[MAXQ], block_size, distinct_count;
struct Query {
    int L, R, index;
};

bool cmp(Query a, Query b) {
    if (a.L / block_size != b.L / block_size)
        return a.L / block_size < b.L / block_size;
    return a.R < b.R;
}

void add(int position) {
    if (freq[arr[position]] == 0)
        distinct_count++;
    freq[arr[position]]++;
}

void remove(int position) {
    if (freq[arr[position]] == 1)
        distinct_count--;
    freq[arr[position]]--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int n, q;
        cin >> n >> q;

        block_size = sqrt(n);
        vector<Query> queries(q);
        
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        for (int i = 0; i < q; i++) {
            cin >> queries[i].L >> queries[i].R;
            queries[i].L--; // convert to 0-based index
            queries[i].R--; // convert to 0-based index
            queries[i].index = i;
        }
        
        sort(queries.begin(), queries.end(), cmp);
        
        memset(freq, 0, sizeof(freq));
        distinct_count = 0;
        
        int currentL = 0, currentR = -1;
        
        for (int i = 0; i < q; i++) {
            int L = queries[i].L;
            int R = queries[i].R;
            
            while (currentL < L) {
                remove(currentL);
                currentL++;
            }
            while (currentL > L) {
                currentL--;
                add(currentL);
            }
            while (currentR < R) {
                currentR++;
                add(currentR);
            }
            while (currentR > R) {
                remove(currentR);
                currentR--;
            }
            
            answers[queries[i].index] = distinct_count;
        }
        
        cout << "Case " << test_case << ":\n";
        for (int i = 0; i < q; i++) {
            cout << answers[i] << "\n";
        }
    }
    return 0;
}
