#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
typedef int matr[100][100];
typedef int gor[100];
matr s;
gor Q, goroda;
int  n, m, t, i_st, i_end, A, B;

void matr_smezh() {
    int i, j;
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            srand(time(NULL));
            s[i][j] = rand() % 2;
        }
    }
    for (i = 0; i < n; i++) {
        s[i][i] = 0;
        for (j = 0; j < n; j++) {
            s[j][i] = s[i][ j];
        }
}
};


void vuvod() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
}

    void poisk(){
        int i;
        goroda[A] = 200;
    Q[0] = A; i_st = 1; i_end = 2;
    while (i_st < i_end) {
        for (i = 0; i < n; i++) {
            if ((goroda[i] == 0) && (s[Q[i_st]][i] == 1)) {
                Q[i_end] = i; i_end++; goroda[i] = Q[i_st];
            }
            i_st++;
        }
    }
};
    void vuvod_res() {
        int i;
        if (goroda[B] == 0)
            cout << "Немає виходу" << endl;
        Q[0] = B; i_end = 2; t = goroda[B];
        while (t != A) {
            Q[i_end] = t; i_end++; t = goroda[t];
        }
        Q[i_end] = A;
        for (i = i_end; i > 1; i--)
            cout << Q[i] << ' ';
    }

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введіть кількість вершин графа: " << endl;
        cin >> n;
    cout << "Введіть кількість непрохідних вершин: " << endl;
    cin >> m;

    cout << "Введіть вершини: " << endl;
    for (int i = 0; i < m; i++) {
        cin >> t; goroda[t] = -1;
    }
    matr_smezh();
    cout << "Матриця суміжності: " << endl;
    vuvod();
    cout << endl;
    for (int i = 0; i < n; i++)
        if (goroda[i] == -1)
            cout << i << ' ';
    cout << endl;
    cout << "Введіть номер вершини А: ";
    cin >> A;
    cout << "Введіть номер вершини В: ";
    cin >> B;
    poisk();
    cout << endl;
    vuvod_res();
    cout << endl;
    system("pause");

    return 0;
}

