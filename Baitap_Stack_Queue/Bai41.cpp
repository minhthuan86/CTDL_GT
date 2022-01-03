#include<iostream>
using namespace std;
#define Max 10
struct Stack{
    int A[Max];
    int top;
};
void Init(Stack &S){
    S.top = -1;
}
bool IsFull(Stack S){
    return S.top==Max-1;
}
bool IsEmpty(Stack S){
    return S.top==-1;
}
void Push(Stack &S,int a){
    if(!IsFull(S)) 
     S.A[++S.top]=a;
    else cout<<"Stack day";
}

int Pop(Stack &S){
    if(!IsEmpty(S)) return S.A[S.top--];
    else{
        cout<<"Stack rong";
        return 0;
    }
}
void InStack(Stack &S){
    int a;
    cout<<"nhap den so 0 thi dung\n";
    do{
        cout<<"Nhap a= ";
        cin>>a;
        if(a!=0) Push(S,a);
        if(IsFull(S)) {
            cout<<"Stack day\n";
            return;
        }
    }while(a!=0);
}
void OutStack(Stack &S){
    cout<<"Stack: ";
    while(!IsEmpty(S)) cout<<Pop(S)<<" ";
}

int main(){
    Stack S;
    Init(S);
    InStack(S);
    OutStack(S);
}