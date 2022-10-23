#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
int stack[50];
char st1[50];
int top=-1;
void push(int a);
void pop();


int main(){
   char x;
    cout<<"Enter a string to evaluate postfix expression";
    cin>>st1;
    
    for(int i=0; st1[i] != '\0'; i++){
        x=st1[i];
        if((isdigit(x))){
            int num=(x-'0');
            push(num);
          
}
      
        else  if((x=='+')){
            int c=stack[top];
            pop();
            int b=stack[top];
            pop();
            int y=b+c;
          
            push(y);
            
            
        }
        else if((x=='-')){
            int c=stack[top];
            pop();
            int b=stack[top];
            pop();
            int y=(b-c);
            push(y);
            
        }
        else if(x=='*'){
            int c=stack[top];
            pop();
            int b=stack[top];
            pop();
            int y=b*c;
            push(y);
        }
        else if(x=='/'){
            int c=stack[top];
            pop();
            int b=stack[top];
            pop();
            int y=b/c;
            push(y);
        }
        
        
        
    } 
    while(top != -1){
        cout<<stack[top];
        pop();
    }
    return 0;
}
void pop(){
    top--;
    
}
void push(int x){
    top++;
    stack[top]=x;
  
}