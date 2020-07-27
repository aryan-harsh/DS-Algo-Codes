vector<int> Solution::plusOne(vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size(),carry=0;
    vector<int>res;
    res.push_back((1+A[n-1])%10);
    carry=(1+A[n-1])/10;
    for(int i=n-2;i>=0;i--){
        res.push_back((carry+A[i])%10);
        carry=(carry+A[i])/10;
    }
    if(carry)
     res.push_back(carry);
    int x=res.size();
    for(int i=0;i<x/2;i++)
     swap(res[i],res[x-i-1]);
    while(res[0]==0){
       res.erase(res.begin());
    }
    return res;
}
