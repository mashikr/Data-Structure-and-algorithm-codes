#include <stdio.h>

int sum (int n)
{
    if (n == 0)
        return 0;
    else
        return sum (n - 1) + n;
}

int main ()
{
    int res = sum (10);

    printf("%d\n", res);

    return 0;
}
