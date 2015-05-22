#include <stdio.h>

int c[2][10];
int po[10];

void count(int x , int up);

int main(){
    int a,b,i;
    po[0] = 1;
    for(i = 1; i < 10; ++i)
        po[i] = 10 * po[i - 1];

    for(;scanf("%d%d", &a, &b) && a;){
        for(i = 0; i < 10; ++i)
            c[0][i] = c[1][i] = 0;
        count(b, 1);
        count(a - 1, 0);
        for(i = 0; i < 10; ++i){
            if(i)
                putc(32, stdout);
                printf("%d", c[1][i] - c[0][i]);
        }
        putc(10, stdout);
    }
    return 0;
}

void count(int x , int up){
    int *cnt = c[up], d, dcnt = 0, r = 0, rem0 = 0, v,i;
    while(x){
        d = x % 10; x /= 10;
        if(dcnt){
            v = d * po[dcnt - 1] * dcnt;
            for(i = 0; i < 10; ++i)
                cnt[i] += v;
            if(!d)
                rem0 += (po[dcnt] - 1) - r;
        }
        v = po[dcnt];
        for(i = 1; i < d; ++i) cnt[i] += v;
        if(d)
            cnt[d] += r + 1;
        r = po[dcnt++] * d + r;
    }
    cnt[0] -= rem0;
}
//@end_of_source_code

