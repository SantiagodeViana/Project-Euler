//Código de 2017

//The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
//Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
//(Please note that the palindromic number, in either base, may not include leading zeros.)

var digits = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

// Check if a string is palindrome
var isPalindrome = function(str) {
    // base case #1
    if (str.length <= 1) {
        return true;
    }
    // base case #2
    if (digits[0] !== lastCharacter(str)) {
        return false;
    }
    // recursive case
        return isPalindrome(middleCharacters(str));
};

// Converts a decimal to binary 
var toBinary = function(n) {
    // If the decimal is odd
    if (n % 2 !== 0){
        
    }
    // If the decimal is even
};
