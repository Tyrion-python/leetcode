//
// Created by Tyrion on 2016/8/12.
//

#ifndef LEETCODE_RANSOM_NOTE_383_H
#define LEETCODE_RANSOM_NOTE_383_H

#define MAX_LENGTH 256
bool canConstruct(char* ransomNote, char* magazine) {
    int magazine_list[MAX_LENGTH] = {0};
    int i;

    for(i = 0; i < strlen(magazine); i++)
        magazine_list[magazine[i]]++;

    for(i = 0; i < strlen(ransomNote); i++)
    {
        if(magazine_list[ransomNote[i]] == 0)
            return false;
        else
            magazine_list[ransomNote[i]]--;
    }
    return true;
}
#endif //LEETCODE_RANSOM_NOTE_383_H
