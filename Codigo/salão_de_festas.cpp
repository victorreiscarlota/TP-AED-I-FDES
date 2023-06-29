#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
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
            ss.ignore(1, ',');
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
            arquivo << contrato.numero << "," << fixed << setprecision(2) << contrato.valorTotal << ","
                    << contrato.desconto << "," << contrato.valorFinal << ","
                    << contrato.formaPagamento << "," << contrato.status << ","
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
            ss.ignore(1, ',');
            ss >> contrato.desconto;
            ss.ignore(1, ',');
            ss >> contrato.valorFinal;
            ss.ignore(1, ',');
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
    cout << "Código: ";
    cin >> cliente.codigo;
    cin.ignore();
    cout << "Nome: ";
    getline(cin, cliente.nome);
    cout << "Endereço: ";
    getline(cin, cliente.endereco);
    cout << "Telefone: ";
    getline(cin, cliente.telefone);
    cout << "Data de Nascimento: ";
    getline(cin, cliente.dataNascimento);
    clientes.push_back(cliente);
    salvarClientes();
    cout << "Cliente adicionado com sucesso!" << endl;
}

void listarClientes() {
    for (const auto& cliente : clientes) {
        cout << "Código: " << cliente.codigo << endl;
        cout << "Nome: " << cliente.nome << endl;
        cout << "Endereço: " << cliente.endereco << endl;
        cout << "Telefone: " << cliente.telefone << endl;
        cout << "Data de Nascimento: " << cliente.dataNascimento << endl;
        cout << "------------------------------------" << endl;
    }
}

void adicionarFornecedor() {
    Fornecedor fornecedor;
    cout << "Código: ";
    cin >> fornecedor.codigo;
    cin.ignore();
    cout << "Nome: ";
    getline(cin, fornecedor.nome);
    cout << "Telefone: ";
    getline(cin, fornecedor.telefone);
    fornecedores.push_back(fornecedor);
    salvarFornecedores();
    cout << "Fornecedor adicionado com sucesso!" << endl;
}

void listarFornecedores() {
    for (const auto& fornecedor : fornecedores) {
        cout << "Código: " << fornecedor.codigo << endl;
        cout << "Nome: " << fornecedor.nome << endl;
        cout << "Telefone: " << fornecedor.telefone << endl;
        cout << "------------------------------------" << endl;
    }
}

string calcularHorarioTermino(const string& horarioInicio, int duracao) {
    int horaInicio = stoi(horarioInicio.substr(0, 2));
    int minutoInicio = stoi(horarioInicio.substr(3, 2));

    int horaTermino = horaInicio + duracao / 60;
    int minutoTermino = minutoInicio + duracao % 60;

    if (minutoTermino >= 60) {
        horaTermino += minutoTermino / 60;
        minutoTermino %= 60;
    }

    stringstream ss;
    ss << setw(2) << setfill('0') << horaTermino << ":" << setw(2) << setfill('0') << minutoTermino;
    return ss.str();
}

void adicionarFesta() {
    Festa festa;
    cout << "Código: ";
    cin >> festa.codigo;
    cin.ignore();
    cout << "Quantidade de Convidados: ";
    cin >> festa.quantidadeConvidados;
    cin.ignore();
    cout << "Data: ";
    getline(cin, festa.data);
    cout << "Dia da Semana: ";
    getline(cin, festa.diaSemana);
    cout << "Horário de Início (HH:MM): ";
    getline(cin, festa.horarioInicio);
    cout << "Duração (em minutos): ";
    int duracao;
    cin >> duracao;
    festa.horarioTermino = calcularHorarioTermino(festa.horarioInicio, duracao);
    cin.ignore();
    cout << "Tema: ";
    getline(cin, festa.tema);
    cout << "Código do Cliente: ";
    getline(cin, festa.codigoCliente);
    cout << "Código do Fornecedor: ";
    getline(cin, festa.codigoFornecedor);
    festas.push_back(festa);
    salvarFestas();
    cout << "Festa adicionada com sucesso!" << endl;
}

void listarFestas() {
    for (const auto& festa : festas) {
        cout << "Código: " << festa.codigo << endl;
        cout << "Quantidade de Convidados: " << festa.quantidadeConvidados << endl;
        cout << "Data: " << festa.data << endl;
        cout << "Dia da Semana: " << festa.diaSemana << endl;
        cout << "Horário de Início: " << festa.horarioInicio << endl;
        cout << "Horário de Término: " << festa.horarioTermino << endl;
        cout << "Tema: " << festa.tema << endl;
        cout << "Código do Cliente: " << festa.codigoCliente << endl;
        cout << "Código do Fornecedor: " << festa.codigoFornecedor << endl;
        cout << "------------------------------------" << endl;
    }
}

void adicionarContrato() {
    Contrato contrato;
    cout << "Número: ";
    cin >> contrato.numero;
    cin.ignore();
    cout << "Valor Total: ";
    cin >> contrato.valorTotal;
    cin.ignore();
    cout << "Desconto: ";
    cin >> contrato.desconto;
    cin.ignore();
    contrato.valorFinal = contrato.valorTotal - contrato.desconto;
    cout << "Forma de Pagamento: ";
    getline(cin, contrato.formaPagamento);
    cout << "Status: ";
    getline(cin, contrato.status);
    cout << "Código da Festa: ";
    getline(cin, contrato.codigoFesta);
    contratos.push_back(contrato);
    salvarContratos();
    cout << "Contrato adicionado com sucesso!" << endl;
}

void listarContratos() {
    for (const auto& contrato : contratos) {
        cout << "Número: " << contrato.numero << endl;
        cout << "Valor Total: R$ " << fixed << setprecision(2) << contrato.valorTotal << endl;
        cout << "Desconto: R$ " << fixed << setprecision(2) << contrato.desconto << endl;
        cout << "Valor Final: R$ " << fixed << setprecision(2) << contrato.valorFinal << endl;
        cout << "Forma de Pagamento: " << contrato.formaPagamento << endl;
        cout << "Status: " << contrato.status << endl;
        cout << "Código da Festa: " << contrato.codigoFesta << endl;
        cout << "------------------------------------" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    carregarClientes();
    carregarFornecedores();
    carregarFestas();
    carregarContratos();

    int opcao;
    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Adicionar Cliente" << endl;
        cout << "2. Listar Clientes" << endl;
        cout << "3. Adicionar Fornecedor" << endl;
        cout << "4. Listar Fornecedores" << endl;
        cout << "5. Adicionar Festa" << endl;
        cout << "6. Listar Festas" << endl;
        cout << "7. Adicionar Contrato" << endl;
        cout << "8. Listar Contratos" << endl;
        cout << "9. Sair" << endl;
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                adicionarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                adicionarFornecedor();
                break;
            case 4:
                listarFornecedores();
                break;
            case 5:
                adicionarFesta();
                break;
            case 6:
                listarFestas();
                break;
            case 7:
                adicionarContrato();
                break;
            case 8:
                listarContratos();
                break;
            case 9:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }
    } while (opcao != 9);

    return 0;
}
