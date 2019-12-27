#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int* bArrCreate(int* arr, int m, int* count);
double midArifm(int* arr, int len);

int main()
{
    int m;
    int count = 0;

    cout<<"input m\n> ";
    cin>>m;

    int* a = (int*)malloc(sizeof(int) * m);

    srand(time(0));

    int i;
    for(i = 0; i < m; i++){
        a[i] = rand() % 100 + 1;
        if (rand() % 2 == 0)
            a[i] *= -1;
    }

    cout<<"Array a:\n\n";
    for(i = 0; i < m; i++)
        cout<<a[i]<<" ";

    int* b = bArrCreate(a, m, &count);

    cout<<"\n\nArray b:\n";
    for(i = 0; i < count; i++)
        cout<<b[i]<<" ";

    double c = midArifm(b, count);
    cout<<"\n\nmiddle arifm:\n";
    cout<<c;

    return 0;
}

int* bArrCreate(int* arr, int m, int* count){
    int i;
    int* b;

    for(i = 1; i < m; i += 2)
        if(arr[i] < 0)
            *count = *count + 1;

    b = (int*)malloc(*count * sizeof(int));

    int k = 0;
    for(i = 1; i < m; i += 2)
        if(arr[i] < 0)
            b[k++] = arr[i];

    return b;
}

double midArifm(int* arr, int len){
    int i;
    int sum = 0;
    double res;

    for(i = 0; i < len; i++)
        sum += arr[i];

    res = sum / len;

    return res;
}

