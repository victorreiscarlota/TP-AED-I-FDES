#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale.h>

using namespace std;

class Cliente {
public:
    string codigo;
    string nome;

    Cliente(const string& codigo = "", const string& nome = "")
        : codigo(codigo), nome(nome) {}
};

class Fornecedor {
public:
    string codigo;
    string nome;

    Fornecedor(const string& codigo = "", const string& nome = "")
        : codigo(codigo), nome(nome) {}
};

class Festa {
public:
    string codigo;
    int quantidadeConvidados;
    string data;
    Cliente cliente;
    Fornecedor fornecedor;

    Festa(const string& codigo = "", int quantidadeConvidados = 0, const string& data = "",
          const Cliente& cliente = Cliente(), const Fornecedor& fornecedor = Fornecedor())
        : codigo(codigo), quantidadeConvidados(quantidadeConvidados), data(data),
          cliente(cliente), fornecedor(fornecedor) {}
};

class Contrato {
public:
    string numero;
    double valorTotal;
    double desconto;
    double valorFinal;
    Festa festa;

    Contrato(const string& numero = "", double valorTotal = 0.0, double desconto = 0.0,
             double valorFinal = 0.0, const Festa& festa = Festa())
        : numero(numero), valorTotal(valorTotal), desconto(desconto),
          valorFinal(valorFinal), festa(festa) {}
};

vector<Cliente> clientes;
vector<Fornecedor> fornecedores;
vector<Festa> festas;
vector<Contrato> contratos;

void cadastrarCliente() {
    Cliente cliente("", "");
    cout << "Código do cliente: ";
    cin >> cliente.codigo;

    for (const auto& c : clientes) {
        if (c.codigo == cliente.codigo) {
            cout << "Cliente já cadastrado." << endl;
            return;
        }
    }

    cout << "Nome: ";
    cin.ignore();
    getline(cin, cliente.nome);

    clientes.push_back(cliente);
}

void cadastrarFornecedor() {
    Fornecedor fornecedor("", "");
    cout << "Código do fornecedor: ";
    cin >> fornecedor.codigo;

    for (const auto& f : fornecedores) {
        if (f.codigo == fornecedor.codigo) {
            cout << "Fornecedor já cadastrado." << endl;
            return;
        }
    }

    cout << "Nome do buffet: ";
    cin.ignore();
    getline(cin, fornecedor.nome);

    fornecedores.push_back(fornecedor);
}

void cadastrarFesta() {
    Festa festa("", 0, "", Cliente("", ""), Fornecedor("", ""));
    cout << "Código da festa: ";
    cin >> festa.codigo;

    for (const auto& f : festas) {
        if (f.codigo == festa.codigo) {
            cout << "Festa já cadastrada." << endl;
            return;
        }
    }

    cout << "Quantidade de convidados: ";
    cin >> festa.quantidadeConvidados;

    cout << "Data da festa (dd/mm/aaaa): ";
    cin.ignore();
    getline(cin, festa.data);

    cadastrarCliente();
    cout << "Código do cliente: ";
    cin >> festa.cliente.codigo;

    for (const auto& c : clientes) {
        if (c.codigo == festa.cliente.codigo) {
            festa.cliente.nome = c.nome;
            break;
        }
    }

    cadastrarFornecedor();
    cout << "Código do fornecedor: ";
    cin >> festa.fornecedor.codigo;

    for (const auto& f : fornecedores) {
        if (f.codigo == festa.fornecedor.codigo) {
            festa.fornecedor.nome = f.nome;
            break;
        }
    }

    festas.push_back(festa);
}

void cadastrarContrato() {
    Contrato contrato("", 0.0, 0.0, 0.0, Festa("", 0, "", Cliente("", ""), Fornecedor("", "")));
    cout << "Número do contrato: ";
    cin >> contrato.numero;

    for (const auto& c : contratos) {
        if (c.numero == contrato.numero) {
            cout << "Contrato já cadastrado." << endl;
            return;
        }
    }

    cadastrarFesta();
    cout << "Código da festa: ";
    cin >> contrato.festa.codigo;

    for (const auto& f : festas) {
        if (f.codigo == contrato.festa.codigo) {
            contrato.festa = f;
            break;
        }
    }

    cout << "Valor total do contrato: ";
    cin >> contrato.valorTotal;

    cout << "Desconto: ";
    cin >> contrato.desconto;

    contrato.valorFinal = contrato.valorTotal - contrato.desconto;

    contratos.push_back(contrato);
}

void listarClientes() {
    cout << "---- Clientes cadastrados ----" << endl;
    for (const auto& cliente : clientes) {
        cout << "Código: " << cliente.codigo << endl;
        cout << "Nome: " << cliente.nome << endl;
        cout << "-------------------------------" << endl;
    }
}

void listarFornecedores() {
    cout << "---- Fornecedores cadastrados ----" << endl;
    for (const auto& fornecedor : fornecedores) {
        cout << "Código: " << fornecedor.codigo << endl;
        cout << "Nome: " << fornecedor.nome << endl;
        cout << "---------------------------------" << endl;
    }
}

void listarFestas() {
    cout << "---- Festas cadastradas ----" << endl;
    for (const auto& festa : festas) {
        cout << "Código: " << festa.codigo << endl;
        cout << "Quantidade de convidados: " << festa.quantidadeConvidados << endl;
        cout << "Data: " << festa.data << endl;
        cout << "Cliente: " << festa.cliente.nome << endl;
        cout << "Fornecedor: " << festa.fornecedor.nome << endl;
        cout << "-----------------------------" << endl;
    }
}

void listarContratos() {
    cout << "---- Contratos cadastrados ----" << endl;
    for (const auto& contrato : contratos) {
        cout << "Número: " << contrato.numero << endl;
        cout << "Valor total: " << contrato.valorTotal << endl;
        cout << "Desconto: " << contrato.desconto << endl;
        cout << "Valor final: " << contrato.valorFinal << endl;
        cout << "Festa: " << contrato.festa.codigo << endl;
        cout << "------------------------------" << endl;
    }
}

int main() {
    int opcao;
    setlocale(LC_ALL, "Portuguese_Brazil");

    do {
        cout << "---------- MENU ----------" << endl;
        cout << "1. Cadastrar cliente" << endl;
        cout << "2. Cadastrar fornecedor" << endl;
        cout << "3. Cadastrar festa" << endl;
        cout << "4. Cadastrar contrato" << endl;
        cout << "5. Listar clientes" << endl;
        cout << "6. Listar fornecedores" << endl;
        cout << "7. Listar festas" << endl;
        cout << "8. Listar contratos" << endl;
        cout << "9. Sair" << endl;
        cout << "--------------------------" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                cadastrarFornecedor();
                break;
            case 3:
                cadastrarFesta();
                break;
            case 4:
                cadastrarContrato();
                break;
            case 5:
                listarClientes();
                break;
            case 6:
                listarFornecedores();
                break;
            case 7:
                listarFestas();
                break;
            case 8:
                listarContratos();
                break;
            case 9:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }

        cout << endl;
    } while (opcao != 9);

    return 0;
}
