#ifndef MATERIA_H
#define MATERIA_H

#include <string>

class Materia {
private:
    std::string nome;
    int cargaHorariaTotal;
    int horasEstudadas;
    int pesoDificuldade;

public:
    Materia(std::string n, int ch, int diff);

    std::string getNome() const;
    int getCargaHorariaTotal() const;
    int getHorasEstudadas() const;
    int getPesoDificuldade() const;

    void registrarHoras(int horas);
    double getProgressoPorcentagem() const;
    double calcularPrioridade() const;
};

#endif // MATERIA_H
