#include<stdio.h>
void main(){
int a[100],n,i;
printf("Enter the numbers:");
scanf("%d",&n);
for(i=0;i<n;i++){
      a[i]=rand()%50;
}
BubbleSort(a,n);
for(i=0;i<n;i++){
      printf("%d\t",a[i]);
}
}
void BubbleSort(int a[],int n){
int i,j,temp;
for(i=0;i<n-2;i++)
      {
      for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                  temp=a[j];
                  a[j]=a[j+1];
                  a[j+1]=temp;
            }
      }
      }
}
