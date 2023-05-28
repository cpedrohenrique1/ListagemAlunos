#ifndef MATRICULA_H
#define MATRICULA_H

#include <QString>

namespace Pedro
{

class Matricula
{
private:
    int ano;
    int semestre;
    int nCurso;
    int numero;
    int numeroVerificador;
public:
    Matricula();
    Matricula(int ano, int semestre, int nCurso, int numero, int numeroVerificador);
    int getAno() const;
    void setAno(int newAno);
    int getSemestre() const;
    void setSemestre(int newSemestre);
    int getNCurso() const;
    void setNCurso(int newNCurso);
    int getNumero() const;
    void setNumero(int newNumero);
    int getNumeroVerificador() const;
    void setNumeroVerificador(int newNumeroVerificador);
    Matricula getMatricula() const;
    operator QString() const;
};

}

#endif // MATRICULA_H
