/*
Author: Sam Rixford
Date: 10/22/2022
Description: A Bacon cipher that takes english words and converts them to bacon code or converts bacon code into english words. 
Usage: <exe> <input file> <-bc\-e> <output file>
 */
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

// converts a given english letter (or space) and converts it into bacon code.
const char* englishToBaconCode(char letter) {

  //uses a switch case that switches from each letter (either case) and turns it into its bacon code.
  switch (letter) {
 
  case 'a':
  case 'A':
    return "aaaaa";
    break;
     
  case 'b':
  case 'B':
    return "aaaab";
    break;

  case 'c':
  case 'C':
    return "aaaba";
    break;

  case 'd':
  case 'D':
    return "aaabb";
    break;

  case 'e':
  case 'E':
    return "aabaa";
    break;

  case 'f':
  case 'F':
    return "aabab";
    break;

  case 'g':
  case 'G':
    return "aabba";
    break;

  case 'h':
  case 'H':
    return "aabbb";
    break;

  case 'i':
  case 'I':
    return "abaaa";
    break;

  case 'j':
  case 'J':
    return "abaab";
    break;

  case 'k':
  case 'K':
    return "ababa";
    break;

  case 'l':
  case 'L':
    return "ababb";
    break;

  case 'm':
  case 'M':
    return "abbaa";
    break;

  case 'n':
  case 'N':
    return "abbab";
    break;

  case 'o':
  case 'O':
    return "abbba";
    break;

  case 'p':
  case 'P':
    return "abbbb";
    break;

  case 'q':
  case 'Q':
    return "baaaa";
    break;

  case 'r':
  case 'R':
    return "baaab";
    break;

  case 's':
  case 'S':
    return "baaba";
    break;

  case 't':
  case 'T':
    return "baabb";
    break;

  case 'u':
  case 'U':
    return "babaa";
    break;

  case 'v':
  case 'V':
    return "babab";
    break;

  case 'w':
  case 'W':
    return "babba";
    break;

  case 'x':
  case 'X':
    return "babbb";
    break;

  case 'y':
  case 'Y':
    return "bbaaa";
    break;

  case 'z':
  case 'Z':
    return "bbaab";
    break;

    // have the space as a single character string.
  case ' ':
    return "/";
    break;

    //if something other than a letter or space is entered, return the error bacon code.
  default:
    return "!!!!!";
  }

}

//turns bacon code into english given a string of bacon code.
char baconCodeToEnglish (const char* bacon) {

  // since switch cases don't take strings, I used if statements and strcmp in order to compare the given bacon code with the corresponding bacon code for each letter.

  if(strcmp(bacon, "aaaaa") == 0){
    return 'A';
  }

  else if(strcmp(bacon, "aaaab") ==0) {
    return 'B';
  }
  
  else if(strcmp(bacon, "aaaba") ==0) {
    return 'C';
  }

  else if(strcmp(bacon, "aaabb") ==0) {
    return 'D';
  }
 
  else if(strcmp(bacon, "aabaa") ==0) {
    return 'E';
  }
  
  else if(strcmp(bacon, "aabab") ==0) {
    return 'F';
  }
 
  else if(strcmp(bacon, "aabba") ==0) {
    return 'G';
  }
 
  else if(strcmp(bacon, "aabbb") ==0) {
    return 'H';
  }

  else if(strcmp(bacon, "abaaa") ==0) {
    return 'I';
  }

  else if(strcmp(bacon, "abaab") ==0) {
    return 'J';
  }

  else if(strcmp(bacon, "ababa") ==0) {
    return 'K';
  }

  else if(strcmp(bacon, "ababb") ==0) {
    return 'L';
  }

  else if(strcmp(bacon, "abbaa") ==0) {
    return 'M';
  }

  else if(strcmp(bacon, "abbab") ==0) {
    return 'N';
  }

  else if(strcmp(bacon, "abbba") ==0) {
    return 'O';
  }

  else if(strcmp(bacon, "abbbb") ==0) {
    return 'P';
  }

  else if(strcmp(bacon, "baaaa") ==0) {
    return 'Q';
  }

  else if(strcmp(bacon, "baaab") ==0) {
    return 'R';
  }

  else if(strcmp(bacon, "baaba") ==0) {
    return 'S';
  }

  else if(strcmp(bacon, "baabb") ==0) {
    return 'T';
  }

  else if(strcmp(bacon, "babaa") ==0) {
    return 'U';
  }

  else if(strcmp(bacon, "babab") ==0) {
    return 'V';
  }

  else if(strcmp(bacon, "babba") ==0) {
    return 'W';
  }

  else if(strcmp(bacon, "babbb") ==0) {
    return 'X';
  }

  else if(strcmp(bacon, "bbaaa") ==0) {
    return 'Y';
  }

  else if(strcmp(bacon, "bbaab") ==0) {
    return 'Z';
  }

  else if(strcmp(bacon, "/") ==0) {
    return ' ';
  }

  else {
    return '#';
  }
  

}

int main (int argc, char** argv) {

  //if there is not the right amount of arguments, return an error message.
  if (argc != 4) {
    cout << "Error -- usage: <exe> <input file> <-bc|-e> <output file>" << endl;
      }
  else {

    //store the arguments after the exe as 3 string variables.
  const char* input = argv[1];
  const char* select = argv[2];
  const char* output = argv[3];

  //use the input variable above to designate it as the file to read.
  ifstream infile;
  infile.open(input, ios::in);

  //use the output variable above to designate it as the file to write.
  ofstream outfile;
  outfile.open(output, ios::out);

  
  // need to use two if statements for the string comparison of the select in order to compare it to -bc or -e.
  if(strcmp(select, "-bc") ==0) {
    cout << "Translating " << input << " to BACON code" << endl;
    char inputLine[256];

    //while it is not the end of the file, store the next line to inputLine variable.
    while (!infile.eof()) {
    infile.getline(inputLine, 256);

    // for each character in the line, as long as it isn not the end of the line '\0', then convert from english to bacon and write it into the outfile.
    int i = 0;
    while (inputLine[i] != '\0') {
      const char* temp = englishToBaconCode(inputLine[i]);
      outfile << temp;
      ++i;
    
      //if it is the end of the line, write a new line.
    if (inputLine[i] == '\0') {
      outfile << "\n";
    }
    //else if it is just the end of the letter, insert |.
    else {
      outfile << "|";
    }
    }
    }
    cout << output << " file completed." << endl;
    }

  //seeing if the select is to convert to english.
    if(strcmp(select, "-e") ==0) {
    cout << "Translating " << input << " to English" << endl;

    //create the input variable for infile and the token to tokenize.
    char inputLine[1600];
    char* token; 

    //while it is not the end of the file, getline and store it into inputline.
    while (!infile.eof()) {
      infile.getline(inputLine, 1600);

      // split the input by | and store the first read into token.
      token = strtok(inputLine, "|"); 

      //while there is a token, convert it to english, store it into the outfile, and keep tokenizing untill it is NULL.
      while (token != NULL) {
	char letter = baconCodeToEnglish(token);
        outfile << letter;
	token = strtok(NULL, "|");
      }
      // once there is a null, write a new line.
      outfile << "\n";
    }

	cout << input << " file completed." << endl; 
    }


  
  }
}
