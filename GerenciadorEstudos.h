#ifndef GERENCIADOR_ESTUDOS_H
#define GERENCIADOR_ESTUDOS_H

#include <vector>
#include <string>
#include "Materia.h"

class GerenciadorEstudos {
private:
    std::vector<Materia> materias;

public:
    void adicionarMateria(const std::string& nome, int ch, int diff);
    void listarMaterias() const;
    void gerarPrioridadeEstudos() const;
    void registrarHorasMateria(const std::string& nome, int horas); // <-- NOVA DECLARAÇÃO
};

#endif // GERENCIADOR_ESTUDOS_H
