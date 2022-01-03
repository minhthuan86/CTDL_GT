#include<iostream>
#include<string>
using namespace std;
struct Node{
    char data;
    Node *next;
};
typedef Node * Stack;
Node *TaoNode(int a){
    Node *p = new Node;
    p->data = a;
    p->next =NULL;
    return p;
}
void Init(Stack &pHead){
    pHead=NULL;
}
bool IsEmpty(Stack &pHead){
    return pHead==NULL;
}
void Push(Stack &pHead,int a){
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
void InPut(Stack &pHead){
    string str;
    cout<<"Nhap ten: ";
    getline(cin,str);
    int s=str.length();
    while(str[s]!=' '){
        Push(pHead,str[s]);
        s--;
    }

}
void OutPut(Stack &pHead){
    cout<<"Ten vua nhap: ";
    while(!IsEmpty(pHead)) cout<<Pop(pHead);
}
int main(){
    Stack pHead;
    Init(pHead);
    InPut(pHead);
    OutPut(pHead);
}