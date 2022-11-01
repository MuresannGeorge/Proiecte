#pragma once
#include <qwidget.h>
#include "Business.h"
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qcombobox.h>
#include <qfiledialog.h>

using namespace std;

class GUI : public QWidget
{
private:
	Business& business;

	QListWidget* recordListWidget,*savedRecordsWidget;
	QLineEdit* titleLineEdit, * locationLineEdit, * timesAccessedLineEdit, * FootagePreview, *FilterTimesAccessedLineEdit, *FilterLocationLineEdit;
	QPushButton* addButton, * deleteButton, *updateButton,*modeButton,*nextButton,*saveButton,*filterButton,*openButton;
	QComboBox* dayCombo, * monthCombo, * yearCombo;
	
public:
	GUI(Business& business);

private:
	int mode = 1;
	void initGUI();
	void populateList();
	void connectSignalsAndSlots();
	int getSelectedIndex();

	void addRecord();
	void deleteRecord();
	void updateRecord();
	void next();
	void save();
	void mylist();
	void populateMyList();
	void filteredRecords();
	void modeChanger();
};
