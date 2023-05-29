#include "inserirmatricula.h"

InserirMatricula::InserirMatricula()
{

}

Pedro::Matricula InserirMatricula::operator ()(QString matriculaText)
{
    QString saida = "";
    int i = 0;
    for (int i = 0; matriculaText[i] != '.'; i++)
    {
        saida += matriculaText[i];
    }
    Pedro::Matricula matricula;
    matricula.setAno(saida.toInt());
    saida = "";
    i++;
    while (matriculaText[i] != '.')
    {
        saida += matriculaText[i];
        i++;
    }
    matricula.setSemestre(saida.toInt());
    saida = "";
    while(matriculaText[i] != '.')
    {
        saida += matriculaText[i];
        i++;
    }
    matricula.setNCurso(saida.toInt());
    saida = "";
    i++;
    for (int j = 0; j < 3; j++)
    {
        saida += matriculaText[i];
        i++;
    }
    matricula.setNumero(saida.toInt());
    i++;
    saida = matriculaText[i];
    matricula.setNumeroVerificador(saida.toInt());
    return matricula;
}
