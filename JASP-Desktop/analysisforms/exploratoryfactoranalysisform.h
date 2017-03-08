//
// Copyright (C) 2013-2017 University of Amsterdam
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public
// License along with this program.  If not, see
// <http://www.gnu.org/licenses/>.
//

#ifndef EXPLORATORYFACTORANALYSISFORM_H
#define EXPLORATORYFACTORANALYSISFORM_H

#include <QWidget>
#include "analysisform.h"

namespace Ui {
class ExploratoryFactorAnalysisForm;
}

class ExploratoryFactorAnalysisForm : public AnalysisForm
{
	Q_OBJECT
	
public:
	explicit ExploratoryFactorAnalysisForm(QWidget *parent = 0);
	~ExploratoryFactorAnalysisForm();
	
private:
	Ui::ExploratoryFactorAnalysisForm *ui;
	
private slots:
	void HandleSlider(int i);
	void HandleLineEdit(QString s);
	
};



#endif // EXPLORATORYFACTORANALYSISFORM_H
