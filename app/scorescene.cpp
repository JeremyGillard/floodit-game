#include "scorescene.h"

ScoreScene::ScoreScene(QFloodIt& qFloodIt, QWidget* parent)
    : QWidget(parent)
    , model(&qFloodIt)
{
    initComponents();
    arrangement();
    behavior();
}

void ScoreScene::initComponents()
{
    sceneTitle = new QLabel(this);
    sceneTitle->setObjectName("scoretitle");
    table = new QTableWidget(this);
    newGameBtn = new QPushButton("New Game", this);
    mainLayout = new QVBoxLayout;
}

void ScoreScene::populateData()
{

    QString title = QString("Score - Height: %1, Width: %2, Difficulty: %3")
                        .arg(QVariant(model->chosenHeight()).toString(),
                            QVariant(model->chosenWidth()).toString(),
                            QVariant(model->chosenDifficulty()).toString());
    sceneTitle->setText(title);
    // Tableau
    table->setRowCount(0);
    table->setRowCount(model->getScores().size());
    table->setColumnCount(2);
    QStringList labels;
    labels << "Scores"
           << "Names";
    table->setHorizontalHeaderLabels(labels);
    table->verticalHeader()->setVisible(false);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    auto records = model->getScores();
    unsigned i = 0;
    for (const auto& [score, name] : records) {
        table->insertRow(i);
        table->setItem(i, 0, new QTableWidgetItem(QVariant(score).toString()));
        table->setItem(i, 1, new QTableWidgetItem(QVariant(name.c_str()).toString()));
        i++;
    }
}

void ScoreScene::arrangement()
{
    setLayout(mainLayout);
    mainLayout->addWidget(sceneTitle);
    mainLayout->addWidget(table);
    mainLayout->addWidget(newGameBtn);
}

void ScoreScene::behavior()
{
    connect(newGameBtn, &QPushButton::clicked, this, &ScoreScene::newGame);
}
