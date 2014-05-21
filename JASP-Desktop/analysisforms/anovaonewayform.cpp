#include "anovaonewayform.h"
#include "ui_anovaonewayform.h"

#include "analysisform.h"

AnovaOneWayForm::AnovaOneWayForm(QWidget *parent) :
	AnalysisForm("AnovaOneWayForm", parent),
	ui(new Ui::AnovaOneWayForm)
{
	ui->setupUi(this);

	ui->listAvailableFields->setModel(&_availableVariablesModel);
	ui->listAvailableFields->setDoubleClickTarget(ui->variables);

	TableModelVariablesAssigned *variablesModel = new TableModelVariablesAssigned(this);
	variablesModel->setSource(&_availableVariablesModel);
	variablesModel->setVariableTypesAllowed(Column::ColumnTypeNominal | Column::ColumnTypeOrdinal | Column::ColumnTypeScale);
	variablesModel->setVariableTypesSuggested(Column::ColumnTypeScale);
	ui->variables->setModel(variablesModel);
	ui->variables->setDoubleClickTarget(ui->listAvailableFields);

	TableModelVariablesAssigned *groupingVariableModel = new TableModelVariablesAssigned(this);
	groupingVariableModel->setVariableTypesAllowed(Column::ColumnTypeNominalText | Column::ColumnTypeNominal | Column::ColumnTypeOrdinal);
	groupingVariableModel->setVariableTypesSuggested(Column::ColumnTypeOrdinal | Column::ColumnTypeNominal);
	groupingVariableModel->setSource(&_availableVariablesModel);
	ui->groupingVariable->setModel(groupingVariableModel);
	ui->groupingVariable->setDoubleClickTarget(ui->listAvailableFields);

	ui->buttonAssignVariables->setSourceAndTarget(ui->listAvailableFields, ui->variables);
	ui->buttonAssignGroupingVariable->setSourceAndTarget(ui->listAvailableFields, ui->groupingVariable);
}

AnovaOneWayForm::~AnovaOneWayForm()
{
	delete ui;
}
