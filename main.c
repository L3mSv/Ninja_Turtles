#include <stdio.h>
#include "jogo.h"


int main(){
    srand(time(NULL));

    initialize_team();

    logbook = malloc(sizeof(Pilha));
    stackInicialization(logbook);

    getting_weapon_from_file(&weapon_list);
    getting_characters_from_file(&character_list);
    injured_list_inicialization(character_list);
    
    get_villains_from_file(&villains);

    Panel = createHeap(10);
    addMissionToPanel();

    cleanTerminal(); 
    introduction();

    commandCentral();

    return 0;
}