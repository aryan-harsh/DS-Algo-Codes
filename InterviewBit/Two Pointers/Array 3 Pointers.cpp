#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define MOD 1000000007

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) 
{
    ll min = LLONG_MAX;
    int p1 = A.size() - 1, p2 = B.size() - 1, p3 = C.size() - 1;
    ll ab, bc, ca, maxt;
    while (p1 > -1 && p2 > -1 && p3 > -1)
    {
        ab = llabs(1LL * A[p1] - B[p2]);
        bc = llabs(1LL * B[p2] - C[p3]);
        ca = llabs(1LL * C[p3] - A[p1]);
        maxt = max(max(ab, bc), ca);
        if (maxt<min)
        {
            min=maxt;
        }
        if (maxt==ab)
        {
            if (A[p1]>=B[p2])
            {
                p1--;
            }
            else p2--;
        }
        else if (maxt==bc)
        {
            if (B[p2]>=C[p3])
            {
                p2--;
            }
            else p3--;
        }
        else
        {
            if (C[p3]>=A[p1])
            {
                p3--;
            }
            else p1--;
        }
    }
    return min;
}
