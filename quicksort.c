#include <stdio.h>
#include <stdlib.h>
int partition(int arr[], int left, int right);

void quicksort(int arr[], int left, int right)
{
    if(left<right){
 int index = partition(arr, left, right);
 quicksort(arr, left, index-1);
 quicksort(arr, index+1, right);
}}


int partition(int arr[], int left, int right){
int pivot = arr[(left+right)/2];
while(left<=right){
while(arr[left]<pivot) left++;
while(arr[right]>pivot) right--;

if(left<=right)
{
int temp = arr[left];
arr[left] = arr[right];
arr[right] = temp;
left++;
right--;
}
}
return left;
}

void main(){
int arr[] = {5,3,2,4,9};
int len = sizeof(arr)/sizeof(arr[0]);
quicksort(arr, 0, len-1);
for(int k=0; k<len; k++)
{
 printf("%d ",arr[k]);
}
}