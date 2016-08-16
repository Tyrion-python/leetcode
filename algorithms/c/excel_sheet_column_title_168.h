//
// Created by Tyrion on 2016/8/12.
//

#ifndef LEETCODE_EXCEL_SHEET_COLUMN_TITLE_168_H
#define LEETCODE_EXCEL_SHEET_COLUMN_TITLE_168_H

char* convertToTitle(int n) {
    char temp_col[32];
    int length = 0, tail;
    long long int temp = n; //consider overflow
    while( temp > 0 )
    {
        tail = (temp+25) % 26;
        temp_col[length++] = tail+65;
        temp = (temp-tail) / 26;
    }

    char* ret_col = (char*) malloc(sizeof(char)*(length+1));
    for(int i = 0; i < length; i++)
    {
        ret_col[i] = temp_col[length - i - 1];
    }
    ret_col[length] = 0;
    return ret_col;
}
#endif //LEETCODE_EXCEL_SHEET_COLUMN_TITLE_168_H
