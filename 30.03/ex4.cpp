#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string formatar_nome(string nome) {
    string sobrenome;
    string resto_nome;
    size_t pos = nome.find_last_of(" ");
    if (pos != string::npos) {
        sobrenome = nome.substr(pos + 1);
        resto_nome = nome.substr(0, pos);
        transform(sobrenome.begin(), sobrenome.end(), sobrenome.begin(), ::toupper);
        return sobrenome + ", " + resto_nome;
    }
    else {
        return nome;
    }
}

int main() {
    string nome_arquivo = "nomes.txt";
    ifstream input(nome_arquivo);

    if (!input) {
        cerr << "Erro ao abrir o arquivo " << nome_arquivo << endl;
        return 1;
    }

    vector<string> nomes;
    string linha;
    while (getline(input, linha)) {
        nomes.push_back(linha);
    }

    input.close();

    for (string nome : nomes) {
        cout << formatar_nome(nome) << endl;
    }

    return 0;
}