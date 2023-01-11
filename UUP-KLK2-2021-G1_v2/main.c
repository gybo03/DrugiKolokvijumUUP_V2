#include <stdio.h>
#include <math.h>
#include <string.h>

double zad1(int n, int i, int k, int j) {
    if (j == n) {
        return pow(k, j) + j;
    }
    if (n % 2 == 1) {
        if (j % 2 == 0) {
            if (j > n / 2) {
                return k + pow(i, j) / zad1(n, j + 1, k - (2 * j), j + 1);
            } else {
                return k + pow(i, j) / zad1(n, i - 1, k - (2 * j), j + 1);
            }
        } else {
            if (j > n / 2) {
                return pow(k, j) + (double) i / zad1(n, j + 1, k - (2 * j), j + 1);
            } else {
                return pow(k, j) + (double) i / zad1(n, i - 1, k - (2 * j), j + 1);
            }
        }
    } else {
        if (j % 2 == 1) {
            if (j > n / 2) {
                return k + pow(i, j) / zad1(n, j + 1, k - (2 * j), j + 1);
            } else {
                return k + pow(i, j) / zad1(n, i - 1, k - (2 * j), j + 1);
            }
        } else {
            if (j > n / 2) {
                return pow(k, j) + (double) i / zad1(n, j + 1, k - (2 * j), j + 1);
            } else {
                return pow(k, j) + (double) i / zad1(n, i - 1, k - (2 * j), j + 1);
            }
        }
    }
}

int findK(int n, int k) {
    for (int i = 1; i < n; ++i) {
        k = k - (2 * i);
    }
    return k;
}

double zad1a(int n) {
    int k = n * 8;
    int j = n / 2;
    k = findK(n, k);
    double sum = pow(k, j) + n;
    for (int i = n - 1; i > 0; --i) {
        k = k + (2 * i);

        if (n % 2 == 1) {
            if (i % 2 == 0) {
                if (i <= (n + 1) / 2) {
                    j++;
                    sum = k + pow(j, i) / sum;
                    printf("k=%d,i=%d,j=%d\n", k, i, j);
                } else {
                    sum = k + pow(i, i) / sum;
                    printf("k=%d,i=%d,j=%d\n", k, i, i);
                }

            } else {
                if (i < (n + 1) / 2) {
                    j++;
                    sum = pow(k, i) + (double) j / sum;
                    printf("k=%d,i=%d,j=%d\n", k, i, j);
                } else {
                    sum = pow(k, i) + (double) i / sum;
                    printf("k=%d,i=%d,j=%d\n", k, i, i);
                }
            }
        } else {
            if (i % 2 == 1) {
                if (i <= (n + 1) / 2) {
                    j++;
                    sum = k + pow(j, i) / sum;
                    printf("k=%d,i=%d,j=%d\n", k, i, j);
                } else {
                    sum = k + pow(i, i) / sum;
                    printf("k=%d,i=%d,j=%d\n", k, i, i);
                }

            } else {
                if (i < (n + 1) / 2) {
                    j++;
                    sum = pow(k, i) + (double) j / sum;
                    printf("k=%d,i=%d,j=%d\n", k, i, j);
                } else {
                    sum = pow(k, i) + (double) i / sum;
                    printf("k=%d,i=%d,j=%d\n", k, i, i);
                }
            }
        }

    }
    return sum;

}

int n = 4;

void printM(int a[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void shift(int prsten[], int duzinaPrstena, int k) {
    printf("\n");
    for (int i = 0; i < k; ++i) {
        int t = prsten[duzinaPrstena - 1];
        for (int j = duzinaPrstena - 1; j > 0; --j) {
            prsten[j] = prsten[j - 1];
        }
        prsten[0] = t;
    }
}

void zad2(int a[n][n], int k) {
    int brPrstenova = n / 2;
    for (int i = 0; i < brPrstenova; ++i) {
        int duzinaPrstena = 4 * (n - (2 * i)) - 4;
        int row = i, col = i;
        int hor = 1, ver = 0;
        int prsten[duzinaPrstena];
        int j = 0;
        //printf("%d\n",duzinaPrstena);
        while (j < duzinaPrstena) {
            prsten[j++] = a[row][col];
            if (row == i && col == n - 1 - i) {
                hor = 0;
                ver = 1;
            }
            if (row == n - 1 - i && col == n - 1 - i) {
                hor = -1;
                ver = 0;
            }
            if (row == n - 1 - i && col == i) {
                hor = 0;
                ver = -1;
            }
            col += hor;
            row += ver;
        }
        row = i, col = i;
        hor = 1, ver = 0;
        j = 0;
        shift(prsten, duzinaPrstena, k);
        while (j < duzinaPrstena) {
            a[row][col] = prsten[j++];
            if (row == i && col == n - 1 - i) {
                hor = 0;
                ver = 1;
            }
            if (row == n - 1 - i && col == n - 1 - i) {
                hor = -1;
                ver = 0;
            }
            if (row == n - 1 - i && col == i) {
                hor = 0;
                ver = -1;
            }
            col += hor;
            row += ver;
        }
    }
}
//ubedljivo najtezi zadatak iz stringova
int zad3(char S[], char P[], int len1, int len2) {
    char trenutnoSlovo = P[0];
    char prethodnoSlovo;
    int brSubStr = 0;
    int br = 1;
    int mogBr = 1;
    for (int i = 1; i < len2; ++i) {
        br = 0;
        if (trenutnoSlovo != P[i]) {
            for (int j = 0; j <= i; ++j) {
                if (P[i] != P[j]) {
                    trenutnoSlovo = P[j];
                    br++;
                }
            }
            if (br == i) {
                mogBr++;
            }
        }
    }
    //printf("%d\n",mogBr);
    trenutnoSlovo = P[0];
    for (int i = 0; i < mogBr; ++i) {
        //printf("\nprethodnoSlovo==%c trenutnoSlovo==%c\n", prethodnoSlovo, trenutnoSlovo);
        if (prethodnoSlovo != trenutnoSlovo) {
            int brSlova = 0;
            for (int k = 0; k < len1; ++k) {
                brSlova = 0;
                for (int j = 0; j < len2; ++j) {
                    if (P[j] != trenutnoSlovo) {
                        brSlova++;
                        //printf("%c", P[j]);
                    }
                }
                int poklopilo = 0;
                for (int j = k; j < k + brSlova + 1; ++j) {
                    for (int l = 0; l < len2; ++l) {
                        if (P[l] != trenutnoSlovo) {
                            if (S[j] == P[l]) {
                                //printf("trenutnoSlovo=%c k=%d S[j]=%c P[l]=%c\n",trenutnoSlovo,j,S[j],P[l]);
                                poklopilo++;
                                j++;
                            } else {
                                poklopilo = -1;
                                break;
                            }
                        }
                        if (poklopilo == -1) {
                            break;
                        }
                    }
                    //printf("------------------\n");
                    if (poklopilo == -1) {
                        break;
                    }
                }
                if (poklopilo == brSlova) {
                    //printf("POGODAK:trenutnoslovo= %c, k=%d\n------------------\n", trenutnoSlovo, k);
                    brSubStr++;
                }

            }
        }
        //odredjuje trenutno i prethodno slovo ako je p i t jednako ne ispisuje podstring
        for (int j = i+1; j < len2; ++j) {
            if (trenutnoSlovo != P[j]) {
                prethodnoSlovo = trenutnoSlovo;
                trenutnoSlovo = P[j];
                break;
            }
        }
    }
    return brSubStr;
}

int main() {
    /*printf("%lf\n", zad1(6, 6, 6 * 8, 1));
    printf("%lf", zad1a(6));
    int a[][4] = {{8, 1, 7, 5},
                  {8, 7, 4, 6},
                  {7, 4, 4, 9},
                  {0, 1, 3, 7}};
    printM(a);
    zad2(a, 2);
    printM(a);*/
    /*char str[] = "cbaebabacd";
    char str1[] = "abc";*/
    char str[] = "BBDDADADA";
    char str1[] = "ABBDA";
    /*char str[]="AAABABAA";
    char str1[]="AABA";*/
    printf("%d", zad3(str, str1, strlen(str), strlen(str1)));

    return 0;
}
