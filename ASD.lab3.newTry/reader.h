#pragma once
#include <fstream>
#include <string>
using namespace std;


string read()
{
    string text = "";
    string newText;
    char symbol;
    ifstream file("data.txt");

    while (!file.eof()) {
        file.get(symbol);

        text += symbol;
    }
    file.close();
    newText = text.substr(0, text.length() - 1);
    return newText;
}
