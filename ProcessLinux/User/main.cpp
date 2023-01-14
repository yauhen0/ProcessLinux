#include <iostream>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    putenv("PROC_TO_KILL=telegram-desktop");
    fork();
    execv("./../../Killer/cmake-build-debug/Killer",argv);
}
