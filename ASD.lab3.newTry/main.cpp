#include <iostream>
#include "Floyd.h"
#include "reader.h"


int main()
{
    string text = read();
    cout << text << endl;
    Floyd airport;
    string str = airport.algorithm("MSC", "KHB", "data.txt");
    cout << str;
}