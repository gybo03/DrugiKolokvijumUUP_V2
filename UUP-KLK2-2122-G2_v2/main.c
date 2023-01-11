#include <stdio.h>
#include <math.h>
#include <string.h>

double zad1(int n, int i) {
    if (n == 1) {
        return n - i;
    }
    return n - ((double) i / (i + (double) n / zad1(n / 2, i * 2)));
}

int pom(int n, int i) {
    while (i > 1) {
        n /= 2;
        i /= 2;
    }
    return n;
}

int brPonavljanja(int n) {
    int i = 0;
    while (n > 0) {
        n /= 2;
        i++;
    }
    return i;
}

double zad1a(int n) {
    double sum = 1 - pow(2, brPonavljanja(n) - 1);
    for (int i = pow(2, brPonavljanja(n) - 1) / 2; i > 0; i /= 2) {
        //printf("n=%d,i=%d\n", pom(n,i),i);
        sum = pom(n, i) - (double) i / (i + (double) pom(n, i) / sum);
    }
    return sum;
}

int n = 5;

void printM(int a[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void sortirajKolonu(int a[n][n], int j) {
    for (int i = 0; i < n - 1; ++i) {
        for (int k = 0; k < n - i - 1; ++k) {
            if (a[k][j] > a[k + 1][j]) {
                int temp = a[k][j];
                a[k][j] = a[k + 1][j];
                a[k + 1][j] = temp;
            }
        }
    }
}

void printA(int a[n][n], int j) {
    for (int i = 0; i < n; ++i) {
        printf("%d", a[i][j]);
    }
    printf("\n");
}

void sortirajPoPoslednjemRedu(int a[n][n]) {
    for (int i = 0; i < n - 1; ++i) {
        for (int k = 0; k < n - i - 1; ++k) {
            if (a[n - 1][k] < a[n - 1][k + 1]) {
                int temp[n];
                /*printA(a,k);
                printA(a,k+1);*/
                for (int j = 0; j < n; ++j) {
                    temp[j] = a[j][k];
                }

                for (int j = 0; j < n; ++j) {
                    a[j][k] = a[j][k + 1];
                }
                for (int j = 0; j < n; ++j) {
                    a[j][k + 1] = temp[j];
                }
            }
        }
    }
}

void zad2(int a[n][n]) {
    for (int i = 0; i < n; ++i) {
        sortirajKolonu(a, i);
    }
    printM(a);
    for (int i = 0; i < n; ++i) {
        sortirajPoPoslednjemRedu(a);
    }
    printM(a);
}
char* swapWord(char* token,int length){
    char swapped[length+1];
    for (int i = 0; i < length; ++i) {
        swapped[i]=token[length-i-1];
    }
    swapped[length]=0;
    return swapped;
}

void zad3(char str[], int length) {
    char str2[length];
    strcpy(str2,str);
    char *token = strtok(str, " ");
    while (token != NULL) {
        char word[strlen(token)+1];
        for (int i = 0; i < strlen(token); ++i) {
            word[i]=token[strlen(token)-i-1];
        }
        word[strlen(token)]=0;
        //printf("%s\n",word);
        if(strstr(str2,word)){
            printf("%s<=>%s\n",token,word);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    /*printf("%lf\n", zad1(8,1));
    printf("%lf\n", zad1a(8));
    int a[][5]={
            {3, 6, 7, 5, 3},
            {5, 6, 2, 9, 1},
            {2, 7, 0, 9, 3},
            {6, 0, 6, 2, 6},
            {1, 8, 7, 9, 2}
    };
    zad2(a);*/
    char str[] = "abc eef cba eed ghi dee aaa";
    //printf("%p", strstr(str,"cbb"));
    zad3(str, strlen(str));


    return 0;
}
