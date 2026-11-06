#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

class Materia {
private:
    std::string nome;
    int cargaHorariaTotal; // em horas
    int horasEstudadas;
    int pesoDificuldade;   // Ex: 1 (Fácil) a 5 (Muito Difícil)

public:
    Materia(std::string n, int ch, int diff) 
        : nome(n), cargaHorariaTotal(ch), horasEstudadas(0), pesoDificuldade(diff) {}

    std::string getNome() const { return nome; }
    int getCargaHorariaTotal() const { return cargaHorariaTotal; }
    int getHorasEstudadas() const { return horasEstudadas; }
    int getPesoDificuldade() const { return pesoDificuldade; }

    void registrarHoras(int horas) {
        horasEstudadas += horas;
        if (horasEstudadas > cargaHorariaTotal) {
            horasEstudadas = cargaHorariaTotal;
        }
    }

    double getProgressoPorcentagem() const {
        if (cargaHorariaTotal == 0) return 100.0;
        return (static_cast<double>(horasEstudadas) / cargaHorariaTotal) * 100.0;
    }

    // Algoritmo simples de cálculo de prioridade
    double calcularPrioridade() const {
        int horasRestantes = cargaHorariaTotal - horasEstudadas;
        return horasRestantes * pesoDificuldade;
    }
};

class GerenciadorEstudos {
private:
    std::vector<Materia> materias;

public:
    void adicionarMateria(const std::string& nome, int ch, int diff) {
        materias.emplace_back(nome, ch, diff);
        std::cout << "\n[+] Matéria \"" << nome << "\" cadastrada com sucesso!\n";
    }

    void listarMaterias() const {
        if (materias.empty()) {
            std::cout << "\nNenhuma matéria cadastrada.\n";
            return;
        }

        std::cout << "\n=================== MATÉRIAS ===================\n";
        std::cout << std::left << std::setw(20) << "Nome" 
                  << std::setw(12) << "Progresso" 
                  << std::setw(15) << "Dificuldade" << "\n";
        std::cout << "------------------------------------------------\n";

        for (const auto& m : materias) {
            std::cout << std::left << std::setw(20) << m.getNome()
                      << std::fixed << std::setprecision(1) << m.getProgressoPorcentagem() << "%"
                      << std::setw(8) << "" 
                      << std::setw(15) << m.getPesoDificuldade() << "\n";
        }
        std::cout << "================================================\n";
    }

    void gerarPrioridadeEstudos() {
        if (materias.empty()) {
            std::cout << "\nNenhuma matéria para ordenar.\n";
            return;
        }

        auto materiasOrdenadas = materias;
        std::sort(materiasOrdenadas.begin(), materiasOrdenadas.end(), 
            [](const Materia& a, const Materia& b) {
                return a.calcularPrioridade() > b.calcularPrioridade();
            });

        std::cout << "\n=== CRONOGRAMA RECOMENDADO (MAIOR PRIORIDADE PRIMEIRO) ===\n";
        int pos = 1;
        for (const auto& m : materiasOrdenadas) {
            std::cout << pos++ << ". " << m.getNome() 
                      << " | Horas Restantes: " << (m.getCargaHorariaTotal() - m.getHorasEstudadas())
                      << "h | Dificuldade: " << m.getPesoDificuldade() << "\n";
        }
    }
};

int main() {
    GerenciadorEstudos app;
    int opcao = -1;

    while (opcao != 0) {
        std::cout << "\n--- GERENCIADOR DE ESTUDOS ---\n";
        std::cout << "1. Cadastrar Matéria\n";
        std::cout << "2. Listar Matérias\n";
        std::cout << "3. Ver Prioridade de Estudos\n";
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
        }
    }

    std::cout << "\nAplicação encerrada.\n";
    return 0;
}