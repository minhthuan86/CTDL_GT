#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<cmath>
#define MAX 10
using namespace std;
struct Stack{
	int top;
	int Node[MAX];
};
void Init(Stack &S){
 	S.top=-1;
}
bool isFull(Stack S){	
 	return S.top==MAX-1;
}
bool isEmpty(Stack S){
 	return S.top==-1;
}
void AddStack(Stack &S,int x){
 	if(isFull(S)==true) cout<<"Ngan xep day";
 	else{
	  S.top++;
	  S.Node[S.top]=x;
	}
}
int PopStack(Stack &S){
 	if(isEmpty(S)==true){
 		cout<<"Danh sach rong";
 		return 0;
	 }
	 else{
	 	return S.Node[S.top--];
	 }  
}
int Top(Stack S) {
    if (!isEmpty(S)) {
        return S.Node[S.top];
    }
    else {
        cout << "Stack rong !" << endl;
        return 0;
    }
}
void InStack(Stack &S){
 	int n,a;
 	cout<<"Nhap vao so luong pt : ";
 	cin>>n;
 	for(int i=0;i<=n;i++)
 	{
 		if(isFull(S)) return;
 		cout<<"Nhap phan thu thu "<<i<<" : ";
 		cin>>a;
 		AddStack(S,a);
	 }
}
void OutStack(Stack &S){
 	while(!isEmpty(S))
 	 cout<<PopStack(S)<<"\t";
}
int main(){
	Stack S;
 	Init(S);
 	InStack(S);
    cout<<"\nGia tri lon nhat sua Stack : "<<Top(S);
 	OutStack(S);
 	
}