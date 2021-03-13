#include <stdio.h>

int fib (int n)
{
    if (n <= 1)
        return n;
    return fib (n - 2) + fib (n - 1);
}

int f[10];

int fib2 (int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    } else
    {
        if (f[n-2] == 0)
            f[n-2] = fib2 (n - 2);
        if (f[n-1] == 0)
            f[n-1] = fib2 (n - 1);
        f[n] = f[n-2] + f[n-1];
        return f[n-2] + f[n-1];
    }
}

int main ()
{
    printf("%d\n", fib (7));
    printf("%d\n", fib2 (7));

    return 0;
}
