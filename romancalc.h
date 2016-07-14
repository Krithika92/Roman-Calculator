
#ifndef ROMANCALC_H
#define ROMANCALC_H

int isvalidRoman(char *roman);
int chartoNum(char c);
int convertToDecimal(char *roman);

char *convertToRoman(int numeral);

char *addRoman(char *rom1, char *rom2);
char *subRoman(char *rom1, char *rom2);

#endif
