#include<stdio.h>
void main(){
int a[100],n,i;
printf("Enter the numbers:");
scanf("%d",&n);
for(i=0;i<n;i++){
      a[i]=rand()%50;
}
InsertionSort(a,n);
for(i=0;i<n;i++){
      printf("%d\t",a[i]);
}
}
void InsertionSort(int a[],int n){
int i,j,temp;
for(i=1;i<n;i++){
      temp=a[i];
      j=i-1;
      while(j>=0&&temp<a[j]){
            a[j+1]=a[j];
            j--;
      }
      a[j+1]=temp;
 }
}
