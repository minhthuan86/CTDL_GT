#include<iostream>
using namespace std;
#define Max 10
struct Queue{
    int A[Max];
    int f,r; //front: đầu, rear: đuôi
};
void Init(Queue &Q){
    Q.r=-1;
    Q.f=0;
}
bool IsEmpty(Queue Q){
    return Q.f>Q.r;
}
bool IsFull(Queue Q){
    return Q.r==Max-1;
}
void Push(Queue &Q,int a){
    if(IsFull(Q)) {
        cout<<"Hang doi full";
        return;
    }
    else Q.A[++Q.r]=a;
}
int Pop(Queue &Q){
    if(IsEmpty(Q)){
        cout<<"Hang doi empty";
        return 0;
    }
    else return Q.A[Q.f++];
}
void InPut(Queue &Q){
    int m,n;
    cout<<"Nhap so phan tu: ";cin>>m;
    for(int i=0;i<m;i++){
        cout<<"Nhap gia tri: ";
        cin>>n;
        Push(Q,n);
        if(IsFull(Q)) break;
    }
}
void Output(Queue &Q){
    while(!IsEmpty(Q)) cout<<Pop(Q)<<"\t";
}
int main(){
    Queue Q;
    Init(Q);
    InPut(Q);
    Output(Q);
}