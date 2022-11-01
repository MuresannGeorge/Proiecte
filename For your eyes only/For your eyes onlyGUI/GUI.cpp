#include "GUI.h"
#include <qlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include <qmessagebox.h>
#include <string>

GUI::GUI(Business& newbusiness) : business{newbusiness}
{
	this->initGUI();
    this->populateList();
    this->connectSignalsAndSlots();
    this->mode = 2;
    this->modeChanger();

}

void GUI::initGUI()
{
    QStringList days = { "1","2","3","4","5","6",
                         "7","8","9","10","11","12",
                         "13","14","15","16","17","18",
                         "19","20","21","22","23","24",
                         "25","26","27","28","29","30","31" };

    QStringList months = { "01","02","03","04","05","06","07","08","09","10","11","12" };

    QStringList years = { "2020","2019","2018","2017","2016","2015","2014","2013","2012","2011",
                         "2010","2009","2008","2007","2006","2005","2004","2003","2002","2001",
                         "2000","1999","1998","1997","1996","1995","1994","1993","1992","1991","1990" };

    this->recordListWidget = new QListWidget{};
    this->savedRecordsWidget = new QListWidget{};
    this->titleLineEdit = new QLineEdit{};
    this->locationLineEdit = new QLineEdit{};
    this->timesAccessedLineEdit = new QLineEdit{};
    this->FootagePreview = new QLineEdit{};
    this->FilterLocationLineEdit = new QLineEdit{};
    this->FilterTimesAccessedLineEdit = new QLineEdit{};
    this->modeButton = new QPushButton{ "Mode changer" };
    this->addButton = new QPushButton{ "Add" };
    this->deleteButton = new QPushButton{ "Delete" };
    this->updateButton = new QPushButton{ "Update" };
    this->saveButton = new QPushButton{ "Save" };
    this->nextButton = new QPushButton{ "Next" };
    this->filterButton = new QPushButton{ "Filter" };
    this->openButton = new QPushButton{ "Open" };
    this->dayCombo = new QComboBox{};
    this->monthCombo = new QComboBox{};
    this->yearCombo = new QComboBox{};

    this->dayCombo->addItems(days);
    this->monthCombo->addItems(months);
    this->yearCombo->addItems(years);

    QFormLayout* space = new QFormLayout();
    QSpacerItem* spacer = new QSpacerItem(20, 60);
    space->addItem(spacer);

    QVBoxLayout* mainLayout = new QVBoxLayout{ this };
    mainLayout->addWidget(this->modeButton);
    mainLayout->addWidget(this->recordListWidget);

    QFormLayout* recordDetailsLayout = new QFormLayout{};
    recordDetailsLayout->addRow("Title",this->titleLineEdit);
    recordDetailsLayout->addRow("Location", this->locationLineEdit);

    QGridLayout* comboLayout = new QGridLayout{};
    comboLayout->addWidget(this->dayCombo, 0, 1);
    comboLayout->addWidget(this->monthCombo, 0, 0);
    comboLayout->addWidget(this->yearCombo, 0, 2);

    recordDetailsLayout->addRow("TimesAccessed", this->timesAccessedLineEdit);
    recordDetailsLayout->addRow("FootagePreview", this->FootagePreview);

    mainLayout->addLayout(comboLayout);
    mainLayout->addLayout(recordDetailsLayout);

    QGridLayout* firstbuttonsLayout = new QGridLayout{};
    firstbuttonsLayout->addWidget(this->addButton, 0, 0);
    firstbuttonsLayout->addWidget(this->deleteButton, 0, 1);
    firstbuttonsLayout->addWidget(this->updateButton, 0, 2);

    QGridLayout* secondbuttonsLayout = new QGridLayout{};
    secondbuttonsLayout->addWidget(this->nextButton,3,0);
    secondbuttonsLayout->addWidget(this->saveButton,3,1);
    secondbuttonsLayout->addWidget(this->openButton,3,2);

    mainLayout->addLayout(firstbuttonsLayout);

    QFormLayout* filterLayout = new QFormLayout{};
    filterLayout->addRow("Filter Location", this->FilterLocationLineEdit);
    filterLayout->addRow("Filter TimesAccessed", this->FilterTimesAccessedLineEdit);
    secondbuttonsLayout->addWidget(this->filterButton,2,0);
    mainLayout->addLayout(filterLayout);
    mainLayout->addLayout(secondbuttonsLayout);

    mainLayout->addWidget(savedRecordsWidget);

}

void GUI::populateList()
{
    this->recordListWidget->clear();

    std::vector<Record> records = this->business.getAllListOfRecords(); 

    for (Record& record : records)
        this->recordListWidget->addItem(QString::fromStdString(record.printRecord()));
}

void GUI::connectSignalsAndSlots()
{
    QObject::connect(this->recordListWidget, &QListWidget::itemSelectionChanged, [this]() {
        int selectedIndex = this->getSelectedIndex();
        if (selectedIndex < 0)
            return;

        Record record = this->business.getAllListOfRecords()[selectedIndex];
        this->titleLineEdit->setText(QString::fromStdString(record.getTitle()));
        this->locationLineEdit->setText(QString::fromStdString(record.getLocation()));
        this->dayCombo->setCurrentText(QString::fromStdString(std::to_string(record.gettimeOfCreation().getDay())));
        this->monthCombo->setCurrentText(QString::fromStdString(std::to_string(record.gettimeOfCreation().getMonth())));
        this->yearCombo->setCurrentText(QString::fromStdString(std::to_string(record.gettimeOfCreation().getYear())));
        this->timesAccessedLineEdit->setText(QString::fromStdString(to_string(record.getTimesAccessed())));
        this->FootagePreview->setText(QString::fromStdString(record.getFootagePreview()));
    });
    QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addRecord);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::deleteRecord);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUI::updateRecord);
    QObject::connect(this->modeButton, &QPushButton::clicked, this, &GUI::modeChanger);
    QObject::connect(this->nextButton, &QPushButton::clicked, this, &GUI::next);
    QObject::connect(this->saveButton, &QPushButton::clicked, this, &GUI::save);
    QObject::connect(this->filterButton, &QPushButton::clicked, this, &GUI::filteredRecords);
    QObject::connect(this->openButton, &QPushButton::clicked, this, &GUI::mylist);
}

int GUI::getSelectedIndex()
{
    QModelIndexList selectedIndexes = this->recordListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.size() == 0)
    {
        this->titleLineEdit->clear();
        this->locationLineEdit->clear();
        this->timesAccessedLineEdit->clear();
        this->FootagePreview->clear();
        this->dayCombo->setCurrentIndex(0);
        this->monthCombo->setCurrentIndex(0);
        this->yearCombo->setCurrentIndex(0);
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void GUI::addRecord()
{
    string title = this->titleLineEdit->text().toStdString();
    string location = this->locationLineEdit->text().toStdString();
    QString month = this->monthCombo->currentText();
    QString day = this->dayCombo->currentText();
    QString year = this->yearCombo->currentText();
    int timesAccessed = this->timesAccessedLineEdit->text().toInt();
    string footage = this->FootagePreview->text().toStdString();

    if (this->business.addNewRecording(title, location, month.toInt(), day.toInt(), year.toInt(), timesAccessed, footage) == 0)
    {
        QMessageBox::critical(this, "Error", "already exist");
        return;
    }

    this->populateList();

    int lastElement = this->business.getAllListOfRecords().size() - 1;
    this->recordListWidget->setCurrentRow(lastElement);
}

void GUI::deleteRecord()
{
    int selectedIndex = this->getSelectedIndex();
    if (selectedIndex < 0)
    {
        QMessageBox::critical(this, "Error", "You didnt select a record");
        return;
    }

    string title = this->titleLineEdit->text().toStdString();
    string location = this->locationLineEdit->text().toStdString();
    QString month = this->monthCombo->currentText();
    QString day = this->dayCombo->currentText();
    QString year = this->yearCombo->currentText();
    int timesAccessed = this->timesAccessedLineEdit->text().toInt();
    string footagePreview = this->FootagePreview->text().toStdString();

    Record record = this->business.getAllListOfRecords()[selectedIndex];
    this->business.deleteExistingRecording(record.getTitle());
    this->populateList();
}

void GUI::updateRecord()
{
    int selectedIndex = this->getSelectedIndex();
    if (selectedIndex < 0)
    {
        QMessageBox::critical(this, "Error", "You didnt select a record");
        return;
    }

    string title = this->titleLineEdit->text().toStdString();
    string location = this->locationLineEdit->text().toStdString();
    QString month = this->monthCombo->currentText();
    QString day = this->dayCombo->currentText();
    QString year = this->yearCombo->currentText();
    int timesAccessed = this->timesAccessedLineEdit->text().toInt();
    string footagePreview = this->FootagePreview->text().toStdString();

    this->business.updateExistingRecording(title, location, month.toInt(), day.toInt(), year.toInt(), timesAccessed, footagePreview);
    this->populateList();
}

void GUI::next()
{
    Record record = this->business.next();
    this->titleLineEdit->setText(QString::fromStdString(record.getTitle()));
    this->locationLineEdit->setText(QString::fromStdString(record.getLocation()));
    this->dayCombo->setCurrentText(QString::fromStdString(std::to_string(record.gettimeOfCreation().getDay())));
    this->monthCombo->setCurrentText(QString::fromStdString(std::to_string(record.gettimeOfCreation().getMonth())));
    this->yearCombo->setCurrentText(QString::fromStdString(std::to_string(record.gettimeOfCreation().getYear())));
    this->timesAccessedLineEdit->setText(QString::fromStdString(to_string(record.getTimesAccessed())));
    this->FootagePreview->setText(QString::fromStdString(record.getFootagePreview()));
}

void GUI::save()
{
    if (this->titleLineEdit->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "You didnt select a record");
    }
    else
    {
        this->business.save(this->titleLineEdit->text().toStdString());
        this->populateMyList();
    }

}

void GUI::mylist()
{
    this->business.openFile();
}

void GUI::populateMyList()
{
    this->savedRecordsWidget->clear();

    std::vector<Record> records = this->business.getAllSavedRecords();

    for (Record& record : records)
        this->savedRecordsWidget->addItem(QString::fromStdString(record.printRecord()));
}

void GUI::filteredRecords()
{
    auto timesAccesed = this->FilterTimesAccessedLineEdit->text();
    auto location = this->FilterLocationLineEdit->text();
    if (this->FilterLocationLineEdit->text().isEmpty() || this->FilterTimesAccessedLineEdit->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "you didnt provide any location or timesACcessed");
        return;
    }
    try
    {
        int timesACcessed = stoi(this->FilterTimesAccessedLineEdit->text().toStdString());
        vector<Record> records = this->business.getFilteredRecords(location.toStdString(), timesAccesed.toInt());
        this->savedRecordsWidget->clear();
        for (auto record : records)
        {
            this->savedRecordsWidget->addItem(QString::fromStdString(record.printRecord()));
        }
        this->FilterLocationLineEdit->clear();
        this->FilterTimesAccessedLineEdit->clear();
    }
    catch(exception& ex)
    {
        QMessageBox::critical(this, "Error", "timesACcessed needs to be an integer");
    }
}

void GUI::modeChanger()
{
    if (this->mode == 1)
    {
        this->mode = 2;
        this->addButton->setEnabled(false);
        this->deleteButton->setEnabled(false);
        this->updateButton->setEnabled(false);
        this->nextButton->setEnabled(true);
        this->saveButton->setEnabled(true);
        this->openButton->setEnabled(true);
        this->filterButton->setEnabled(true);
    }
    else
    {
        this->mode = 1;
        this->addButton->setEnabled(true);
        this->deleteButton->setEnabled(true);
        this->updateButton->setEnabled(true);
        this->nextButton->setEnabled(false);
        this->saveButton->setEnabled(false);
        this->openButton->setEnabled(false);
        this->filterButton->setEnabled(false);
    }
}
