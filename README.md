# Roman-Calculator

"int isvalidRoman()" function checks if the character entered is a valid numeral or not. If it doesn't fall under the characters I,V,X,L,C,D and M, then it means that the character entered is an Invalid entry. 

Initially the Roman numeral is taken as input and in the "int convertToDecimal()" function, the Roman numeral is converted to Decimal number by making use of the "int chartoNum()" function. 

Then in order to add or subtract the two roman numeral entries, "char *addRoman()" and "char *subRoman()" functions are used. First, it checks whether both the entries are valid or not. If found to be valid, they are added or subtracted. Otherwise, "Invalid numbers" information gets displayed. During subtraction, it is also taken into consideration whether the first entry is greater than the second entry. If not, then "Invalid numbers" gets displayed.

The added and subtracted values are then converted back to roman numerals, using the "convertToRoman()" function. 
