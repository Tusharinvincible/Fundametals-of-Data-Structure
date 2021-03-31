#include <iostream>
using namespace std;

void get_arr(int *a,int size){              // Complexity O(n)
    cout<<"Enter the array elements :";
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
}
void print_arr(int *a,int size){            // Complexity O(n)
    cout<<"Printing array elements : ";
    for(int i=0;i<size;i++){
        cout<<a[i]<<"  ";
    }
    cout<<"\n";
}
void reverse_array(int* a,int size){      // Complexity O(n/2) i.e O(n)
    int l=0;
    int m=size-1;
    while(l<m){
        int temp=a[l];
        a[l]=a[m];
        a[m]=temp;
        l++;
        m--;
    }

}

void merge(int * a,int* b,int* c,int s1,int s2){     // Complexity O(m+n)
    int l=0;
    int m=0;
    int t=0;
    while(l<s1 && m<s2){
        if(a[l]<=b[m]){
            c[t]=a[l];
            l++;
        }
        else{
            c[t]=b[m];
            m++;
        }
        t++;
    }
    while(l<s1){
        c[t]=a[l];
        l++;
        t++;
    }
    while(m<s2){
        c[t]=b[m];
        m++;
        t++;
    }
}

int main(){
    int n,m;
    cout<<"Enter the size of array :";
    cin>>n>>m;
    int arr[n];
    int arr2[m];
    int res[m+n];
    get_arr(arr,n);
    get_arr(arr2,m);
    print_arr(arr,n);
    print_arr(arr2,m);
    reverse_array(arr,n);
    reverse_array(arr2,m);
    print_arr(arr,n);
    print_arr(arr2,m);

    reverse_array(arr,n);
    reverse_array(arr2,m);
    merge(arr,arr2,res,n,m);
    print_arr(res,m+n);

    return 0;
}