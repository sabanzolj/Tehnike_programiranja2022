#include <stdio.h>
#include <conio.h>

int main() {
    unsigned char data;

    // Čitanje podataka iz paralelnog porta
    data = inp(0x378); // Port adresiran na 0x378

    // Pisanje podataka u paralelni port
    outp(0x378, data); // Port adresiran na 0x378

    // Čitanje statusnog registra paralelnog porta
    unsigned char status = inp(0x379); // Statusni registar na adresi 0x379

    return 0;
}