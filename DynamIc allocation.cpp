#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int *ptr;
     ptr = (int *) malloc(5 * sizeof(int));

     ptr[1] = 5;

     cout<<ptr[1]<<endl;
     ptr = (int *) realloc(ptr, 10 * sizeof(int));

     //ptr[1] = 5;

     cout<<ptr[1]<<endl;
}
