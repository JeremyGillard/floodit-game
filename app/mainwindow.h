#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>

#include "gamescene.h"
#include "introductionscene.h"
#include "qfloodit.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void switchScene();

private:
    QFloodIt* model;

    QWidget* centralWidget;

    IntroductionScene* iScene;

    GameScene* gScene;

    int switchSceneIndex;

    QStackedLayout* layout;

    void initComponents();

    void arrangement();

    void behavior();
};
#endif // MAINWINDOW_H
