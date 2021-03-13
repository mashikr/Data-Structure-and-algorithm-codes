#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display (struct Array arr)
{
    int i;
    printf("\nElements are: ");
    for (i=0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void Append (struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert (struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i=arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete (struct Array *arr, int index)
{
    int x = 0, i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i=index; i<arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void Reverse (struct Array *arr)
{
    int *B;
    int i, j;

    B = (int *)malloc(arr->length * sizeof(int));
    for (i=arr->length-1, j=0; i>=0; i--, j++)
        B[j] = arr->A[i];
    for (i=0; i<arr->length; i++)
        arr->A[i] = B[i];
}

void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Reverse2 (struct Array *arr)
{
    int i, j;
    for (i=0, j=arr->length-1; i<j; i++, j--)
    {
        swap (&arr->A[i], &arr->A[j]);
    }
}

void InsertSort (struct Array *arr, int x)
{
    int i = arr->length-1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int isSorted (struct Array arr)
{
    int i;
    for (i=0; i<arr.length-1; i++)
    {
        if (arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

void Rearrange (struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length-1;

    while (i<j)
    {
        while (arr->A[i]<0) i++;
        while (arr->A[j]>=0) j--;
        if (i<j) swap(&arr->A[i], &arr->A[j]);
    }
}

int main ()
{
    struct Array arr = {{-2,3,4,-5,6},10,5};
    // Append(&arr, 7);
    // Insert(&arr, 7, 10);
    // printf("%d\n", Delete(&arr, 2));
    // Reverse (&arr);
    // Reverse2 (&arr);
    // InsertSort (&arr, 3);
    //printf("%d\n", isSorted(arr));
    Rearrange (&arr);

    Display(arr);

    return 0;
}
