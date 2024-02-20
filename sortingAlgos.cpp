#include<iostream>

using namespace std;

template<typename T>
class BubbleSort{
public:
    BubbleSort(T arr[],int n){
        _sort_(arr,n);
    }
    /* Finding and placing the smallest element for each position */
    void _sort_(T arr[],int n){
        for(int i=0 ; i<n ; i++){
            for(int j=i+1; j<n ; j++){
                if(arr[j] < arr[i]){
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
};

template<typename T>
class InsertionSort{
public:
    InsertionSort(T arr[],int n){
        _sort_(arr,n);
    }
    /* Creating a sorted array part and then inserting an element into it's correct position */
    void _sort_(T arr[],int n){
        for(int i=1; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(arr[i]<arr[j]){
                    T temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
};

template<typename T>
class MergeSort{
public:
    MergeSort(T arr[],int n){
        _sort_(arr,n);
    }
    /* Divide and Conquer */
    void _sort_(T arr[],int n){
        mergeSort(arr,0,n-1);
    }
    /* Dividing the array by mid-point => Takes log(n) operations */
    void mergeSort(T arr[], int st, int end){
        if(st==end)
            return;
        
        int mid = (end-st)/2+st;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,st,mid,end);
    }
    void merge(T arr[],int s,int m,int e){
        int k=0,l=0,r=s;
        int n1=m-s+1 , n2=e-m;

        T leftArr[n1], rightArr[n2];
        for(int i=0 ; i<n1 ; i++)
            leftArr[i] = arr[s+i];
        for(int i=0 ; i<n2 ; i++)
            rightArr[i] = arr[m+1+i];

        while(k<n1 && l<n2){
            if(leftArr[k]<rightArr[l]){
                arr[r++] = leftArr[k++];
            } else {
                arr[r++] = rightArr[l++];
            }
        }

        while(k<n1)
            arr[r++] = leftArr[k++];
        while(l<n2)
            arr[r++] = rightArr[l++];
        
    }
};

template<typename T>
class QuickSort{
public:
    QuickSort(T arr[],int n){
        _sort_(arr,n);
    }
    /* Choosing a pivot and fixing it's correct position in the array, then divide and conquer */
    void _sort_(T arr[],int n){
        quickSort(arr,0,n-1);
    }
    void quickSort(T arr[],int st,int end){
        if(st>=end)
            return;
        
        int pT = partition(arr,st,end);
        
        quickSort(arr,st,pT-1);
        quickSort(arr,pT+1,end);
    }
    int partition(T arr[],int st,int end){
        T pivot = arr[end];
        int l=st-1;

        for(int r=st; r<end ; r++){
            if(pivot>arr[r]){
                l++;
                T temp = arr[r];
                arr[r] = arr[l];
                arr[l] = temp;
            }
        }

        T temp = arr[l+1];
        arr[l+1] = arr[end];
        arr[end] = temp;

        return l+1;
    }
};

template<typename T>
class HeapSort{
public:
    HeapSort(T arr[], int n){
        _sort_(arr,n);
    }
    void _sort_(T arr[],int n){
        for(int i=n/2-1; i>=0 ; i--)
            heapify(arr,n,i);

        for(int i=n-1 ; i>=0 ; i--){
            T temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;

            heapify(arr,i,0);
        }
    }
    void heapify(T arr[],int n,int root){
        int largest = root;
        int leftChild = 2*root+1;
        int rightChild = 2*root+2;

        if(leftChild<n && arr[leftChild]>arr[largest])
            largest = leftChild;
        if(rightChild<n && arr[rightChild]>arr[largest])
            largest = rightChild;

        if(largest!=root){
            T temp = arr[root];
            arr[root] = arr[largest];
            arr[largest] = temp;
            heapify(arr,n,largest);
        }
    }
};

void _print_(int arr[],int n){
    for(int i=0 ; i<n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {-42,75,-34,-35,-30,7,-83,33,77,-69,58,-34,23,1,-90,91,-87,100,61,-74,98,54,98,36,19,89,57,79,-20,23,30,-83,-61,-45,-40,60,39,7,-27,17,-100,-18,1,74,53,-53,44,14,23,-3,82,-25,52,18,-63,19,26,49,3,-26,50,-1,45,8,-90,11,-25,64,71,-47,46,-56,-94,100,-46,63,60,74,90,-91,-94,-7,26,34,60,-65,-37,61,90,-8,-82,95,61,31,-67,34,13,39,62,-31};
    int n = sizeof(arr)/sizeof(arr[0]);

    // BubbleSort<int> b(arr,n);
    // InsertionSort<int> i(arr,n);
    // MergeSort<int> m(arr,n);
    // QuickSort<int> q(arr,n);
    // HeapSort<int> h(arr,n);

    _print_(arr,n);

    return 0;
}
