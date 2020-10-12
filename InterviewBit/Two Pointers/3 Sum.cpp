#define ll long long int

int Solution::threeSumClosest(vector<int> &A, int B) 
{
    int n = A.size();
    sort(A.begin(), A.end());

    ll sum = 0, sumt = 0;
    ll diff = LLONG_MAX;
    bool flag=true;
    for (int i = 0; i < n && flag; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            sumt = 1LL * A[i] + A[l] + A[r];
            if (llabs(sumt - B) < diff)
            {
                diff = llabs(sumt - B);
                sum = sumt;
            }
            if (sumt < B)
            {
                l++;
            }
            else if(sumt > B)
            {
                r--;
            }
            else
            {
                flag=false;
                break;
            }
        }
    }
    return sum;
}