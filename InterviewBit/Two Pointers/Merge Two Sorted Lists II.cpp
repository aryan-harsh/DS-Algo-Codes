void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> c;
    int a=0,b=0;
    while(1)
    {
        if(b<B.size()&&a<A.size()&&A[a]<B[b]) 
        {
            c.push_back(A[a]);
            a++;
        }
        else if(b<B.size())
        {
            c.push_back(B[b]);
            b++;
        }
        else if(a<A.size())
        {
            c.push_back(A[a]);
            a++;
        }
        if(c.size()==A.size()+B.size()){
            A=c;
            return;
        }
            
    }
}
