#include<QtWidgets>
#include "road.h"
class MainWindow : public QMainWindow {
public:
	MainWindow(Road* _road);
	void buttonRoad1Click();
	void buttonRoad2Click();

private:
	QLabel* widthLabel;
	QPushButton* buttonRoad1;
	Road* road1;
	QPushButton* buttonRoad2;
	QLineEdit* WidthEdit
};

MainWindow::MainWindow(Road* _road) {
	setFixedSize(700, 400);
	setWindowTitle("Two roads v8.2");
	QFont LabelFont("System", 36, QFont::Normal);
	QFont buttonFont("Helvetica [cronyx]", 13, QFont::Bold);

	widthLabel = new QLabel("Width: ", this);
	widthLabel->setGeometry(0, 0, 500, 150);
	widthLabel->setFont(LabelFont);
	widthLabel->setText("Width: " + QString::number(_road->Width));

	buttonRoad1 = new QPushButton("road 1", this);
	buttonRoad1->setGeometry(20, 170, 200, 150);
	buttonRoad1->setFont(buttonFont);

	buttonRoad2 = new QPushButton("road 2", this);
	buttonRoad2->setGeometry(270, 170, 200, 150);
	buttonRoad2->setFont(buttonFont);

	WidthEdit = new WidthEdit("road 2", this);
	WidthEdit->setGeometry(20, 260, 200, 70);
	WidthEdit->setFont(buttonFont);

	road1 = _road;
	connect(buttonRoad1, &QPushButton::clicked, this, &MainWindow::buttonRoad1Click);
	connect(buttonRoad2, &QPushButton::clicked, this, &MainWindow::buttonRoad2Click);
}

void MainWindow::buttonRoad1Click() {
	QString strWidth;
	strWidth = widthEdit.text();
	road1->Width = 4;
	widthLabel->setText("Width: " + QString::number(road1->Width));

}
void MainWindow::buttonRoad2Click() {
	road1->Width = 8;
	widthLabel->setText("Width: " + QString::number(road1->Width));

}
int main(int argc, char* argv[]) {
	Road road(6);
	test8.pro
		QApplication app(argc, argv);
	MainWindow mainWin(&road);
	mainWin.show();
	return app.exec();
}
