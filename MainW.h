#ifndef MAINW_H
#define MAINW_H

#include <QtWidgets>
#include <QJSEngine>

#include "DisWidget.h"

class MainW : public QMainWindow
{
	Q_OBJECT

	DisWidget *display = new DisWidget(this);
	QSplitter *splitterMain = new QSplitter(Qt::Vertical, this);

	QTextEdit *codeEdit = new QTextEdit(this);
	QTextEdit *runEdit = new QTextEdit(this);
	QSplitter *splitter = new QSplitter(Qt::Horizontal, this);

	QAction *act = new QAction("execute", this);

	QJSEngine *js = new QJSEngine(this);

public:
	MainW(QWidget *parent = 0) : QMainWindow(parent){
		this->splitter->addWidget(this->codeEdit);
		this->splitter->addWidget(this->runEdit);
		this->splitter->setCollapsible(0, false);
		this->splitter->setCollapsible(1, false);
		this->runEdit->setReadOnly(true);

		this->splitterMain->addWidget(this->display);
		this->splitterMain->addWidget(this->splitter);
		this->splitterMain->setCollapsible(0, false);
		this->splitterMain->setCollapsible(1, false);

		this->setCentralWidget(this->splitterMain);
		this->resize(400, 600);

		this->menuBar()->addAction(this->act);

		this->js->installExtensions(QJSEngine::AllExtensions);

		QJSValue codeEditJsObject = js->newQObject(this->codeEdit);
		QJSValue runEditJsObject = js->newQObject(this->runEdit);
		js->globalObject().setProperty("codeEdit", codeEditJsObject);
		js->globalObject().setProperty("runEdit", runEditJsObject);

		QJSValue displayJsObject = js->newQObject(this->display);
		js->globalObject().setProperty("turtle", displayJsObject);


		this->connect(this->act, &QAction::triggered, [this](bool){
			this->runEdit->clear();
			try{
				QJSValue result = js->evaluate(this->codeEdit->toPlainText());
				if(result.isError()){
					throw result;
				}
				this->runEdit->insertPlainText(result.toString());
			}catch(const QJSValue &value){
				if(value.isError()){
					this->runEdit->insertPlainText(tr("Uncaught exception at line %1 : %2").arg(value.property("lineNumber").toInt()).arg(value.toString()));
				}
			}
		});

	}
	~MainW();
};

#endif // MAINW_H
