#include "executarmodo.h"
#include "fm_inserircurso.h"
#include "fm_inserirdisciplinaturma.h"

namespace Pedro
{

int ExecutarModo::getInfoCurso() const
{
    return infoCurso;
}

void ExecutarModo::setInfoCurso(int newInfoCurso)
{
    infoCurso = newInfoCurso;
}

Pedro::DisciplinaTurma ExecutarModo::getInfoDisciplinaTurma() const
{
    return infoDisciplinaTurma;
}

void ExecutarModo::setInfoDisciplinaTurma(Pedro::DisciplinaTurma newInfoDisciplinaTurma)
{
    infoDisciplinaTurma = newInfoDisciplinaTurma;
}

Pedro::Aluno ExecutarModo::getInfoAluno() const
{
    return infoAluno;
}

void ExecutarModo::setInfoAluno(Pedro::Aluno newInfoAluno)
{
    infoAluno = newInfoAluno;
}

void ExecutarModo::receberInfo(int infoCurso)
{
    this->infoCurso = infoCurso;
}

void ExecutarModo::receberInfoDisciplina(QString infoDisciplina)
{
    this->infoDisciplina = infoDisciplina;
}

void ExecutarModo::receberInfoMatricula(Matricula infoMatricula)
{
    this->infoMatricula = infoMatricula;
}

void ExecutarModo::receberInfoDisciplinaTurma(Pedro::DisciplinaTurma disciplinaTurma)
{
    this->infoDisciplinaTurma = disciplinaTurma;
}

ExecutarModo::ExecutarModo():
    infoCurso(0)
  , infoDisciplinaTurma()
  , infoAluno()
{}

void ExecutarModo::operator ()(QString enderecoArquivo, QString textoComboBox, QTableWidget* parent, std::list<Pedro::Aluno> listaAluno)
{
    if (enderecoArquivo.isEmpty())
    {
        throw QString("Arquivo nao selecionado");
    }

    if (textoComboBox == "Selecionar Modo...")
    {
        throw QString("Selecione um modo primeiro");
    }

    parent->clearSelection();
    parent->setRowCount(0);

    if (textoComboBox == "Todos os alunos de um curso")
    {
        Fm_InserirCurso f_inserirCurso(nullptr, &listaAluno);
        QObject::connect(&f_inserirCurso, &Fm_InserirCurso::infoTransmitida, this, &ExecutarModo::receberInfo);
        f_inserirCurso.exec();
        parent->setColumnCount(2);
        QStringList cabecalho = {"Matricula", "Nome"};
        parent->setHorizontalHeaderLabels(cabecalho);
        std::list<Pedro::Aluno>::iterator it;
        int cont = 0;
        for (it = listaAluno.begin(); it != listaAluno.end(); it = ++it)
        {
            if (it->getMatricula().getNCurso() == infoCurso)
            {
                parent->insertRow(cont);
                parent->setItem(cont, 0, new QTableWidgetItem(it->getMatricula()));
                parent->setItem(cont, 1, new QTableWidgetItem(it->getNomeCompleto()));
                cont++;
            }
        }
    }

    if (textoComboBox == "Alunos de uma turma")
    {
        Fm_InserirDisciplinaTurma f_inserirDisciplinaTurma;
        QObject::connect(&f_inserirDisciplinaTurma, &Fm_InserirDisciplinaTurma::infoTransmitida, this, &ExecutarModo::receberInfoDisciplinaTurma);
        f_inserirDisciplinaTurma.exec();
        parent->setColumnCount(2);
        QStringList cabecalho = {"Matricula", "Nome"};
        parent->setHorizontalHeaderLabels(cabecalho);
        std::list<Pedro::Aluno>::iterator it;
        std::list<Pedro::DisciplinaTurma>::iterator itDisciplina;
        int cont = 0;
        for (it = listaAluno.begin(); it != listaAluno.end(); ++it)
        {
            itDisciplina = it->getListaDisciplinaTurma()->begin();
            while (itDisciplina != it->getListaDisciplinaTurma()->end())
            {
                if (itDisciplina->getDisciplinaTurma() == infoDisciplinaTurma.getDisciplinaTurma())
                {
                    parent->insertRow(cont);
                    parent->setItem(cont, 0, new QTableWidgetItem(it->getMatricula()));
                    parent->setItem(cont, 1, new QTableWidgetItem(it->getNomeCompleto()));
                    cont++;
                }
                ++itDisciplina;
            }
        }
    }

    if (textoComboBox == "Alunos de uma disciplina")
    {
        Fm_InserirDisciplina f_inserirDisciplina;
        QObject::connect(&f_inserirDisciplina, &Fm_InserirDisciplina::infoTransmitida, this, &ExecutarModo::receberInfoDisciplina);
        f_inserirDisciplina.exec();
        parent->setColumnCount(2);
        QStringList cabecalho = {"Matricula", "Nome"};
        parent->setHorizontalHeaderLabels(cabecalho);
        std::list<Pedro::Aluno>::iterator it;
        std::list<Pedro::DisciplinaTurma>::iterator itDisciplina;
        int cont = 0;
        for (it = listaAluno.begin(); it != listaAluno.end(); ++it)
        {
            itDisciplina = it->getListaDisciplinaTurma()->begin();
            while (itDisciplina != it->getListaDisciplinaTurma()->end())
            {
                if (itDisciplina->getCodigoDisciplina() == infoDisciplina)
                {
                    parent->insertRow(cont);
                    parent->setItem(cont, 0, new QTableWidgetItem(it->getMatricula()));
                    parent->setItem(cont, 1, new QTableWidgetItem(it->getNomeCompleto()));
                    cont++;
                }
                ++itDisciplina;
            }
        }
    }
    parent->setColumnWidth(0, 130);
    parent->setColumnWidth(1, 610);

    if (textoComboBox == "Todas as disciplinas de um aluno")
    {
        Fm_InserirMatricula f_inserirMatricula;
        QObject::connect(&f_inserirMatricula, &Fm_InserirMatricula::infoTransmitida, this, &ExecutarModo::receberInfoMatricula);
        f_inserirMatricula.exec();
        parent->setColumnCount(1);
        QStringList cabecalho = {"Nome e disciplinas"};
        parent->setHorizontalHeaderLabels(cabecalho);
        std::list<Pedro::Aluno>::iterator it;
        std::list<Pedro::DisciplinaTurma>::iterator itDisciplina;
        int cont = 0;
        for (it = listaAluno.begin(); it != listaAluno.end(); ++it)
        {
            if (it->getMatricula() == infoMatricula)
            {
                parent->insertRow(cont);
                parent->setItem(cont, 0, new QTableWidgetItem(it->getNomeCompleto()));
                cont++;
                itDisciplina = it->getListaDisciplinaTurma()->begin();
                while (itDisciplina != it->getListaDisciplinaTurma()->end())
                {
                    parent->insertRow(cont);
                    parent->setItem(cont, 0, new QTableWidgetItem(itDisciplina->getDisciplinaTurma()));
                    ++itDisciplina;
                    cont++;
                }
            }
        }
        parent->setColumnWidth(0, 730);
    }
    parent->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

}
