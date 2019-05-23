#Merge Sort

This is the fastest Sorting technique implemented.
It keeps Dividing the entire Array into 2 parts, compares adjacent elements and sorts, Finally it merges into a Single Array.

#Explanation and code for merge sort

The primary advantage of merge sort is that it include recursiona and division of an array into as many small parts as possible, till each subunit array becomes only one element long to help sorting from smallest to largest in the array.
The merge sort primarily consista of 2 functins, one to do the sorting itself and the other to merge the two subunit arrays into one larger unit.
This keeps happening until the entire array is sorted

Here is the algorithm and explanation of the code

#include <iostream.h>

void merging(int l, int m, int u, int a[100])// function required for merging 2 subunits or subarrays 
{
   int i, j, k, b[100];//local variables declared as part of function

   for(i = l, j = m + 1, k = l; i <= m && j <= u; k++) //initialising i to the lower limit, j to the midmost+1 element and k to the upper limit
   { // the loop runs till i reaches the midmost element of the array and j reaches the upper limit indicating complete sorting, k gets incremented each step
      if(a[i] <= a[j])// checking in subunit 1, the lower bounds
         b[k] = a[i++];// the array b gets to store sorted elements temporarily, incrementation is done inherently
      else
         b[k] = a[j++];//if the second subunit has an element smaller than the first, then that element goes first
   }
   //the next two while loops are to ensure that the remaining elements go directly as they are already in ascending order
   while(i <= m)    
      b[k++] = a[i++];

   while(j <= u)   
      b[k++] = a[j++];
//finally, once the temporary array gets the order correctly, it goes back to the original array
   for(k = l; k <= u; k++)
      a[k] = b[k];
}
//function to do merge sort by calling merge function
void sort(int l, int u, int a[100]) 
{
   int m;//local varible for midmost element
   
   if(l < u)//checking validity 
   {
      m = (l + u) / 2;//initialising midmost value
      sort(l, m);//recursive nature to split into subunits
      sort(m+1, u);
      merging(l, m, u, a);//calling merging function
   } 
   else //if it is already sorted
   { 
      return;
   }   
}

void main() 
{ 
   int i, n, a[100];//variables for index, array, upper limit

  cout<<"Enter number of elements ";
  cin>>n;
  cout<<"Enter elements"<<endl;
  for(i = 0; i <= n; i++)
  cin>>a[n];
  sort(0,n,a);//passing to function
  cout<<"Sorted array"<<endl; 
   for(i = 0; i <= n; i++)
cout<<a[i]<<" ";
}

The basic algorithm for the code is as follows

MergeSort(a[], l,  u)
If u > l // atleast one element
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+u)/2
     2. Call mergeSort for first half:   
             Call mergeSort(a, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(a, m+1, u)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(a, l, m, r)
             this occurs in recursion.
             
             
             
