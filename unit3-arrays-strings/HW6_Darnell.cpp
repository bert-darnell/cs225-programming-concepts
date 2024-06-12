/* Bert Darnell
 * Kenneth Dewey
 * CS225 - HW6
 * 4-2-2023
 *
 * This program is used to encrypt and decrypt text strings. The encryption function
 * takes a plain text string and transforms it into an encrypted string using a set
 * of rules, while the decryption function takes an encrypted string and translates 
 * it back into the original plain text string. The program also includes some sample
 * test cases to demonstrate how the encryption and decryption functions work.
 *
 *  Algorithm for decrypting a given cipher text string:
 *  
 *  1. Calculate the shift as the length of the cipher text string divided by 2.
 *  2. Create a new string with the same length as the cipher text string, filled with spaces.
 *  3. Loop over each character in the cipher text string:
 *    -Calculate the new index for the character based on the shift.
 *    -Get the character at the new index.
 *    -Apply the substitution:
 *    -Add the substituted character to the new string.
 *  4. Return the decrypted string.
 *
 * */

#include <iostream>
#include <string>

// Encrypts a given plain text string 
  std::string encrypt(std::string/*IN*/ plaintext) {
  int shift = plaintext.length() / 2; 
  std::string ecnryptedText(plaintext.length(), ' '); // create a string with the same length as plaintext, filled with spaces

  // loop over each character in the plaintext
  for (int i = 0; i < plaintext.length(); i++) {
    int shiftedIndex = (i + shift) % plaintext.length(); // calculate the new index for the character based on the shift
    char c = plaintext[shiftedIndex]; // get the character at the new index

    // apply the substitution rules
    if (c >= 'A' && c <= 'Z') {
      c = 'Z' - (c - 'A');
    } else if (c >= 'a' && c <= 'z') {
      c = 'z' - (c - 'a');
    } else if (c >= '0' && c <= '9') {
      c = '9' - (c - '0');
    }
    ecnryptedText[i] = c; // add the character to the new string
  }
  return ecnryptedText; // return the encrypted string
}

// Decrypts a given cipher text string.
std::string decrypt(std::string/*IN*/ ciphertext) {
  int shift = ciphertext.length() / 2; 
  std::string decryptedText(ciphertext.length(), ' '); // create a string with the same length as plaintext, filled with spaces


  // loop over each character in the ciphertext
  for (int i = 0; i < ciphertext.length(); i++) {
    int shiftedIndex = (i + ciphertext.length() - shift) % ciphertext.length(); // calculate the new index for the character
    char c = ciphertext[shiftedIndex]; 

    // apply the substitution
    if (c >= 'A' && c <= 'Z') {
      c = 'A' + ('Z' - c);
    } else if (c >= 'a' && c <= 'z') {
      c = 'a' + ('z' - c);
    } else if (c >= '0' && c <= '9') {
      c = '0' + ('9' - c);
    }
    decryptedText[i] = c; // add the substituted character to the new string
  }
  return decryptedText; // return the decrypted string
}
int main() {
  // Testing case 1: a short string with no special characters provided in assignment
  std::string str1 = "Secret 12";
  std::string secretStr1 = encrypt(str1);
  std::string decryptedStr1 = decrypt(secretStr1);
  std::cout << "original:  " << str1 << '\n';
  std::cout << "encrypted: " << secretStr1 << '\n';
  std::cout << "decrypted: " << decryptedStr1 << '\n';

  // Testing case 2: a string with uppercase and lowercase letters, digits, and special characters
  std::string str2 = "SeCret! P@ssw0rd";
  std::string secretStr2 = encrypt(str2);
  std::string decryptedStr2 = decrypt(secretStr2);
  std::cout << "original:  " << str2 << '\n';
  std::cout << "encrypted: " << secretStr2 << '\n';
  std::cout << "decrypted: " << decryptedStr2 << '\n';

  // Testing case 3: a very long string with repeated characters
  std::string str3 = "aaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccc";
  std::string secretStr3 = encrypt(str3);
  std::string decryptedStr3 = decrypt(secretStr3);
  std::cout << "original:  " << str3 << '\n';
  std::cout << "encrypted: " << secretStr3 << '\n';
  std::cout << "decrypted: " << decryptedStr3 << '\n';

  return 0;
}
