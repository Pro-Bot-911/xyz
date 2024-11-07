#include <iostream>
using namespace std;
#define max 100

void swap(int *a,int *b){
   int temp=*a;
    *a=*b;
    *b=temp;

}
void heapify( int arr[],int n, int i){
   int  lar=i;
   int left = 2*i+1;
   int  right = 2*i+2;
    if (left<n && arr[left]>arr[lar]){
        lar=left;
    }
    if(right<n && arr[right]>arr[lar]){
        lar=right;

    }
    if(lar!=i){
        swap(&arr[i],&arr[lar]);
        heapify(arr,n,lar);
    }
}

int main(){
    int arr[max]={3, 5, 6, 2, 4, 1, 8, 7};
    int n=8;

    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }

    cout<<"execution :"<<endl;
    for (int i= 0;i<n;i++){
        swap(&arr[0],&arr[n-1-i]);
        cout<<arr[n-1-i]<<endl;
        heapify(arr,n-1-i,0);
    }
    return 0;
}