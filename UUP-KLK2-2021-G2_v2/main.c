#include <stdio.h>
#include <math.h>
#include <string.h>

double zad1(int n, int i, int k, char c) {
    if (abs(k) == 1) {
        return c + (double) i / (c + k);
    }
    if (n % 2 == 0) {
        if (k % 2 == 0) {
            if (k < (n + 1) / 2) {
                return c + (double) i / zad1(n, i + 1, k - 1, c - k);
            } else {
                return c + (double) i / zad1(n, i - 1, k - 1, c - k);
            }
        } else {
            if (k < (n + 1) / 2) {
                return c + (double) i / zad1(n, i + 1, k - 1, c + k);
            } else {
                return c + (double) i / zad1(n, i - 1, k - 1, c + k);
            }
        }
    } else {
        if (k % 2 == 0) {
            if (k < (n + 1) / 2) {
                return c + (double) i / zad1(n, i + 1, k - 1, c + k);
            } else {
                return c + (double) i / zad1(n, i - 1, k - 1, c + k);
            }
        } else {
            if (k < (n + 1) / 2) {
                return c + (double) i / zad1(n, i + 1, k - 1, c - k);
            } else {
                return c + (double) i / zad1(n, i - 1, k - 1, c - k);
            }
        }
    }
}
double zad1a(int n) {
    char c = 'A';
    for (int i = n - 1; i > 0; --i) {
        if (n % 2 == 0) {
            if (i % 2 == 0) {
                c = ((c - 48) - i) + 48;
            } else {
                c = ((c - 48) + i) + 48;
            }
        } else {
            if (i % 2 == 0) {
                c = ((c - 48) + i) + 48;
            } else {
                c = ((c - 48) - i) + 48;
            }
        }
    }
    double sum = c;
    int k = n / 2;
    //printf("slovo=%c menjacslova=%d i=%d\n", c,i,k);
    for (int i = 1; i < n; ++i) {
        printf("slovo=%c menjacslova=%d i=%d\n", c, i, k);

        if (n % 2 == 0) {
            if (i % 2 == 0) {
                c = ((c - 48) + i) + 48;
            } else {
                c = ((c - 48) - i) + 48;
            }
        } else {
            if (i % 2 == 0) {
                c = ((c - 48) - i) + 48;
            } else {
                c = ((c - 48) + i) + 48;
            }
        }

        sum = c + (double) k / sum;
        if (n % 2 == 0) {
            if (i < (n + 1) / 2) {
                k--;
            } else {
                k++;
            }
        } else {
            if (i < (n - 1) / 2) {
                k--;
            } else if (i == (n - 1) / 2) {
            } else {
                k++;
            }
        }

    }
    return sum;
}
int n=4;
void ispisi(int a[n][n]);
void spoljasnjaPostajeGlavna(int a[n][n], int b[n][n]){
    int temp[n];
    for (int i = 0; i < n; ++i) {
        temp[i]=a[i][i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j >=0 ; --j) {
            if(i+j==n-1){
                b[i][j]=temp[j];
            }
        }
    }
}
void glavnaPostajeSpoljasnja(int a[n][n],int b[n][n]){
    int temp[n];
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j >=0 ; --j) {
            if(i+j==n-1){
                temp[j]=a[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        b[i][i]=temp[i];
    }

}
int maxSused(int a[n][n],int i,int j){
    int temp[4];
    if(i-1>=0){
        temp[0]=a[i-1][j];
    }
    else{
        temp[0]=0;
    }
    if(i+1<n){
        temp[1]=a[i+1][j];
    }
    else{
        temp[1]=0;
    }
    if(j-1>=0){
        temp[2]=a[i][j-1];
    }
    else{
        temp[2]=0;
    }
    if(j+1<n){
        temp[3]=a[i][j+1];
    }
    else{
        temp[3]=0;
    }
    int max=0;
    for (int k = 0; k < 4; ++k) {
        if(temp[k]%2==0){
            if(max<temp[k]){
                max= temp[k];
            }
        }
    }
    return max;

}
void ispisi(int a[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void zad2(int a[n][n],int b[n][n]){
    ispisi(b);
    spoljasnjaPostajeGlavna(a,b);
    ispisi(b);
    glavnaPostajeSpoljasnja(a,b);
    ispisi(b);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==j||i+j==n-1){
                continue;
            }
            b[i][j]= maxSused(a,i,j);
        }
    }
    ispisi(b);
}

typedef struct{
    char* rec;
    int brPon;
}Rec;
Rec upisiRec(char* rec,int brPon){
    Rec r;
    r.rec=rec;
    r.brPon=brPon;
    return r;
}
void ispisiRec(Rec rec){
    printf("Rec=%s, brPon=%d\n",rec.rec,rec.brPon);
}
int brReci(char str[],int length){
    int j=1;
    for (int i = 0; i < length; ++i) {
        if(str[i]==' '){
            j++;
        }
    }
    return j;
}
void zad3(char str[],int length){
    int duzina=brReci(str,length);
    Rec reci[duzina];
    char* tok= strtok(str," ");
    for (int i = 0; i < duzina; ++i) {
        reci[i]=upisiRec(tok,0);
        tok=strtok(NULL," ");
    }
    for (int i = 0; i < duzina; ++i) {
        for (int j = 0; j < duzina; ++j) {
            if(strcmp(reci[i].rec,reci[j].rec)==0){
                reci[i].brPon++;
                //reci[j].brPon++;
            }
        }
    }
    /*for (int i = 0; i < duzina; ++i) {
        ispisiRec(reci[i]);
    }*/
    int min= duzina+1;
    for (int i = 0; i < duzina; ++i) {
        if(reci[i].brPon<min){
            min=reci[i].brPon;
        }
    }
    for (int i = 0; i < duzina; ++i) {
        if(reci[i].brPon!=min){
            printf("%s ",reci[i].rec);
        }
    }

}

int main() {
    /*printf("%lf\n", zad1(8,8/2,8-1,'A'));
    printf("%lf", zad1a(7));
    int a[][4]={{2, 6, 1, 4},{3, 5, 6, 8},{4, 1, 8, 0},{9, 6, 3, 7}};
    int b[][4]={{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};
    zad2(a,b);*/
    char str[]="hill forest woods lake forest hill";
    char str1[]="castle flower rose flower castle rose flower";
    zad3(str1,strlen(str1));
    return 0;
}
