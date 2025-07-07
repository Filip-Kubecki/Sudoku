#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "sudokugame.h"
#include <qpushbutton.h>
#include "QPushButton"
#include <QtWidgets>
#include <QApplication>
#include "QPushButton"
#include "QGridLayout"
#include "QDebug"
#include "QPalette"
#include <QPainter>
#include "qwinnerpopup.h"

using namespace std;

const int buttonSize = 80;
const float buttonSpacing = 1.08;
const int boardSpacing = 5;
int difficultyLevel = 20;

SudokuGame *gameInstance = new SudokuGame();

QList<QPushButton*> buttonList;
QPushButton *prevButton;
map<QPushButton*,int> positionToButtonMap;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui -> setupUi(this);

    this -> setWindowTitle("Sudoku");
    ui -> setupUi(this);
    this -> setFocusPolicy( Qt::StrongFocus );

    this -> setFixedSize(buttonSpacing*1000+(boardSpacing*2), buttonSpacing*buttonSize*9+(boardSpacing*2));

    //Creating board
    int number = 0;
    int constX = 0;
    int constY = 0;
    for (int x = 0; x < 9; ++x) {
        for (int y = 0; y < 9; ++y) {
            QPushButton *button = new QPushButton(this);

            QFont font = button->font();
            font.setPointSize(16);
            button -> setFont(font);

            QPalette pal = button -> palette();
            pal.setColor(QPalette::Button, QColor(Qt::white));
            pal.setColor(QPalette::ButtonText, QColor(Qt::black));
            button -> setAutoFillBackground(true);
            button -> setPalette(pal);
            button -> setText(" ");

            if(y == 3 || y == 6){
                constY += boardSpacing;
            }
            if(x == 3 && y == 0 || x == 6 && y == 0){
                constX += boardSpacing;
            }
            button -> setGeometry(buttonSpacing*(buttonSize*y)+constY, buttonSpacing*buttonSize*x+constX, buttonSize, buttonSize);

            buttonList.append(button);
            positionToButtonMap[button] = x+(10*y);
            button -> show();

            number++;
        }
        constY = 0;
    }
    for (int var = 0; var < buttonList.size(); ++var) {
        QObject::connect(buttonList.at(var),&QPushButton::clicked,this,&MainWindow::setCurrentButton);
    }

    //Creating user input panel
    number = 9;
    for (int x = 0; x < 3; ++x) {
        for (int y = 2; y >= 0; --y) {
            QPushButton *button = new QPushButton(this);

            QFont font = button->font();
            font.setPointSize(16);
            button -> setFont(font);

            button -> setText(QString::number(number));
            button -> setGeometry((buttonSize+10)*y+80+(725), (buttonSize+10)*x+20, buttonSize+10, buttonSize+10);
            QObject::connect(button,&QPushButton::clicked,this,&MainWindow::setBoardValue);
            number--;
        }
    }

    const int button_padding = 10;
    const int button_start_y = 320;
    const int button_spacing = 80;
    //Generate Button
    QPushButton *generateButton = new QPushButton(this);
    generateButton -> setText("Generate");
    generateButton -> setGeometry(buttonSize*10+(button_padding), button_start_y, buttonSize*3+20, buttonSize);
    QObject::connect(generateButton, &QPushButton::clicked,this,&MainWindow::generateBoard);

    //Clear Button
    QPushButton *clearButton = new QPushButton(this);
    clearButton -> setText("Clear");
    clearButton -> setGeometry(buttonSize*10+(button_padding), button_start_y+button_spacing, buttonSize*3+20, buttonSize);
    QObject::connect(clearButton, &QPushButton::clicked,this,&MainWindow::clearBoard);

    //Difficulty level Label
    QPushButton *showSolution = new QPushButton(this);
    showSolution -> setText("Solution");
    showSolution -> setGeometry(buttonSize*10+(button_padding), button_start_y+(2*button_spacing), buttonSize*3+20, buttonSize);
    QObject::connect(showSolution, &QPushButton::clicked,this,&MainWindow::showPosibleSolution);

    //Difficulty level Label
    QLabel *difficultyLabel = new QLabel(this);
    difficultyLabel -> setText("Difficulty:");
    difficultyLabel -> setGeometry(buttonSize*10+20, button_start_y+(3*button_spacing), buttonSize*2, buttonSize);


    //Difficulty level Slider
    QSlider *levelSlider = new QSlider(this);
    levelSlider -> setGeometry(buttonSize*10+10, button_start_y+(3*button_spacing)+20, buttonSize*3, buttonSize);
    levelSlider -> setOrientation(Qt::Horizontal);
    levelSlider -> setMinimum(2);
    levelSlider -> setMaximum(40);
    levelSlider -> invertedControls();
    levelSlider -> setSliderPosition(difficultyLevel);
    levelSlider -> setSingleStep(2);
    QObject::connect(levelSlider, &QSlider::sliderMoved,this,[=]{
        difficultyLevel = levelSlider -> value();
    });
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setCurrentButton(){
    if(prevButton != NULL){
        QPalette palx = prevButton -> palette();
        palx.setColor(QPalette::Button, QColor(Qt::white));
        prevButton -> setAutoFillBackground(true);
        prevButton -> setPalette(palx);
        prevButton -> update();
    }


    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    prevButton = qobject_cast<QPushButton *>(sender());

    QPalette pal = clickedButton->palette();
    pal.setColor(QPalette::Button, QColor(76, 205, 153));
    clickedButton -> setAutoFillBackground(true);
    clickedButton -> setPalette(pal);
    clickedButton -> update();
}

void MainWindow::clearBoard(){
    prevButton = NULL;
    for (int var = 0; var < buttonList.size(); ++var) {
        QPalette pal = buttonList.at(var) -> palette();
        pal.setColor(QPalette::Button, QColor(Qt::white));
        buttonList.at(var) -> setAutoFillBackground(true);
        buttonList.at(var) -> setPalette(pal);
        buttonList.at(var) -> update();
        buttonList.at(var) -> setText("");
        buttonList.at(var) -> setEnabled(true);
    }
    gameInstance -> clearBoard();
}

void MainWindow::setBoardValue(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString value = clickedButton->text();

    int position = positionToButtonMap.find(prevButton) -> second;
    cout << position%10 << " " << position/10 << "Position: " << position << endl;
    if(gameInstance -> setBoardValue((position/10)+1,(position%10)+1,value.toInt())){
        prevButton -> setText(value);
        gameInstance -> printBoard();
    }else{
        cout << "wrong value" << endl;
    }
    if(gameInstance -> checkIfGameFinished()){
        QWinnerPopup popup;
        popup.setModal(true);
        popup.exec();
    }
}

void MainWindow::generateBoard(){
    clearBoard();

    gameInstance -> generateBoard(difficultyLevel);

    int next = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int value = gameInstance -> getBoardValue(i,j);
            if(value == 0){
                buttonList.at(next) -> setText("");
                next++;
            }else{
                buttonList.at(next) -> setText(QString::number(value));
                buttonList.at(next) -> setEnabled(false);
                QPalette pal = buttonList.at(next) -> palette();
                pal.setColor(QPalette::Button, QColor(226, 231, 237));
                buttonList.at(next) -> setAutoFillBackground(true);
                buttonList.at(next) -> setPalette(pal);
                buttonList.at(next) -> update();
                next++;
            }
        }
    }
    gameInstance -> printBoard();
}

void MainWindow::showPosibleSolution(){
    //Clear GUI board
    prevButton = NULL;
    for (int var = 0; var < buttonList.size(); ++var) {
        QPalette pal = buttonList.at(var) -> palette();
        pal.setColor(QPalette::Button, QColor(Qt::white));
        buttonList.at(var) -> setAutoFillBackground(true);
        buttonList.at(var) -> setPalette(pal);
        buttonList.at(var) -> update();
        buttonList.at(var) -> setText("");
        buttonList.at(var) -> setEnabled(true);
    }

    int next = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int value = gameInstance -> getSolutionValue(i,j);
            int valueX = gameInstance -> getBoardValue(i,j);
            if(valueX == 0){
                buttonList.at(next) -> setText(QString::number(value));
                buttonList.at(next) -> setEnabled(false);
                QPalette palx = buttonList.at(next) -> palette();
                palx.setColor(QPalette::Button, QColor(177, 222, 200));
                buttonList.at(next) -> setAutoFillBackground(true);
                buttonList.at(next) -> setPalette(palx);
                buttonList.at(next) -> update();
                next++;
            }else{
                buttonList.at(next) -> setText(QString::number(value));
                buttonList.at(next) -> setEnabled(false);
                QPalette pal = buttonList.at(next) -> palette();
                pal.setColor(QPalette::Button, QColor(226, 231, 237));
                buttonList.at(next) -> setAutoFillBackground(true);
                buttonList.at(next) -> setPalette(pal);
                buttonList.at(next) -> update();
                next++;
            }
        }
    }
}
