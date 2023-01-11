#include <stdio.h>
#include <math.h>
#include <string.h>

double zad1(int n, int i) {
    if (n == i) {
        return sqrt((double) n / (i * i));
    }
    if (n - i + 1 > n / 2) {
        return sqrt((double) (n - i + 1) / (i * i) + zad1(n, i + 1));
    }
    return sqrt((double) (i) / (i * i) + zad1(n, i + 1));
}

double zad1a(int n) {
    double sum = 0;
    for (int i = n; i > 0; --i) {
        if (i > n / 2) {
            sum = sqrt((double) i / (i * i) + sum);
        } else {
            sum = sqrt((double) (n - i + 1) / (i * i) + sum);
        }
    }
    return sum;
}

int n = 5, m = 4;

void printM(int a[n][m]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int daLiJePalindrom(int x) {
    int obrnutBr = 0;
    int br = x;
    while (x > 0) {
        obrnutBr = obrnutBr * 10 + x % 10;
        x /= 10;
    }
    if (obrnutBr == br) {
        return 1;
    }
    return 0;
}

void rotirajkolonu(int a[n][m], int j, int k) {
    for (int i = 0; i < k; ++i) {
        int temp = a[n - 1][j];
        for (int l = n - 1; l > 0; --l) {
            a[l][j] = a[l - 1][j];
        }
        a[0][j] = temp;
    }
}

void zad2(int a[n][m]) {
    for (int i = 0; i < m; ++i) {
        int x = 0;
        int max = -1;
        for (int j = 0; j < n; ++j) {
            if (a[j][i] > max) {
                max = a[j][i];
            }
            x = x * 10 + a[j][i];
        }
        //printf("br=%d  max=%d\n",x,max);
        if (daLiJePalindrom(x) == 0) {
            rotirajkolonu(a, i, max);
        }
    }
}

int indexOfSpace(char str[], int i) {
    while (str[i] != ' ' && str[i] != 0) {
        i++;
    }
    if (i == strlen(str)) {
        return strlen(str);
    }
    return i;
}

void zad3(char str[], int length) {
    int prevSpace = 0;
    int nextSpace = indexOfSpace(str, prevSpace);
    while (nextSpace <= length) {
        int i = 1;
        int n=nextSpace - prevSpace;
        for (int j = 0; j < n; ++j) {
            if(n%2==0){
                if(j<(n)/2){
                    str[j + prevSpace] = (str[j + prevSpace] - 48 + i++) % 10 + 48;
                }
                else{
                    str[j + prevSpace] = (str[j + prevSpace] - 48 + --i) % 10 + 48;
                }
            }else{
                str[j + prevSpace] = (str[j + prevSpace] - 48 + i) % 10 + 48;
                if(j<(n)/2){
                    i++;
                }else{
                    i--;
                }

            }


        }
        printf("\n");
        prevSpace = nextSpace + 1;
        nextSpace = indexOfSpace(str, prevSpace);
    }
    printf("%s",str);
}

int main() {
    /*printf("%lf\n", zad1(6, 1));
    printf("%lf\n", zad1a(6));
    int a[][4]={
            {1, 2, 2, 2},
            {6, 3, 1, 1},
            {5, 8, 1, 1},
            {6, 3, 3, 1},
            {7, 2, 1, 2}
    };
    printM(a);
    zad2(a);
    printM(a);*/
    char str[] = "4385 53913 335";
    //printf("%d", indexOfSpace(str,11));
    zad3(str, strlen(str));
    return 0;
}
