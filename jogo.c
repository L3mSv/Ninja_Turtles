#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "bibliotecas/pilha.h"
#include "utils/utils.h"
#include "jogo.h"

int main(){
    system("clear"); //limpa tela para Linux/macOS
    system("cls"); //Limpa tela para Windows

     char* Introducao = 
     "\033[31mA cidade de Nova York esta um caos\033[0m!\n"
     " O Destruidor e Krang uniram forcas, e o Cla do Pe, junto com mutantes como Bebop e Rocksteady, estao executando varios planos malignos ao mesmo tempo.\n"
     "As Tartarugas Ninja estao sobrecarregadas, para organizar a defesa da cidade Donatello decidiu criar um sistema de computador avancado, a \033[1m\"Central de Comando\"\033[0m,\n" 
     "para gerenciar as missoes, catalogar os viloes e otimizar as operacoes do time.\n"
     "\nSua missao e ajudar as Tartarugas Ninja a combater o mal sobre Nova York e restaurar a paz atraves de ordens pela Centra de Comando. \033[33mBoa sorte\033[0m\n";

     print_lento(Introducao , 100);

     
}