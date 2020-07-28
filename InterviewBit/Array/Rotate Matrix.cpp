void rot(vector<vector<int> >& A, int rowStart, int rowEnd, int colStart, int colEnd){

    while(rowStart < rowEnd){
        int i = 0;
        while((i + rowStart) < rowEnd){
            int temp1 = A[rowStart][colStart+i];
            int temp2 = A[rowStart+i][colEnd];
            int temp3 = A[rowEnd][colEnd-i];
            int temp4 = A[rowEnd-i][colStart];

            A[rowStart][colStart+i] = temp4;
            A[rowStart+i][colEnd] = temp1;
            A[rowEnd][colEnd-i] = temp2;
            A[rowEnd-i][colStart] = temp3;
            i++;
        }
        colStart++;
        colEnd--;
        rowStart++;
        rowEnd--;
    }

}
void Solution::rotate(vector<vector<int> > &A)
{
    int rows = A.size();

    if(rows == 0){
        return;
    }

    rot(A, 0, rows-1, 0, rows-1);

}
