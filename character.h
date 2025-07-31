#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct Character{
    const char* name;
    char* status;
    const char* type;
    int level;
}Character;


void createCharacter(const char* name, char* status, const char* type, int level);
void verifyStatus(Character* character);
#endif 