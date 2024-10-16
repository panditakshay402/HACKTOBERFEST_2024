#include <iostream>
#include <string.h>
using namespace std;
int n;
#define stacksize n

class stack{
public:
char demo[100];
int top;

public:

stack(){
    top=-1;
}

int empty(){
if(top==-1){
return 1;
}
else return 0;
}

int full(){
if(top==stacksize-1)
return 1;
else return 0;
}

void push(char m){
if(full()){
cout<<"Stack overflow, cannot push"<<endl;

}
top=top+1;
demo[top]=m;

}
char pop(){
if(empty()){
cout<<"stack underflow, cannot pop"<<endl;
}
return (demo[top--]);
}

char peek(){
if(empty()){
cout<<"stack empty"<<endl;
}
return demo[top];
}

};

int main(){
stack obj;
cout<<"Enter n"<<endl;
 cin>>n;

//string reversal
char ch;
cout<<"enter characters"<<endl;
for(int i=0;i<=stacksize-1;i++){
cin>>ch;
obj.push(ch);
}

for(int i=0;i<=stacksize-1;i++){
cout<<obj.pop();
}
return 0;
}
