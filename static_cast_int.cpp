#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a = 10;
    char c = 'a';
  
    // pass at compile time, may fail at run time
    int* q = (int*)&c; 
    int* p = static_cast<int*>(&c);
    return 0;
}