#include <stdio.h>

int main() 
{
	int n, i, j, k, dg, min, c;
	printf("Enter number of matrices: ");
	scanf("%d",&n);
	n++;
  
	//array for storing dimensions for the matrices and those matrices itself
	int dim[n], m[n][n]; 
	printf("\nEnter the dimensions: ");
	for(i=0;i<n;i++) scanf("%d",&dim[i]);

	//initialising diagonal values to be 0
	for (i = 0; i < n; i++) m[i][i] = 0;

	for(dg = 1; dg < n - 1; dg++)
	{
		for(i = 1; i < n - dg; i++)
		{
			j = i + dg;
			min = 999999; //intialising min to a large number
			for(k = i; k <= j - 1; k++)
			{
				c = m[i][k] + m[k+1][j] + dim[i-1] * dim[k] * dim[j]; //calculating answers of multiplying 1 matrix only, then 2 matrices, then 3 and so on			        
				if(c < min) min=c;
		        	m[i][j] = min; //store the min value
			}
	  	}
	}
	printf("\nMinimum cost of chain matrix multiplication: %d\n",m[1][n-1]); //the optimum answer is stored at the last column of the first row

	return 0;
}
