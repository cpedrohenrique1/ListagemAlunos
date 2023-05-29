#include "inserirmatricula.h"

InserirMatricula::InserirMatricula()
{

}

Pedro::Matricula InserirMatricula::operator ()(QString matriculaText)
{
    QString entrada = "";
    for (int i = 0; matriculaText[i] != '.' && i < matriculaText.size(); i++)
    {
        entrada += matriculaText[i];
    }
    Pedro::Matricula matricula;
    matricula.setAno(entrada.toInt());
    entrada = matriculaText[5];
    matricula.setSemestre(entrada.toInt());
    entrada = "";
    for (int i = 7; matriculaText[i] != '.' && i < matriculaText.size(); i++)
    {
        entrada += matriculaText[i];
    }
    matricula.setNCurso(entrada.toInt());

    entrada = "";
    for (int i = 11; i <= 13 && i < matriculaText.size(); i++)
    {
        entrada += matriculaText[i];
    }
    matricula.setNumero(entrada.toInt());

    entrada = matriculaText[14];
    matricula.setNumeroVerificador(entrada.toInt());
    return matricula;
}
