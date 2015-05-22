// OMG It's work!! xD
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <vector>

using namespace std;

#define IN getc ( stdin )
#define MAX 100038

int arr1[MAX], arr2[MAX], arr3[MAX], arr4[MAX];
vector < int > var[MAX];

void scanfnow( register int *n ){
    register char c;
    *n = 0;
    while(!isdigit(c = IN));
    do { *n = 10 * *n + c - '0'; } while(isdigit(c = IN));
}

int main(void){
    int N, T;
    while(scanf("%d %d", &N, &T) && N){
        for(int i = 0; i <= N; ++i){
            arr1[i] = arr4[i] = 0;
            var[i].clear();
        }
        for(int i = 1; i <= N; ++i){
            scanfnow(&arr2[i]);
            ++arr1[arr2[i]];
        }
        int h, t;
        h = t = 0;
        for(int i = 1; i <= N; ++i) arr3[t] = i, t += !arr1[i];
        while(h != t){
            int x = arr3[h++], k = 0;
            int limite = (var[x].size() * T + 99)/100;
            vector < int > :: iterator iter;
            if(!var[x].size()) arr4[x] = 1;
            else {
                sort(var[x].begin(), var[x].end());
                for(iter = var[x].begin(); k < limite; iter++, k++) arr4[x] += *iter;
            }
            if(!x) break;
            if(!--arr1[arr2[x]]) arr3[t++] = arr2[x];
            var[arr2[x]].push_back(arr4[x]);
        }
        printf("%d\n", arr4[0]);
    }
    return 0;
}
