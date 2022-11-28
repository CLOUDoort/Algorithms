#include <stdio.h>

int main()
{
    int prime[1000];
    prime[0] = 2;
    prime[1] = 3;
    int guess = 5;
    int index = 1;
    int ok;
    
    for(;;) {
        ok = 0;
        for(int i = 0; i<= index; i++) {
            if(guess % prime[i] != 0) ok++;
            else break;
        }
        if(ok == index + 1) {
            index++;
            prime[index] = guess;
            printf("소수 : %d\n", prime[index]);
            if(index == 999) break;
        }
        guess += 2;
    }

}