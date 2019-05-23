#include <iostream.h>

void merging(int low, int mid, int high, int a[100]) {
   int l1, l2, i, b[100];

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high, int a[100]) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high, a);
   } else { 
      return;
   }   
}

int main() { 
   int i, a[100],n;

   cout<<"Enter number ";
   cin>>n;
   cout<<"Enter elements"<<endl;
    for(i = 0; i <= n; i++)
   cin>>a[i];
  
   sort(0, n, a);

   cout<<"Sorted list"<<endl;
   
   for(i = 0; i <= n; i++)
      cout<<a[i]<<" ";
}
