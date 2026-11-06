#include "Materia.h"

Materia::Materia(std::string n, int ch, int diff) 
    : nome(n), cargaHorariaTotal(ch), horasEstudadas(0), pesoDificuldade(diff) {}

std::string Materia::getNome() const { return nome; }
int Materia::getCargaHorariaTotal() const { return cargaHorariaTotal; }
int Materia::getHorasEstudadas() const { return horasEstudadas; }
int Materia::getPesoDificuldade() const { return pesoDificuldade; }

void Materia::registrarHoras(int horas) {
    horasEstudadas += horas;
    if (horasEstudadas > cargaHorariaTotal) {
        horasEstudadas = cargaHorariaTotal;
    }
}

double Materia::getProgressoPorcentagem() const {
    if (cargaHorariaTotal == 0) return 100.0;
    return (static_cast<double>(horasEstudadas) / cargaHorariaTotal) * 100.0;
}

double Materia::calcularPrioridade() const {
    int horasRestantes = cargaHorariaTotal - horasEstudadas;
    return horasRestantes * pesoDificuldade;
}
