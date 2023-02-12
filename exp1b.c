#include <stdio.h>
#include<time.h>

void selectSort(int arr[], int n)
{
    int min, temp;
    int index;
    for (int i = 0; i < n - 1; i++)
    {
        min = arr[i];
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }
    /*printf("\nSelection Sort:\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }*/
}

void insertSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n - 1 - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    /*printf("\nInsertion Sort:\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }*/
}

int main()
{
    clock_t t;
    t = clock();
    double time_taken1=0.0,time_taken2=0.0;

    FILE *fp;
    fp = fopen("Numbergenerated.txt", "w");
    int arr[10000];
    for (int i = 0; i < 100000; i++)
    {
        fprintf(fp,"%d ", rand()%10);
    }
    fclose(fp);
    FILE *fptr;
    fptr = fopen("Numbergenerated.txt", "r");
    printf("Given array: ");
    for (int i = 0; i < 10000; i++)
    {
        arr[i]=getw(fptr);
    }
    printf("\nNumbers\tselection-sort\tinsertion-sort\n");

    for(int i=100;i<=10000;i=i+100)
    {
    printf("\n");
    selectSort(arr, i);
    t = clock() - t;
    time_taken1 = ((double)t)/CLOCKS_PER_SEC; // in seconds
    insertSort(arr, i);
    t = clock() - t;
    time_taken2 = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("%d\t%f\t%f \n",i,time_taken1, time_taken2);
    }
}
