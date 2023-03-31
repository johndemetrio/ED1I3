#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string palindromo;
    cout << "Digite uma mensagem para saber se é um palindromo ou não: ";
    cin >> palindromo;
    if(palindromo == string(palindromo.rbegin(), palindromo.rend())){
        cout << palindromo << " - é um palindromo";
    }else{
        cout << palindromo << " - não é um palindromo";
    }
}