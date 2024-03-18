#include <iostream>
#include "hangman.h"

using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;

/***
    Args:
        min (int): left margin of a range
        max (int): right margin of a range
    Returns:
        number (int) : random number in range [min; max]
***/
int generateRandomNumber(const int min, const int max)
{
    // TODO: Return a random integer number between min and max
    return rand() % (max-min+1) + min;
}

vector<string> readWordListFromFile(const string& filePath)
{
    vector<string> wordList;
    string word;
    ifstream wordFile (filePath);
    if (!wordFile.is_open()) {
        throw domain_error("Unable to open file");
    }

    //while ( getline (wordFile, word) ){  // Thong thuong doc tung line.
                                           // Chuong trinh nay cung chay.
    while (wordFile >> word) {  // Nhung voi chuong trinh nay, doc tung word cung duoc
                                // Tuc ca 2 cach doc deu chay.
        wordList.push_back(word);
        //cout << word << '\n';
    }
    wordFile.close();

    return wordList;
}

/***
    Args:
        ch (char): A character
        word (string): a word
    Returns:
        result (bool) : the character ch is in the word or not.
***/
bool isCharInWord(const char ch, const string& word)
{
    // TODO: return true if ch is in word else return false
    return word.find(ch)!=string::npos;
}

/***
    Args:
        wordList (vector<string>): A list of words
        index (int): an integer number
    Returns:
        answer (string) : the lowercase word is in the position index of wordList
***/
string chooseWordFromList(const vector<string>& wordList, int index)
{
    // TODO: Return a lowercase word in the index position of the vector wordList.
    string answer;

    answer=wordList[index];
    for(int i=0;i<answer.length();i++){
        answer[i]=tolower(answer[i]);
    }
    return answer;
}

/***
    Args:
        answerWord (string): a word that player needs to guess
    Returns:
        secretWord (string): answerWord in hidden form (form of ---)
***/
string generateHiddenCharacters(string answerWord){
    // TODO: Based on answerWord's length, generate hidden characters in form of "---"
    string secretWord(answerWord.length(), '-');

    return secretWord;
}

char getInputCharacter() {
    char ch;
    cin >> ch;
    return tolower(ch);
}

/***
    Args:
        secretWord (string): secret word in hidden form
        ch (char): a charater
        word (string): the answer word
    Returns:
        void
***/
void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    // TODO: Update the secret word if the character ch is in the answer word.
    for(int i=0;i<secretWord.length();i++){
        if(ch == word[i]) secretWord[i] = ch;
    }
}

/***
    Args:
        ch (char): a character
        chars (string): an array of characters
    Returns:
        void
***/
void updateEnteredCha
