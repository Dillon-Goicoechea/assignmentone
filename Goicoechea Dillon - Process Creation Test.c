#include <stdio.h>
int fibonacci(int n){
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
   printf("What do you call a cow that's been knighted? Sir Loin!");
   fibonacci(45);
   return 0;
}