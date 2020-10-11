void Solution::sortColors(vector<int> &A) 
{
    int n=A.size();
    int zp=-1,op,tp=n;
    while(zp<n&&A[zp+1]==0) zp++;
    while(tp>-1&&A[tp-1]==2) tp--;
    for(int i=0;i<n;i++)
    {
        if(i<n&&A[i]==0&&i>zp) 
        {
            swap(A[zp+1],A[i]);
            zp++;
            i--;
        }
        if(A[i]==2&&i<tp)
        {
            swap(A[tp-1], A[i]);
            tp--;
            i--;
        }
    }
}