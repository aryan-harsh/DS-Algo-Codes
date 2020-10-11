#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define MOD 1000000007

vector<int> Solution::maxone(vector<int> &A, int B) 
{
    int n = A.size();
    int fp = 0;
    int sp = 0;
    int c = 0;
    int maxl = INT_MIN;
    int beg, end;
    while (sp < n)
    {
        // cout << "fp : " << fp << " & sp : " << sp << "\n";
        if (A[sp] == 0)
        {
            if (c < B)
            {
                c++;
            }
            else
            {
                while(A[fp]==1) fp++;
                fp++;
            }
        }
        if (sp - fp + 1 > maxl)
        {
            maxl = sp - fp + 1;
            beg = fp;
            end = sp;
            // cout << "maxl : " << maxl << "\n";
        }
        sp++;
    }
    vector<int> ans;
    for (int i = beg; i <= end; i++)
    {
        ans.eb(i);
    }
    return ans;
}
