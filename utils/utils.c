#include <stdio.h>
#include <string.h>
#include "utils.h"

#ifdef _WIN32
    #include <windows.h>
    void espera(unsigned int tempo_ms) {
        Sleep(tempo_ms);
    }
#else
    #include <unistd.h>
    void espera(unsigned int tempo_ms) {
        usleep(tempo_ms * 1000);
    }
#endif

void print_lento(const char* texto, unsigned int delay_ms)
{
    for(int i = 0; texto[i] != '\0'; ++i)
    {
        putchar(texto[i]);
        fflush(stdout);
        espera(delay_ms);
    }
}
