#include<stdio.h>
void SelectionSort(int a[],int n);
void main(){
int a[100],n,i;
printf("Enter the numbers:");
scanf("%d",&n);
for(i=0;i<n;i++){
      a[i]=rand()%50;
}
SelectionSort(a,n);
for(i=0;i<n;i++){
      printf("%d\t",a[i]);
}
}
void SelectionSort(int a[],int n){
int i,j,min,temp;
for(i=0;i<n-1;i++){min=i;
      for(j=i+1;j<n;j++)
            {
            if(a[min]>a[j])min=j;
            }
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}
