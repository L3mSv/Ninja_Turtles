#include <stdio.h>
#include <string.h>
#include <time.h>
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

void fala_aleatoria(const char* nomeTartaruga, const char* caminho){
    FILE* file = fopen(caminho, "r");

    if(file == NULL)
    {
        perror("Erro ao abrir o arquivo texto das falas");
        return;
    }

    char* falas[100];
    int count = 0;
    char linha[256];

    while(fgets(linha, sizeof(linha), file))
    {
        falas[count] = malloc(strlen(linha) + 1);
        if(falas[count]){
            strcpy(falas[count], linha);
            count++;
        }
    }

    fclose(file);

    if (count > 0) {
        srand(time(NULL));
        int escolha = rand() % count;

        // Cores ANSI (apenas exemplo visual)
        const char* cor = "\033[0m"; // padrão
        if (strcasecmp(nomeTartaruga, "Donatello") == 0) cor = "\033[95m";       
        else if (strcasecmp(nomeTartaruga, "Rafael") == 0) cor = "\033[91m";    
        else if (strcasecmp(nomeTartaruga, "Leonardo") == 0) cor = "\033[94m";   
        else if (strcasecmp(nomeTartaruga, "Michelangelo") == 0) cor = "\033[93m"; 

        printf("\n%s%s\033[0m: %s", cor, nomeTartaruga, falas[escolha]);
    }

    for(int i = 0; i < count; ++i)
    {
        free(falas[i]);
    }
}
