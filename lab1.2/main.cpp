#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

void sumOddElem(int* arr, int m, int n, int* sum);

int main()
{
    int m, n;

    cout<<"Vvedit m\n> ";
    cin>>m;

    cout<<"Vvedit n\n> ";
    cin>>n;

    int* arr = (int*)malloc(sizeof(int) * m * n);
    int* sum = (int*)calloc(n, sizeof(int));

    srand(time(0));

    int i, j;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            arr[i * m + j] = rand() % 100 + 1;

    cout<<"Masiv:\n\n";
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++)
            cout<<arr[i * m + j]<<" ";
        cout<<"\n";
    }

    sumOddElem(arr, m, n, sum);
    cout<<"Neparni:\n\n";
    for(i = 0; i < n; i++)
        cout<<sum[i]<<" ";

    return 0;
}

void sumOddElem(int* arr, int m, int n, int* sum){
    int i, j;

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            if(arr[j * m + i] % 2 == 1)
                sum[i]++;
}
