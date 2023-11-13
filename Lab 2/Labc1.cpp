#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

bool isKeyword(const string &word)
{
    const unordered_set<string> keywords = {"int", "float", "char", "return" , "if", "else", "while", "for"};
    return keywords.find(word) != keywords.end();
}

bool isOperator(const string &word)
{
    const unordered_set<string> operators = {"+", "-", "*", "/", "=", "==", "<", ">", "<=", ">=", "!="};
    return operators.find(word) != operators.end();
}

bool isIdentifier(const string &word)
{
    if (!isalpha(word[0]) && word[0] != '_')
        return false;

    for (char c : word)
        if (!isalnum(c) && c != '_')
            return false;

    return true;
}

bool isConstant(const string &word)
{
    for (char c : word)
        if (!isdigit(c))
            return false;

    return true;
}

bool isOperatorChar(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>';
}

int main()
{
    ifstream file("SourceFile.txt");
    stringstream buffer;
    buffer << file.rdbuf();

    string word;
    string keywords, identifiers, operators, constants;
    string currentWord;

    for (char c : buffer.str())
    {
        if (isalnum(c) || c == '_')
        {
            currentWord += c;
        }
        else
        {
            if (!currentWord.empty())
            {
                if (isKeyword(currentWord))
                {
                    keywords += (keywords.empty() ? "" : ", ") + currentWord;
                }
                else if (isIdentifier(currentWord))
                {
                    identifiers += (identifiers.empty() ? "" : ", ") + currentWord;
                }
                else if (isConstant(currentWord))
                {
                    constants += (constants.empty() ? "" : ", ") + currentWord;
                }
                currentWord.clear();
            }

            if (isOperatorChar(c))
            {
                string op(1, c);
                while (isOperatorChar(buffer.peek()) && op.length() < 3)
                {
                    op += buffer.get();
                }
                if (isOperator(op))
                    operators += (operators.empty() ? "" : ", ") + op;
            }
        }
    }

    cout << "Keywords: " << keywords << endl;
    cout << "Identifiers: " << identifiers << endl;
    cout << "Operators: " << operators << endl;
    cout << "Constants: " << constants << endl;

    file.close();
    return 0;
}
