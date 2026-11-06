#include "GerenciadorEstudos.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

void GerenciadorEstudos::adicionarMateria(const std::string& nome, int ch, int diff) {
    materias.emplace_back(nome, ch, diff);
    std::cout << "\n[+] Matéria \"" << nome << "\" cadastrada com sucesso!\n";
}

void GerenciadorEstudos::listarMaterias() const {
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

void GerenciadorEstudos::gerarPrioridadeEstudos() const {
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

// ... mantenha os métodos anteriores e adicione este no final:

void GerenciadorEstudos::registrarHorasMateria(const std::string& nome, int horas) {
    for (auto& m : materias) {
        if (m.getNome() == nome) {
            m.registrarHoras(horas);
            std::cout << "\n[+] Foram registradas " << horas << "h de estudo em \"" << nome << "\".\n";
            return;
        }
    }
    std::cout << "\n[-] Matéria \"" << nome << "\" não encontrada.\n";
}
