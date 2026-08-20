#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string sentence;
    int words = 0;
    int characters = 0;
    int vowels = 0;
    int consonants = 0;
    int spaces = 0;

    string longestWord = "";
    string shortestWord = "";

    cout << "====================================\n";
    cout << "           WORD COUNTER\n";
    cout << "====================================\n";

    cout << "\nEnter a sentence: ";
    getline(cin, sentence);

    // Count characters, vowels, consonants and spaces
    for (int i = 0; i < sentence.length(); i++)
    {
        char ch = sentence[i];

        if (isalpha(ch))
        {
            characters++;

            ch = tolower(ch);

            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
        else if (ch == ' ')
        {
            spaces++;
        }
    }

    // Count words
    if (sentence.length() > 0)
    {
        words = 1;

        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == ' ')
            {
                words++;
            }
        }
    }

    // Find longest and shortest word
    string currentWord = "";

    for (int i = 0; i <= sentence.length(); i++)
    {
        if (i < sentence.length() && sentence[i] != ' ')
        {
            currentWord += sentence[i];
        }
        else
        {
            if (currentWord.length() > 0)
            {
                if (longestWord == "" ||
                    currentWord.length() > longestWord.length())
                {
                    longestWord = currentWord;
                }

                if (shortestWord == "" ||
                    currentWord.length() < shortestWord.length())
                {
                    shortestWord = currentWord;
                }

                currentWord = "";
            }
        }
    }

    // Display result
    cout << "\n========== TEXT ANALYSIS ==========\n";

    cout << "\nSentence          : " << sentence;
    cout << "\nTotal Words       : " << words;
    cout << "\nTotal Characters  : " << characters;
    cout << "\nVowels            : " << vowels;
    cout << "\nConsonants        : " << consonants;
    cout << "\nSpaces            : " << spaces;
    cout << "\nLongest Word      : " << longestWord;
    cout << "\nShortest Word     : " << shortestWord;

    cout << "\n\n====================================\n";

    return 0;
}