/* 12 What is the value of the first triangle number to have over five hundred
 * divisors?
 */
 
#include <stdio.h>

int get_divisors(int n)
{
    int i;
    int count = 1;
    for (i = 2; i <= n; i++) {
        int j = 1;
        while (n % i == 0) {
            n /= i;
            j++;
        }
        count *= j;
    }
    return count;
}

int solve(int count)
{
    int n, i;
    for (i = 1, n = 1; ; n += ++i) {
        int c = get_divisors(n);
        if (c >= count)
            break;
    }
    return n;
}

int main()
{
    printf("%d\n", solve(500));
    return 0;
}
