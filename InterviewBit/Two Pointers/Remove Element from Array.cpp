int Solution::removeElement(vector<int> &A, int B)
{
    int n=A.size();
    if(n==0) return 0;
    if(n==1&&A[0]==B) return 0;
    int i=0;
    while(i<n&&A[i]==B) i++;
    swap(A[0],A[i]);
    int up=0,pp=1;
    while(pp<n)
    {
        if(A[pp]!=B)
        {
            up++;
            swap(A[pp],A[up]);
        }
        pp++;
    }
    return up+1;
}
