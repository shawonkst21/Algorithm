#include<bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
#define testCase \
    int t;       \
    cin >> t;    \
    while (t--)
void faster() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<int>ans;
vector<int> createLpsArray(const string& pat) {
    vector<int> lps(pat.size());
    int index = 0;
    lps[0] = 0;
    for (int i = 1; i < pat.size();) {
        if (pat[index] == pat[i]) {
            lps[i] = index + 1;
            ++i;
            ++index;
        } else {
            if (index != 0) {
                index = lps[index - 1];
            } else {
                lps[i] = index;
                ++i;
            }
        }
    }
    return lps;
}

void kmp(const string& text, const string& pat) {
    vector<int> lps = createLpsArray(pat);
    int i = 0;
    int j = 0; 
    int count = 0;

    while (i < text.size()) {
        if (pat[j] == text[i]) {
            ++i;
            ++j;
        }

        if (j == pat.size()) {
            ans.push_back(i-pat.size());
            j = lps[j - 1];
        } else if (i < text.size() && pat[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }
    if(ans.size()==0)
    {
        cout<<"Not Found"<<endl;
        cout<<endl;
    }
    else
    {
        cout<<ans.size()<<endl;
        for(auto i:ans)
        {
            cout<<i+1<<' ';
        }cout<<endl;
        cout<<endl;
    }

    return;
}

int32_t main() {
    faster();
    testCase
    {
         string text, pat;
         cin >> text >> pat;
         kmp(text, pat);
         ans.clear();
         
    }
   
}
