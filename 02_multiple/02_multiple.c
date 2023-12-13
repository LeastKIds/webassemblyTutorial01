#include <stdio.h>

void multiple(int grades) {
    for(int i=1; i<10; i++) 
        printf("%d * %d = %d \n", grades, i, grades * i);
}

int main() {
    multiple(2);

    return 0;
}