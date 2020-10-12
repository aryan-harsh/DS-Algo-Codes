int Solution::maxArea(vector<int> &A) 
{
    if(A.size() == 0 || A.size() == 1)
        return 0;
    int i = 0;
    int j = A.size() - 1;
    int ans = 0;
    while(i < j)
    {
        ans = max(ans, (j - i) * min(A[i], A[j]));
        if(A[i] < A[j])
            i++;
        else
            j--;
    }
    return ans;
}