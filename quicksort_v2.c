int partition(int arr[], int low, int high)
{
 int pivot = arr[high];
 int i=low-1; 
 for(int j=low; j<high; j++)
  {
   if(arr[j]<=pivot)
    {
     i++;
     int temp = arr[i];
     arr[i] = arr[j];
     arr[j] = temp;
    }
  }
   i++;
   int temp = arr[i];
   arr[i] = arr[high];
   arr[high] = temp;
   return i;
}
void quicksort(int arr[], int low, int high)
{
if(low<high)
{
 int index = partition(arr, low, high);
 quicksort(arr, low, index-1);
 quicksort(arr, index+1, high);
}
}

void main(){
int arr[] = {2,4,5,1,9,0,2,6,8,7,3};
int len = sizeof(arr)/sizeof(arr[0]);
quicksort(arr, 0, len-1);
for(int k=0; k<len; k++)
{
 printf("%d ",arr[k]);
}
}