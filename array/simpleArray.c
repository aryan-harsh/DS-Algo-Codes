#include<stdio.h>
int main()
{
	/*first declare the array 
	this is now to declare an array
	DataType name_of_array [number_of_elements];  */
	
	int array[50];

	//Know that the array is declared we can store data in it
	//In this case we can only store integer data in it
	//Array is a collection of similar elements having the same datatype.
	
	//now to store data elements in an array we can use a loop
	//remeber that array elements start a 0 index and end a size - 1 
	
	int i; // we are going to use this for the loop

	int number_of_elements;

	printf("\nhow many elements do you want to have in the array : ");
	scanf("%d",&number_of_elements);

	//now since we got the total number of elements we want in the array we can start storing
	

	for(i=0;i<number_of_elements;i++)
	{
		printf("\narray[%d] : ",i);
		scanf("%d",&array[i]);
	}

	//After this step we have inserted all the elements in the array now its time to print them
	//This can also be done by using a simple for loop as we used for storing the numbers 
	
	printf("\nThe array elements are as follows :- \n");
	for(i=0;i<number_of_elements;i++)
	{
		printf("\narray[%d] : %d",i,array[i]);
	}
}
