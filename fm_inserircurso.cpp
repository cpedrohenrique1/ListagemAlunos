#include "fm_inserircurso.h"
#include "ui_fm_inserircurso.h"
#include <QMessageBox>
#include <algorithm>

Fm_InserirCurso::Fm_InserirCurso(QWidget *parent, std::list<Pedro::Aluno> *listaAluno) :
    QDialog(parent),
    ui(new Ui::Fm_InserirCurso)
{
    ui->setupUi(this);
    std::list<Pedro::Aluno>::iterator it;
    int vetor[2] = {0, 0};
    for (it = listaAluno->begin(); it != listaAluno->end(); ++it)
    {
        int nCurso = it->getMatricula().getNCurso();
        if (std::find(std::begin(vetor), std::end(vetor), nCurso) == std::end(vetor))
        {
            for (int i = 0; i < 2; i++)
            {
                if (vetor[i] == 0)
                {
                    vetor[i] = nCurso;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        ui->comboBox->addItem(QString::number(vetor[i]));
    }
}

Fm_InserirCurso::~Fm_InserirCurso()
{
    delete ui;
}

void Fm_InserirCurso::on_pushButton_clicked()
{
    try {
        if (ui->comboBox->currentText().isEmpty())
        {
            throw QString("Erro, comboBox nao inicializada");
        }
        emit infoTransmitida(ui->comboBox->currentText().toInt());
        close();
    }
    catch (QString &erro) {
        QMessageBox::critical(this,"Erro", erro);
    }
    catch (...) {
        QMessageBox::critical(this,"Erro", "Erro ao entrar com o numero");
    }
}

