#include <iostream>
#include "GerenciadorEstudos.h"

int main() {
    GerenciadorEstudos app;
    int opcao = -1;

    while (opcao != 0) {
        std::cout << "\n--- GERENCIADOR DE ESTUDOS ---\n";
        std::cout << "1. Cadastrar Matéria\n";
        std::cout << "2. Listar Matérias\n";
        std::cout << "3. Ver Prioridade de Estudos\n";
        std::cout << "4. Registrar Horas Estudadas\n"; // <-- NOVA OPÇÃO
        std::cout << "0. Sair\n";
        std::cout << "Opção: ";
        std::cin >> opcao;

        if (opcao == 1) {
            std::string nome;
            int ch, diff;
            std::cout << "Nome da matéria: ";
            std::cin.ignore();
            std::getline(std::cin, nome);
            std::cout << "Carga horária total (horas): ";
            std::cin >> ch;
            std::cout << "Dificuldade (1 a 5): ";
            std::cin >> diff;
            app.adicionarMateria(nome, ch, diff);
        } else if (opcao == 2) {
            app.listarMaterias();
        } else if (opcao == 3) {
            app.gerarPrioridadeEstudos();
        } else if (opcao == 4) { // <-- NOVA LÓGICA
            std::string nome;
            int horas;
            std::cout << "Digite o nome da matéria: ";
            std::cin.ignore();
            std::getline(std::cin, nome);
            std::cout << "Quantidade de horas estudadas hoje: ";
            std::cin >> horas;
            app.registrarHorasMateria(nome, horas);
        }
    }

    std::cout << "\nAplicação encerrada.\n";
    return 0;
}
