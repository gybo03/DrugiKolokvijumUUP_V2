#include <stdio.h>
#include <math.h>
#include <string.h>

double zad1(int n, int i) {
    if (n == i) {
        if (n % 2 == 0) {
            return sqrt((double) n / pow(i + 1, 2));
        } else {
            return sqrt((double) n / (i + 1));
        }
    }
    if (i % 2 == 0) {
        return sqrt((double) i / pow(i + 1, 2) + zad1(n, i + 1));
    } else {
        return sqrt((double) i / (i + 1) + (i + 1) * zad1(n, i + 1));
    }
}

double zad1a(int n) {
    double sum = 0;
    for (int i = n; i > 0; --i) {
        if (i % 2 == 0) {
            sum = sqrt((double) i / pow(i + 1, 2) + sum);
        } else {
            sum = sqrt((double) i / (i + 1) + (i + 1) * sum);
        }
    }
    return sum;
}

int m = 4, n = 6;

void printM(int a[m][n]) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void zad2(int a[m][n]) {
    int min;
    int temp[4];
    for (int i = 0; i < m - 2; ++i) {
        for (int j = 0; j < n - 2; ++j) {
            if (i == m - 3 || j == n - 3) {
                min = 3;
            } else {
                min = fmin(m, n);
            }
            for (int k = min; k > 2; --k) {
                temp[0] = a[i][j];
                temp[1] = a[i][j + k - 1];
                temp[2] = a[i + k - 1][j];
                temp[3] = a[i + k - 1][j + k - 1];
                //printf("gl=%d,gd=%d,dl=%d,dd=%d\n",a[i][j],a[i][j+k-1],a[i+k-1][j],a[i+k-1][j+k-1]);
                int brPon = 0;
                for (int l = i; l < i + k - 1; ++l) {
                    for (int _ = j; _ < j + k - 1; ++_) {
                        if ((l == i && _ == j) || (l == i && _ == j + k - 1) || (l == i + k - 1 && _ == j) ||
                            (l == i + k - 1 && _ == j + k - 1)) {
                            continue;
                        }
                        for (int i1 = 0; i1 < 4; ++i1) {
                            if (a[l][_] == temp[i1]) {
                                brPon = 1;
                                break;
                            }
                        }
                        if (brPon == 1) {
                            break;
                        }
                    }
                    if (brPon == 1) {
                        break;
                    }
                }
                if (brPon == 0) {
                    printf("(%d,%d) dimenzija %d x %d\n", i, j, k, k);
                }
            }
        }
    }
}

typedef struct {
    char *rec;
    int brSlova;
    int index;
} Rec;

Rec napraviRec(char *rec, int index) {
    Rec r;
    r.rec = rec;
    r.brSlova = strlen(rec);
    r.index = index;
    return r;
}

void printRec(Rec rec) {
    printf("rec=%s, brSlova=%d, index=%d\n", rec.rec, rec.brSlova, rec.index);
}

int brReci(char str[], int length) {
    int br = 1;
    for (int i = 0; i < length; ++i) {
        if (str[i] == ' ') {
            br++;
        }
    }
    return br;
}

int odKogIndeksaTrebaDaSePregleda(int i, Rec reci[]) {
    int j = 0;
    int k = 0;
    while (i >= j) {
        j = j + reci[k++].brSlova + 1;
    }
    return j;
}

int saberiSveDuzine(Rec reci[], int i) {
    int sum = 0;
    for (int j = 0; j < i; ++j) {
        sum = reci[j].brSlova + sum + 1;
    }
    return sum;
}

int nadjiIndexReci(int i, Rec reci[]) {
    int j = 0;
    int k = 0;
    while (i >= j) {
        j = j + reci[k++].brSlova + 1;
    }
    return k;
}

void zad3(char str[], int length) {
    char temp[length];
    strcpy(temp, str);
    char *tok = strtok(str, " ");
    int duzina = brReci(str, length) + 1;
    Rec reci[duzina];
    int i = 0;
    while (tok != NULL) {
        reci[i] = napraviRec(tok, saberiSveDuzine(reci, i));
        i++;
        tok = strtok(NULL, " ");
    }
    /*for (int j = 0; j < duzina; ++j) {
        printRec(reci[j]);
    }*/
    //printf("%d", saberiSveDuzine(reci,1));
    //printf("%d", odKogIndeksaTrebaDaSePregleda(8,reci));
    printf("%d", nadjiIndexReci(42,reci));
    char sub[4];
    for (int j = 0; j < length - 2; ++j) {
        sub[0] = temp[j];
        sub[1] = temp[j + 1];
        sub[2] = temp[j + 2];
        sub[3] = 0;
        if (sub[0] == ' ' || sub[1] == ' ' || sub[2] == ' ') {
            continue;
        }
        char sub2[4];
        for (int k = odKogIndeksaTrebaDaSePregleda(j, reci); k < length; ++k) {
            sub2[0] = temp[k];
            sub2[1] = temp[k + 1];
            sub2[2] = temp[k + 2];
            sub2[3] = 0;
            if (sub2[0] == ' ' || sub2[1] == ' ' || sub2[2] == ' ') {
                continue;
            }
            if (strcmp(sub, sub2) == 0) {
                printf("%s  %s\n", reci[nadjiIndexReci(j, reci)-1].rec, reci[nadjiIndexReci(k, reci)-1].rec);
            }
        }
    }
}

int main() {
    /*printf("%lf\n", zad1(6, 1));
    printf("%lf\n", zad1a(6));
    int a[][6]={{1, 2, 3, 4, 1, 3},
                {3, 1, 4, 1, 5, 9},
                {2, 4, 1, 7, 6, 8},
                {5, 5, 3, 1, 9, 2}};
    zad2(a);*/
    char str[] = "pravac jug jugozapad moj zdrav zivot moja pravila";
    zad3(str, strlen(str));

    return 0;
}
