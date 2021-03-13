#include <stdio.h>

int com (int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    return com (n - 1, r - 1) + com (n - 1, r);
}

int fact (int n)
{
    if (n == 0)
        return 1;
    return fact (n - 1) * n;
}

int nCr (int n, int r)
{
    int num, den;

    num = fact (n);
    den = fact (r) * fact (n - r);

    return num / den;
}

int main ()
{
    printf("%d\n", com (4, 3));
    printf("%d\n", nCr (4, 3));

    return 0;
}
