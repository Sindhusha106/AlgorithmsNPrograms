#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int temp[], int low, int middle, int high);

void mergesort(int arr[], int temp[], int low, int high)
{
 if(low<high)
  {
   int middle = (low+high)/2;
   mergesort(arr, temp, low, middle);
   mergesort(arr, temp, middle+1, high);
   merge(arr, temp, low, middle, high);
  }
}

void merge(int arr[], int temp[], int low, int middle, int high){
 for(int i=low; i<=high; i++)
 {
  temp[i] = arr[i];
 }

int tLeft = low;
int tRight = middle+1;
int curr = low;

while(tLeft<=middle && tRight<=high)
{
 if(temp[tLeft]<=temp[tRight]){
	arr[curr] = temp[tLeft];
	tLeft++;
	}else{
	arr[curr] = temp[tRight];
	tRight++;
	}
	curr++;
}

int rem = middle - tLeft;
for(int i=0; i<=rem; i++)
{
 arr[curr+i] = temp[tLeft+i];
}
}

void main(){
int arr[] = {2,4,5,1,6,8,7,3};
int len = sizeof(arr)/sizeof(arr[0]);
int temp[len];
mergesort(arr, temp, 0, len-1);
for(int k=0; k<len; k++)
{
 printf("%d ",arr[k]);
}
}