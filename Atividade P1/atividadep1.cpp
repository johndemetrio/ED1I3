#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;
public:
    Data(int dia, int mes, int ano) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;        
    }
    Data() {
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;        
    }
    void setDia(int dia) {
        this->dia = dia;
    }
    void setMes(int mes) {
        this->mes = mes;
    }
    void setAno(int ano) {
        this->ano = ano;
    }
    int getDia() {
        return this->dia;
    }
    int getMes() {
        return this->mes;
    }
    int getAno() {
        return this->ano;
    }
    string getData()
    {
        return to_string(this->dia) + "/" +
               to_string(this->mes) + "/" +
               to_string(this->ano);       
    }       
};

class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato(string email, string nome, string telefone, Data dtnasc){
        this->email = email;
        this->nome = nome;
        this->telefone = telefone;
        this->dtnasc = dtnasc;
    }
    Contato(){
        this->email = "";
        this->nome = "";
        this->telefone = "";
        this->dtnasc = Data();
    }
    void setEmail(string email){
        this->email = email;
    }
    void setNome(string nome){
        this->nome = nome;
    }
    void setTelefone(string telefone){
        this->telefone = telefone;
    }
    void setDtnasc(Data dtnasc){
        this->dtnasc = dtnasc;
    }
    string getEmail(){
        return this->email;
    }
    string getNome(){
        return this->nome;
    }
    string getTelefone(){
        return this->telefone;
    }
    Data getDtnasc() {
        return this->dtnasc;
    }
    int idade() {
        Data hoje(13, 4, 2023);
        int anos = hoje.getAno() - dtnasc.getAno();
        int meses = hoje.getMes() - dtnasc.getMes();
        int dias = hoje.getDia() - dtnasc.getDia();
        if (meses < 0 || (meses == 0 && dias < 0)) {
            anos--;
        }
        return anos;
    }
};


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
    int n = 10; 
    Contato contatos[n]; 
    
    for(int i = 0; i < n; i++){
        string email, nome, telefone;
        int dia, mes, ano;
        
        cout << "Entre com os dados do contato " << i+1 << ":" << endl;
        cout << "Email: ";
        cin >> email;
        cout << "Nome: ";
        cin >> nome;
        cout << "Telefone: ";
        cin >> telefone;
        cout << "Digite a data de nascimento: " << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << endl;
        cout <<"Mês: ";
        cin >> mes;
        cout << endl;
        cout <<"Ano: ";
        cin >> ano;
        cout << endl;
        Data dtnasc(dia, mes, ano);
        contatos[i] = Contato(email, nome, telefone, dtnasc);
        system("clear");
    }
    

    int somaIdades = 0;
    int maiorIdade = 0;
    Contato contatoMaisVelho;
    int idadeMaisVelho = -1;
    
    cout << endl << "Lista de contatos:" << endl;
    for(int i = 0; i < n; i++){
        int idade = 2023 - contatos[i].getDtnasc().getAno();
        somaIdades += idade;
        
        cout << "Contato " << i+1 << ":" << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Data de Nascimento: " << contatos[i].getDtnasc().getData() << endl;
        cout << "Idade: " << idade << " anos" << endl << endl;
        
        if(idade >= 18){
            maiorIdade++;
        }
        
        if(idade > idadeMaisVelho){
            idadeMaisVelho = idade;
            contatoMaisVelho = contatos[i];
        }
    }
    
    float mediaGeral = somaIdades / (float)n;
    cout << "Média geral das idades: " << mediaGeral << endl << endl;
    
    cout << "Contatos com idade acima da média geral:" << endl;
    for(int i = 0; i < n; i++){
        int idade = 2023 - contatos[i].getDtnasc().getAno();
        if(idade > mediaGeral){
            cout << contatos[i].getNome() << endl;
        }
    }
    cout << endl << endl;
    cout << "A quantidade de contatos maiores de idade é de: " << maiorIdade << endl << endl;
    
    cout << "Contato mais velho:" << endl;
    cout << "Nome: " << contatoMaisVelho.getNome() << endl;
    cout << "Email: " << contatoMaisVelho.getEmail() << endl;
    cout << "Telefone: " << contatoMaisVelho.getTelefone() << endl;
    cout << "Data de Nascimento: " << contatoMaisVelho.getDtnasc().getData() << endl;
    cout << "Idade: " << idadeMaisVelho << " anos" << endl << endl;
    return 0;
}