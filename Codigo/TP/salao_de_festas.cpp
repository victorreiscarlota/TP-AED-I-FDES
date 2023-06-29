#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale.h>

using namespace std;

struct Cliente {
    string codigo;
    string nome;
    string endereco;
    string telefone;
    string dataNascimento;
};

struct Fornecedor {
    string codigo;
    string nome;
    string telefone;
};

struct Festa {
    string codigo;
    int quantidadeConvidados;
    string data;
    string diaSemana;
    string horarioInicio;
    string horarioTermino;
    string tema;
    string codigoCliente;
    string codigoFornecedor;
};

struct Contrato {
    string numero;
    double valorTotal;
    double desconto;
    double valorFinal;
    string formaPagamento;
    string status;
    string codigoFesta;
};

vector<Cliente> clientes;
vector<Fornecedor> fornecedores;
vector<Festa> festas;
vector<Contrato> contratos;

void salvarClientes() {
    ofstream arquivo("clientes.txt");
    if (arquivo.is_open()) {
        for (const auto& cliente : clientes) {
            arquivo << cliente.codigo << "," << cliente.nome << "," << cliente.endereco << ","
                    << cliente.telefone << "," << cliente.dataNascimento << endl;
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo de clientes." << endl;
    }
}

void carregarClientes() {
    ifstream arquivo("clientes.txt");
    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            Cliente cliente;
            getline(ss, cliente.codigo, ',');
            getline(ss, cliente.nome, ',');
            getline(ss, cliente.endereco, ',');
            getline(ss, cliente.telefone, ',');
            getline(ss, cliente.dataNascimento, ',');
            clientes.push_back(cliente);
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo de clientes." << endl;
    }
}

void salvarFornecedores() {
    ofstream arquivo("fornecedores.txt");
    if (arquivo.is_open()) {
        for (const auto& fornecedor : fornecedores) {
            arquivo << fornecedor.codigo << "," << fornecedor.nome << "," << fornecedor.telefone << endl;
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo de fornecedores." << endl;
    }
}

void carregarFornecedores() {
    ifstream arquivo("fornecedores.txt");
    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            Fornecedor fornecedor;
            getline(ss, fornecedor.codigo, ',');
            getline(ss, fornecedor.nome, ',');
            getline(ss, fornecedor.telefone, ',');
            fornecedores.push_back(fornecedor);
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo de fornecedores." << endl;
    }
}

void salvarFestas() {
    ofstream arquivo("festas.txt");
    if (arquivo.is_open()) {
        for (const auto& festa : festas) {
            arquivo << festa.codigo << "," << festa.quantidadeConvidados << "," << festa.data << ","
                    << festa.diaSemana << "," << festa.horarioInicio << "," << festa.horarioTermino << ","
                    << festa.tema << "," << festa.codigoCliente << "," << festa.codigoFornecedor << endl;
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo de festas." << endl;
    }
}

void carregarFestas() {
    ifstream arquivo("festas.txt");
    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            Festa festa;
            getline(ss, festa.codigo, ',');
            ss >> festa.quantidadeConvidados;
            getline(ss, festa.data, ',');
            getline(ss, festa.diaSemana, ',');
            getline(ss, festa.horarioInicio, ',');
            getline(ss, festa.horarioTermino, ',');
            getline(ss, festa.tema, ',');
            getline(ss, festa.codigoCliente, ',');
            getline(ss, festa.codigoFornecedor, ',');
            festas.push_back(festa);
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo de festas." << endl;
    }
}

void salvarContratos() {
    ofstream arquivo("contratos.txt");
    if (arquivo.is_open()) {
        for (const auto& contrato : contratos) {
            arquivo << contrato.numero << "," << contrato.valorTotal << "," << contrato.desconto << ","
                    << contrato.valorFinal << "," << contrato.formaPagamento << "," << contrato.status << ","
                    << contrato.codigoFesta << endl;
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo de contratos." << endl;
    }
}

void carregarContratos() {
    ifstream arquivo("contratos.txt");
    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            Contrato contrato;
            getline(ss, contrato.numero, ',');
            ss >> contrato.valorTotal;
            ss.ignore();
            ss >> contrato.desconto;
            ss.ignore();
            ss >> contrato.valorFinal;
            getline(ss, contrato.formaPagamento, ',');
            getline(ss, contrato.status, ',');
            getline(ss, contrato.codigoFesta, ',');
            contratos.push_back(contrato);
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo de contratos." << endl;
    }
}

void adicionarCliente() {
    Cliente cliente;
    cout << "Digite o código do cliente: ";
    cin >> cliente.codigo;
    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, cliente.nome);
    cout << "Digite o endereço do cliente: ";
    getline(cin, cliente.endereco);
    cout << "Digite o telefone do cliente: ";
    getline(cin, cliente.telefone);
    cout << "Digite a data de nascimento do cliente: ";
    getline(cin, cliente.dataNascimento);
    clientes.push_back(cliente);
    salvarClientes();
    cout << "Cliente adicionado com sucesso!" << endl;
}

void adicionarFornecedor() {
    Fornecedor fornecedor;
    cout << "Digite o código do fornecedor: ";
    cin >> fornecedor.codigo;
    cout << "Digite o nome do fornecedor: ";
    cin.ignore();
    getline(cin, fornecedor.nome);
    cout << "Digite o telefone do fornecedor: ";
    getline(cin, fornecedor.telefone);
    fornecedores.push_back(fornecedor);
    salvarFornecedores();
    cout << "Fornecedor adicionado com sucesso!" << endl;
}

void adicionarFesta() {
    Festa festa;
    cout << "Digite o código da festa: ";
    cin >> festa.codigo;
    cout << "Digite a quantidade de convidados: ";
    cin >> festa.quantidadeConvidados;
    cout << "Digite a data da festa: ";
    cin.ignore();
    getline(cin, festa.data);
    cout << "Digite o dia da semana: ";
    getline(cin, festa.diaSemana);
    cout << "Digite o horário de início: ";
    getline(cin, festa.horarioInicio);
    cout << "Digite o horário de término: ";
    getline(cin, festa.horarioTermino);
    cout << "Digite o tema da festa: ";
    getline(cin, festa.tema);
    cout << "Digite o código do cliente: ";
    getline(cin, festa.codigoCliente);
    cout << "Digite o código do fornecedor: ";
    getline(cin, festa.codigoFornecedor);
    festas.push_back(festa);
    salvarFestas();
    cout << "Festa adicionada com sucesso!" << endl;
}

void adicionarContrato() {
    Contrato contrato;
    cout << "Digite o número do contrato: ";
    cin >> contrato.numero;
    cout << "Digite o valor total: ";
    cin >> contrato.valorTotal;
    cout << "Digite o desconto: ";
    cin >> contrato.desconto;
    cout << "Digite o valor final: ";
    cin >> contrato.valorFinal;
    cout << "Digite a forma de pagamento: ";
    cin.ignore();
    getline(cin, contrato.formaPagamento);
    cout << "Digite o status: ";
    getline(cin, contrato.status);
    cout << "Digite o código da festa: ";
    getline(cin, contrato.codigoFesta);
    contratos.push_back(contrato);
    salvarContratos();
    cout << "Contrato adicionado com sucesso!" << endl;
}

int main() {
    carregarClientes();
    carregarFornecedores();
    carregarFestas();
    carregarContratos();
    setlocale(LC_ALL,"Portuguese_Brazil");

    int opcao;
    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Adicionar cliente" << endl;
        cout << "2. Adicionar fornecedor" << endl;
        cout << "3. Adicionar festa" << endl;
        cout << "4. Adicionar contrato" << endl;
        cout << "5. Sair" << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarCliente();
                break;
            case 2:
                adicionarFornecedor();
                break;
            case 3:
                adicionarFesta();
                break;
            case 4:
                adicionarContrato();
                break;
            case 5:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }
    } while (opcao != 5);

    return 0;
}