/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 200000

// input data
int N, K, Q, P, i;
int V[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &K));
    assert(2 == scanf("%d%d", &P, &Q));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &V[i]));

    // insert your code here

    printf("%d\n", 42); // print the result
    return 0;
}