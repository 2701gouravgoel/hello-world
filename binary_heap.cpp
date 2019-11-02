#include <iostream>
#include<climits>
using namespace std;

void Swap(int *x, int *y);
class MinHeap{
    int *p;
    int max_lim;
    int hsize;
public:
    MinHeap(int max_lim);

    void MinHeapify(int );
    int parent(int i){
        return (i-2)/2;
    }
    int left(int i){
        return (2*i +1);
    }
    int right(int i){
        return (2*i +2);
    }

    int get_Min()
        {
            return p[0];
        }
    void insertKey(int k);

    void decreaseKey(int i,int new_val);

    int removeMin();

    int Size();
    int Merge(int a[] , int b[]);
};
MinHeap::MinHeap(int a)
{
    hsize=0;
    max_lim=a;
    p=new int[a];
}

void MinHeap::insertKey(int k)
{
    if(hsize==max_lim){
        cout <<"overflow";
        return;
    }
    hsize++;
    int i =hsize -1;
    p[i] = k;

    while(i!=0 && p[parent(i)] >p[i]){
        Swap(&p[i], &p[parent(i)]);
        i=parent(i);
    }
}
void MinHeap::decreaseKey(int i, int new_val){
    p[i] = new_val;
    while (i != 0 && p[parent(i)] > p[i])
    {
       Swap(&p[i], &p[parent(i)]);
       i = parent(i);
    }
}
int MinHeap::Size(){

    return hsize+1;
}
int MinHeap::removeMin()
{
    if(hsize<=0)
        return INT_MAX;
    if(hsize ==0)
    {
        hsize--;
        return p[0];
    }

    int root = p[0];
    p[0] = p[hsize-1];
    hsize--;
    MinHeapify(0);

    return root;
}

void MinHeap::MinHeapify(int i){
    int l=left(i);
    int r=right(i);
    int smallest =i;
    if(l<hsize && p[l] <p[i])
        smallest =l;
    if(r<hsize && p[r] <p[smallest])
        smallest =r;
    if(smallest !=i){
        Swap(&p[i],&p[smallest]);
        MinHeapify(smallest);
    }
}
int length(int a[]){
    int i=0;
    while(a[i]!= NULL){
        i++;
    }
    return i;
}
void Merge(int a[] ,int b[]){
    int n=length(a);
    int m=length(b);
    MinHeap c(n+m);
    for (int i = 0; i < n; i++)
        c.insertKey(a[i]);
    for (int i = 0; i < m; i++)
        c.insertKey(b[i]);
    for(int i=0;i<=c.Size()/2-1;i++){
        c.MinHeapify(i);
    }
    cout << c.get_Min() << " ";
    return ;
}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.removeMin() << " ";
    cout << h.get_Min() << " ";
        cout << h.Size() << " ";
    h.decreaseKey(2, 1);
    cout << h.get_Min()<<"                 ";
    int a[2];
    a[0]=4;
    a[1]=-1;
    int b[2];
    b[0]=5;
    b[1]=33;
    Merge(a,b);
    return 0;
}
