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
int SoSanh(Stack &pHead1,Stack &pHead2){
    int char1,char2;
   while(!IsEmpty(pHead1)&&!IsEmpty(pHead2)){
       char1=(int) Pop(pHead1);
       char2=(int) Pop(pHead2);
       //cout<<char1<<" "<<char2<<endl;
       if(char1>char2) return 1;
       if(char1<char2) return 2;
   }
   return 0;
}
int main(){
    Stack Chuoi1,Chuoi2;
    Init(Chuoi1);
    Init(Chuoi2);
    InPut(Chuoi1);
    InPut(Chuoi2);
    int S=SoSanh(Chuoi1,Chuoi2);
    if(S==1) cout<<"Chuoi 1 lon hon";
    else if(S==2) cout<<"Chuoi 2 lon hon";
    else cout<<"2 chuoi bang nhau";
}