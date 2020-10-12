
#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define MOD 1000000007

vector<vector<int> > Solution::threeSum(vector<int> &A) 
{
    std::vector<int> vtemp;
    std::vector<std::vector<int> > ans;
    int n=A.size();
    sort(A.begin(),A.end());

    ll sum=0;
    for(int i=0;i<n;i++)
    {
        vector<int> v;
        int l=i+1, r=n-1;
        while(l<r)
        {
            v.clear();
            sum=1LL*A[i]+A[l]+A[r];
            if (sum==0)
            {
                v.eb(A[i]);
                v.eb(A[l]);
                v.eb(A[r]);
                ans.eb(v);
                l++;
                r--;
                while(l<r&&A[l]==A[l-1]) l++;
                while(r>l&&A[r]==A[r+1]) r--;
            }
            else if (sum<0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        while(i+1<n&&A[i+1]==A[i]) i++;
    }
    return ans;
}
