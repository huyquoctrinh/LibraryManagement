#include "regulationwidget.h"
#include "ui_regulationwidget.h"

RegulationWidget::RegulationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegulationWidget)
{
    ui->setupUi(this);
}

RegulationWidget::~RegulationWidget()
{
    delete ui;
}
