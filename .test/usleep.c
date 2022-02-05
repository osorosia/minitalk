#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int sec = 10000;
    if (argc > 1)
        sec = atoi(argv[1]);
    usleep(sec);
}
