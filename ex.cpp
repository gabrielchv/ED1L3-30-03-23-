#include <iostream>
#include <string> 

using namespace std;

struct data {
	int dia;
	int mes;
	int ano;
};

class Contato {
    private:
        string email;
        string nome;
        string telefone;
        data dtnasc;
    public:
        void setEmail(string email) {
            this->email = email;
        }
        void setNome(string nome) {
            this->nome = nome;
        }
        void setTelefone(string telefone) {
            this->telefone = telefone;
        }
        void setDtnasc(data dtnasc) {
            this->dtnasc = dtnasc;
        }
        
        
        string getEmail() {
            return this->email;
        }
        string getNome() {
            return this->nome;
        }
        string getTelefone() {
            return this->telefone;
        }
        string getDtnasc() {
            string dataFormatada;
            dataFormatada += to_string(this->dtnasc.dia) + "/";
            dataFormatada += to_string(this->dtnasc.mes) + "/";
            dataFormatada += to_string(this->dtnasc.ano);
            
            return dataFormatada;
        }
        
        int idade () {
            return (2023 - this->dtnasc.ano);
        }
};

int main() {
    Contato arrContatos[5];
    int numClasses = 0;
    bool exitLoop = false;
    while (numClasses < 5 && !exitLoop) {
        string selectedOption;
        cout << endl << "Você tem " << to_string(numClasses) << (numClasses == 1 ? " contato" : " contatos") << endl;
        cout << "1 - Criar mais um contato" << endl;
        cout << "2 - Ler um contato" << endl;
        cout << "3 - Sair" << endl;
        cout << "Selecione uma opção: " << endl;
        cin >> selectedOption;
        
        if (selectedOption == "1") {
            string nome;
            string email;
            string telefone;
            string dia;
            string mes;
            string ano;
            struct data nascimento;
            
            cout << "Digite o seu nome: ";
            cin >> nome;
            cout << "Digite o seu email: ";
            cin >> email;
            cout << "Digite o seu telefone: ";
            cin >> telefone;
            cout << "Digite o seu dia de nascimento: ";
            cin >> dia;
            cout << "Digite o seu mês de nascimento: ";
            cin >> mes;
            cout << "Digite o seu ano de nascimento: ";
            cin >> ano;
            
            nascimento.dia = stoi(dia);
            nascimento.mes = stoi(mes);
            nascimento.ano = stoi(ano);
            
            arrContatos[numClasses].setNome(nome);
            arrContatos[numClasses].setEmail(email);
            arrContatos[numClasses].setTelefone(telefone);
            arrContatos[numClasses].setDtnasc(nascimento);
            
            numClasses++;
        }
        
        if (selectedOption == "2") {
            string nmrContato;
            cout << "Digite o número do contato que você deseja pegar os dados sobre: " << endl;
            cin >> nmrContato;
            cout << "O nome do contato é: " << arrContatos[(stoi(nmrContato) - 1)].getNome() << endl;
            cout << "O email do contato é: " << arrContatos[(stoi(nmrContato) - 1)].getEmail() << endl;
            cout << "O telefone do contato é: " << arrContatos[(stoi(nmrContato) - 1)].getTelefone() << endl;
            cout << "A idade do contato é: " << arrContatos[(stoi(nmrContato) - 1)].idade() << endl;
        }
        
        if (selectedOption == "3") {
            exitLoop = true;
        }
    }
    
    cout << "Obrigado por usar a nossa agenda eletrônica :D" << endl;
    cout << "Você criou " << to_string(numClasses) << (numClasses == 1 ? " contato" : " contatos") << endl;

    return 0;
}
