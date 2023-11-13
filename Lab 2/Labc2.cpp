#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isValidIdentifier(const string& word)
{
    if (!isalpha(word[0]) && word[0] != '_')
    {
        return false;
    }
    for (char c : word)
    {
        if (!isalnum(c) && c != '_')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string filename = "SourceFile.txt";
    ifstream file(filename);

    string validVariables, invalidVariables;
    string word;

    while (file >> word)
    {
        if (isValidIdentifier(word))
        {
            if (!validVariables.empty())
            {
                validVariables += "  ";
            }
            validVariables += word;
        }
        else
        {
            if (!invalidVariables.empty())
            {
                invalidVariables += "  ";
            }
            invalidVariables += word;
        }
    }

    cout << "Valid variables   : " << validVariables << "\n"<<endl;
    cout << "Invalid variables : " << invalidVariables << endl;

    return 0;
}
