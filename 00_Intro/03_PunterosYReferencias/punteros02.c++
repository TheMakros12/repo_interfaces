#include <stdio.h>
#include <iostream>

using namespace std;

void hazNegativo(int *pNum) {
    if (*pNum > 0) {
        *pNum = -(*pNum);
    }
}

int main(int argc, char *argv[]) {

    int i;
    i = 8;

    hazNegativo(&i);

    return 0;
}
