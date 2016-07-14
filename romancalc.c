#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "romancalc.h"

char *roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int decimal[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};


int isvalidRoman(char *roman){
	char *p;
	for (p = roman;*p!='\0';++p){
		if (*p!= 'I' && *p != 'V' && *p != 'X' && *p != 'L' && *p != 'C' && *p != 'D' && *p != 'M'){
			return 0;  
		}
	}
	return 1;
}

char *convertToRoman(int numeral){
	char *romanNum = (char *)malloc(sizeof(char));
	int i,len = 13;
	for (i=0; i<len;i++){
		while(decimal[i]<=numeral){
			strcat(romanNum,roman[i]);
			numeral -= decimal[i];
		}
	}
	return romanNum;
}
int chartoNum(char c){
	switch(c){
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
	}
}

int convertToDecimal(char *roman){
	char prev = '%';
	int i,len = strlen(roman),sum = 0;
	for(i = 0;i < len;++i){
		if(i > 0 && chartoNum(roman[i]) > chartoNum(roman[i-1]))
			sum+= (chartoNum(roman[i]) - 2*(chartoNum(roman[i-1])));
		else
			sum += chartoNum(roman[i]);
		}
	return sum;
}

char *addRoman(char *rom1, char *rom2){
	char *ans = (char*)malloc(sizeof(char));
	if (isvalidRoman(rom1) && isvalidRoman(rom2)){
		int num1 = convertToDecimal(rom1);
		int num2 = convertToDecimal(rom2);
		int sum = num1 + num2;
		ans = convertToRoman(sum);
		return ans;
	}
	return "Invalid numbers";
}

char *subRoman(char *rom1, char *rom2){
	char *ans = (char*)malloc(sizeof(char));
	if (isvalidRoman(rom1) && isvalidRoman(rom2)){
		int num1 = convertToDecimal(rom1);
		int num2 = convertToDecimal(rom2);
		if (num1 > num2){
			int sub = num1 - num2;
			ans = convertToRoman(sub);
			return ans;
		}
	}
	return "Invalid numbers";
}

/*int main(int argc, char *argv[]){
	char *add = addRoman(argv[1],argv[2]);
	char *sub = subRoman(argv[1],argv[2]);
	printf("\nAddition: %s\nSubtraction: %s\n",add,sub);
	return 1;
}*/
