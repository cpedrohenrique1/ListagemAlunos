#include "matricula.h"


namespace Pedro {

int Matricula::getSemestre() const
{
    return semestre;
}

void Matricula::setSemestre(int newSemestre)
{
    semestre = newSemestre;
}

int Matricula::getNCurso() const
{
    return nCurso;
}

void Matricula::setNCurso(int newNCurso)
{
    nCurso = newNCurso;
}

int Matricula::getNumero() const
{
    return numero;
}

void Matricula::setNumero(int newNumero)
{
    numero = newNumero;
}

int Matricula::getNumeroVerificador() const
{
    return numeroVerificador;
}

void Matricula::setNumeroVerificador(int newNumeroVerificador)
{
    numeroVerificador = newNumeroVerificador;
}

Matricula Matricula::getMatricula() const
{
    return *this;
}

Matricula::operator QString() const
{
    return QString::number(ano) + "." + QString::number(semestre) + "." + QString::number(nCurso) + "." + QString::number(numero) + QString::number(numeroVerificador);
}

bool Matricula::operator ==(Matricula matricula)
{
    if (this->ano == matricula.getAno() && this->semestre == matricula.getSemestre() && this->nCurso == matricula.getNCurso() && this->numero == matricula.getNumero() && this->numeroVerificador == matricula.getNumeroVerificador())
    {
        return true;
    }
    return false;
}

Matricula::Matricula():
        ano(0)
      , semestre(0)
      , nCurso(0)
      , numero(0)
      , numeroVerificador(0)
{}

Matricula::Matricula(int ano, int semestre, int nCurso, int numero, int numeroVerificador):
        ano(ano)
      , semestre(semestre)
      , nCurso(nCurso)
      , numero(numero)
      , numeroVerificador(numeroVerificador)
{}

int Matricula::getAno() const
{
    return ano;
}

void Matricula::setAno(int newAno)
{
    ano = newAno;
}

}
