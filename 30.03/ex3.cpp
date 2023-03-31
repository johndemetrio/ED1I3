#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

string transformaNome(string nome) {
    vector<string> partes;
    istringstream iss(nome);
    string parte;

    while (iss >> parte) {
        partes.push_back(parte);
    }
    string sobrenome = partes.back();
    partes.pop_back();
    ostringstream oss;
    oss << sobrenome << ", ";
    for (size_t i = 0; i < partes.size(); i++) {
        oss << partes[i];
        if (i < partes.size() - 1) {
            oss << " ";
        }
    }
    return oss.str();
}

int main() {
    ifstream arquivo("nomes.txt");
    string nome;
    while (getline(arquivo, nome)) {
        string nomeTransformado = transformaNome(nome);
        cout << nomeTransformado << endl;
    }
    return 0;
}
