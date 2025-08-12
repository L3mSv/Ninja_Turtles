#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addInjuredMember(Team* team, struct Mission* mission)
{
    Character* member = randomMember(team);
    member->status = "injured";
    remove_character_by_name(character_list, member->name);
    remove_from_team(team, member->name);
    add_node_character(&injured_character_list, member->name, member->status, member->level);
}