#include "buscaraluno.h"
#include <QMessageBox>
#include<fstream>


namespace Pedro {

BuscarAluno::BuscarAluno():
    enderecoArquivo("")
{}

BuscarAluno::BuscarAluno(QString enderecoArquivo):
    enderecoArquivo(enderecoArquivo)
{}

QString BuscarAluno::operator ()(QWidget *parent, std::list<Pedro::Aluno> &listaAluno)
{
    enderecoArquivo = QFileDialog::getOpenFileName(parent, "Abrir Arquivo", QDir::homePath(), "*.csv");
    std::ifstream arquivo;
    arquivo.open(enderecoArquivo.toStdString());
    if (!arquivo.is_open())
    {
        throw QString ("Arquivo nao foi aberto");
    }
    arquivo.seekg(0);
    std::string linha;
    while (getline(arquivo,linha))
    {
        std::string entrada = "";
        for (int i = 0; linha[i] != '.'; i++)
        {
            entrada += linha[i];
        }
        Pedro::Matricula matricula;
        matricula.setAno(std::stoi(entrada));
        entrada = linha[5];
        matricula.setSemestre(std::stoi(entrada));
        entrada = "";
        for (int i = 7; linha[i] != '.'; i++)
        {
            entrada += linha[i];
        }
        matricula.setNCurso(std::stoi(entrada));

        entrada = "";
        for (int i = 11; i <= 13; i++)
        {
            entrada += linha[i];
        }
        matricula.setNumero(std::stoi(entrada));

        entrada = linha[14];
        matricula.setNumeroVerificador(std::stoi(entrada));

        Pedro::Aluno aluno;
        entrada = "";
        int indice = 16;
        for (int i = 16; linha[i] != ';'; i++)
        {
            entrada += linha[i];
            indice = i;
        }
        aluno.setNomeCompleto(QString::fromStdString(entrada));
        indice+= 2;
        std::list<Pedro::DisciplinaTurma> *disciplina = new std::list<Pedro::DisciplinaTurma>;
        while (indice < linha.size() - 1)
        {
            if (linha[indice] == ' ')
            {
                indice++;
            }
            else
            {
                entrada = "";
                while (linha[indice] != '-' && linha[indice] != ' ' && indice < linha.size() - 1)
                {
                    entrada += linha[indice++];
                }
                std::string codigodisciplina = entrada;
                entrada = "";
                indice++;
                while (linha[indice] != ' ' && indice < linha.size() - 1)
                {
                    entrada += linha[indice++];
                }
                disciplina->push_back(Pedro::DisciplinaTurma(QString::fromStdString(codigodisciplina), QString::fromStdString(entrada)));
            }
        }
        aluno.setMatricula(matricula);
        aluno.setDisciplinaTurma(disciplina);
        listaAluno.push_back(aluno);
    }
    return enderecoArquivo;
}

QString BuscarAluno::getEnderecoArquivo() const
{
    return enderecoArquivo;
}

void BuscarAluno::setEnderecoArquivo(QString newEnderecoArquivo)
{
    enderecoArquivo = newEnderecoArquivo;
}

}
