#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Set::SetDefUniversum();
    ui->LE_U->setText(Set::GetUnivStr());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PB_UDef_clicked()
{
    Set::SetDefUniversum();
    ui->LE_U->setText(Set::GetUnivStr());
}


void MainWindow::on_PB_UClear_clicked()
{
    Set::ClearUniversum();
    ui->LE_U->setText(Set::GetUnivStr());
}


void MainWindow::on_PB_USort_clicked()
{
    Set::SetUniversum(ui->LE_U->text());
    Set::SortUniversum();
    ui->LE_U->setText(Set::GetUnivStr());
}




void MainWindow::on_PB_AClear_clicked()
{
    A.clear();
    ui->LE_A->setText("");
}


void MainWindow::on_PB_ASort_clicked()
{
    A.SetElements(ui->LE_A->text());
    A.sort();
    ui->LE_A->setText(A.GetElements());
}


void MainWindow::on_PB_BClear_clicked()
{
    B.clear();
    ui->LE_B->setText("");
}


void MainWindow::on_PB_BSort_clicked()
{
    B.SetElements(ui->LE_B->text());
    B.sort();
    ui->LE_B->setText(B.GetElements());
}


void MainWindow::on_PB_Calculate_clicked()
{
    A.SetElements(ui->LE_A->text());
    if (ui->CB_AInvert->checkState())
    {
        A.Invert();
    }

    B.SetElements(ui->LE_B->text());
    if (ui->CB_BInvert->checkState())
    {
        B.Invert();
    }

    switch (ui->COMB_Oper->currentIndex()) {
    case 0:
        res = A.Union(B);

        break;
    case 1:
        res = A.Intersect(B);
        break;
    case 2:
        res = A.Diff(B);
        break;
    case 3:
        res = A.SimDif(B);
    }
    res.sort();
    ui->L_Res->setText(res.GetElements());
}

