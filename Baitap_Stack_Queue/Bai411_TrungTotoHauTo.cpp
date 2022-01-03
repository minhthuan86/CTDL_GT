#include<iostream>
#include<string>
#include<conio.h>
#include<math.h>
using namespace std;
string str;
struct Node{
    char data;
    Node *next;
};
struct Nut{
    char data;
    int gt;
    Nut *next;
};
typedef Node * Stack;
typedef Nut * GT;
Node *TaoNode(int a){
    Node *p = new Node;
    p->data = a;
    p->next =NULL;
    return p;
}
GT TaoGT(char x,int a){
    GT p=new Nut;
    p->data = x;
    p->gt=a;
    p->next =NULL;
    return p;
}
void NhapGT(GT &pHead){
    GT p;
    char ch,data;
    int gt;
    cout<<"\nNhap gia tri dua vao:\n";
    do{
        cout<<"Nhap toan hang: ";cin>>data;
        cout<<"Nhap gia tri: ";cin>>gt;
        p=TaoGT(data,gt);
        if(pHead==NULL){
            pHead=p;
        }
        else{
            p->next=pHead;
            pHead=p;
        }
        cout<<"Nhap ESC de thoat, phim bat ky de tiep tuc: \n";
        ch=getch();
    }while(ch!=27);
}
void InGT(GT pHead){
    while(pHead!=NULL){
        cout<<pHead->data<<":  "<<pHead->gt<<"\n";
        pHead=pHead->next;
    }
}
void Init(Stack &pHead){
    pHead=NULL;
}
bool IsEmpty(Stack &pHead){
    return pHead==NULL;
}
void Push(Stack &pHead,char a){
    Stack p=TaoNode(a);
    p->next=pHead;
    pHead=p;
}
char Pop(Stack &pHead){
    char a=pHead->data;
    Stack p=pHead;
    pHead=pHead->next;
    delete p;
    return a;
}
void ChenCuoi(Stack &pHead,char a){
    Stack p,q;
    p=TaoNode(a);
    if(pHead==NULL) pHead=p;
    else{
        for(q=pHead;q->next!=NULL;q=q->next);
        q->next=p;
    }
}
void Input_P(Stack &pHead){
    cout<<"Nhap da thuc: ";
    getline(cin,str);
    for(int i=0;i<str.length();i++){
        ChenCuoi(pHead,str[i]);
    }
}
void OutPutDS(Stack pHead){
    while(pHead!=NULL){
        cout<<pHead->data;
        pHead=pHead->next;
    }
}
void OutPutStack(Stack pHead){
    Stack P=NULL;
    while(pHead!=NULL){
        Push(P,pHead->data);
        pHead=pHead->next;
    }
    OutPutDS(P);
}
int SSUT(char x,char y){
    if(y=='(') return 0;
    if(x==y) return 1;
    if(x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') 
        if(y=='+'||y=='-') return 0;
        else return 1;
    if(x=='^') return 0;
}
void Chuyendoi(Stack &P,Stack &Q,Stack &S){
    Push(P,'(');
    ChenCuoi(P,')');
    char ch,q;
    do{
    ch=Pop(P);
    if(ch=='(') Push(S,ch);
    else if (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch>='0'&&ch<='9') ChenCuoi(Q,ch);
    else if (ch==')') {
        while (S->data!='('){
        q=Pop(S);
        if(q!='(') ChenCuoi(Q,q);
        }
        Pop(S);
    }
    else if (ch=='*'||ch=='+'||ch=='-'||ch=='/'||ch=='^') {
        while(SSUT(ch,S->data)){
            q=Pop(S);
            ChenCuoi(Q,q);
        }
        Push(S,ch);
    }
    OutPutDS(P);
    cout<<"\t\t";
    OutPutStack(S);
    cout<<"\t\t";
    OutPutDS(Q);
    cout<<"\n";
    }while(P!=NULL);
    cout<<"\nChuoi trung to:";
    for(int i=0;i<str.length();i++) cout<<str[i];
    cout<<"\nChuoi hau to: ";
    OutPutDS(Q);
}
void DinhGia(Stack &Q,Stack &S,GT &MyGT){
    int a,b;
    NhapGT(MyGT);
    //InGT(MyGT);
    while(MyGT!=NULL){
        Stack p=Q;
        while(p!=NULL){
            if(p->data==MyGT->data) p->data= MyGT->gt+48;
            p=p->next;
        }
        MyGT=MyGT->next;
    }
    cout<<"\n";
    OutPutDS(Q);
    cout<<"\n";
    Init(S);
    do{
        char ch=Pop(Q),kq;
        if(ch>='0' && ch<='9') Push(S,ch);
        else {
            a= Pop(S)-48;
            b= Pop(S)-48;
            switch(ch) {
                case '+': kq= (char) a+b; Push(S,kq); break;
                case '-': kq= (char) a-b; Push(S,kq); break;
                case '*': kq= (char) a*b; Push(S,kq); break;
                case '/': kq= (char) a/b; Push(S,kq); break;
                case '^': kq= (char) pow(a,b); Push(S,kq); break;
            }
        }
        OutPutDS(Q);
        cout << "\t\t";
        OutPutStack(S);
        cout<<"\n";
    }while(Q!=NULL);
    cout<<"KQ:"<<Pop(S);
}
int main(){
    Stack Q=NULL,P=NULL,S;
    GT MyGT=NULL;
    Input_P(P);
    Init(S);
    Chuyendoi(P,Q,S);
    DinhGia(Q,S,MyGT);
}