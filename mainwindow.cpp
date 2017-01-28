#include "mainwindow.h"
#include "ui_mainwindow.h"

//explicit constructor
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_app_path = QApplication::applicationDirPath();
    scene_maker();
    buttons_maker();
    about_window_maker();
    message_maker();
    m_graphic_graph = new graphics_graph(m_scene, m_width, m_height, m_scene_width, m_scene_height);
    m_media = new Media(this, m_app_path, m_width, m_height);
    m_state = 0;
    m_prim_timers = vector<QTimer*>(3);
    m_kruskal_timers = vector<QTimer*>(3);
    for (int i = 0; i < 3; ++i)
    {
        m_prim_timers[i]=new QTimer(this);
        m_kruskal_timers[i]=new QTimer(this);
    }
    m_prim = new Prim(m_graphic_graph, m_message, m_prim_timers);
    m_kruskal = new Kruskal(m_graphic_graph, m_message, m_kruskal_timers);
    connect(m_buttons[0],SIGNAL(clicked()),this,SLOT(new_slot()));
    connect(m_buttons[1],SIGNAL(clicked()),this,SLOT(about_slot()));
    connect(m_buttons[2],SIGNAL(clicked()),this,SLOT(Prim_starting_slot()));
    connect(m_buttons[3],SIGNAL(clicked()),this,SLOT(Kruskal_starting_slot()));
    connect(m_buttons[4],SIGNAL(clicked()),this,SLOT(close()));
    connect(m_pause.first, SIGNAL(clicked()), this, SLOT(pause_restart_slot()));
    connect(m_prim_timers[0], SIGNAL(timeout()), this, SLOT(Prim_considering()));
    connect(m_prim_timers[1], SIGNAL(timeout()), this, SLOT(Prim_appending()));
    connect(m_prim_timers[2], SIGNAL(timeout()), this, SLOT(Prim_considering_helper()));
    connect(m_kruskal_timers[0], SIGNAL(timeout()), this, SLOT(Kruskal_forest_creator()));
    connect(m_kruskal_timers[1], SIGNAL(timeout()), this, SLOT(Kruskal_edge_considering()));
    connect(m_kruskal_timers[2], SIGNAL(timeout()), this, SLOT(Kruskal_DSU()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//creates 2-D scene
void MainWindow::scene_maker()
{
    m_width=QApplication::desktop()->geometry().width();
    m_height=QApplication::desktop()->geometry().height();
    this->setGeometry(0, 0, m_width, m_height);
    m_view = new QGraphicsView(this);
    m_view->setGeometry(0, 0, (m_width * for_view.first) / percent, (m_height * for_view.second) / percent);
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scene = new QGraphicsScene(this);
    m_scene_width = (m_view->width() * for_scene_size) / percent;
    m_scene_height = (m_view->height() *for_scene_size) /percent;
    m_scene->setSceneRect(real_zero, real_zero, m_scene_width, m_scene_height);

    QPen P(Qt::black);
    QBrush B(Qt::white, Qt::SolidPattern);
    QLineF top_line(m_scene->sceneRect().topLeft(), m_scene->sceneRect().topRight());
    QLineF left_line(m_scene->sceneRect().topLeft(), m_scene->sceneRect().bottomLeft());
    QLineF right_line(m_scene->sceneRect().topRight(), m_scene->sceneRect().bottomRight());
    QLineF bottom_line(m_scene->sceneRect().bottomLeft(), m_scene->sceneRect().bottomRight());
    QLineF middle_line(QPointF(m_scene_width / _two,real_zero), QPointF(m_scene_width / _two, m_scene_height));

    m_scene->setBackgroundBrush(B);
    m_scene->addLine(top_line, P);
    m_scene->addLine(left_line, P);
    m_scene->addLine(right_line, P);
    m_scene->addLine(bottom_line, P);
    m_scene->addLine(middle_line, P);

    m_texts.first = new graphics_text(QString("GRAPH"), QPointF((m_scene_width * for_texts_x.first) / percent,
                                                    (m_scene_width * for_texts_y) / percent), m_scene_height * for_font/percent);
    m_scene->addItem(m_texts.first);
    m_texts.second = new graphics_text(QString("MST"), QPointF((m_scene_width * for_texts_x.second) / percent,
                                                    (m_scene_width * for_texts_y) / percent), m_scene_height * for_font/percent);
    m_scene->addItem(m_texts.second);
    m_view->setScene(m_scene);
}

//creates five buttons
void MainWindow::buttons_maker()
{
    vector<QString> V{" NEW", "ABOUT", "PRIM'S \n  ALGORITHM", "  KRUSKAL'S \n  ALGORITHM", " EXIT"};
    QFont f("Sans");
    f.setWeight((int)(for_buttons[7] * m_height) / percent);
    m_buttons=vector<QPushButton*>(5);
    for (size_t i = 0; i < m_buttons.size(); ++i)
    {
        m_buttons[i]=new QPushButton(V[i],this);
        m_buttons[i]->setGeometry((int)(for_buttons[i] * m_width) / percent, (int)(for_buttons[5] * m_height) / percent,
                 (int)(for_buttons[6] * m_width) / percent,(int)(for_buttons[7] * m_height) / percent);
        if (i == 2 || i == 3)
            f.setPointSize((int)m_buttons[i]->width() / 10);
        else f.setPointSize((int)m_buttons[i]->width() / 5);
        m_buttons[i]->setFont(f);
        m_buttons[i]->setStyleSheet("QPushButton { background-color : blue; color : white; }");
    }
    m_pause.first = new QPushButton(this);
    m_pause.first->setGeometry((int)(m_width * for_pause.first.first / percent), (int)(m_height * for_pause.first.second / percent),
                               (int)(m_width * for_pause.second / percent), (int)(m_width * for_pause.second / percent));
    m_pause.first->setStyleSheet("QPushButton {  background-color : transparent; color : black; }");
    m_pause.first->setIcon(QIcon(m_app_path + for_paths[0] + for_paths[5]));
    m_pause.second = make_pair(-1, false);
}

//creates widget about program
void MainWindow::about_window_maker()
{
    m_about = new about_window(this, (int)m_width, (int)m_height, m_app_path);
    m_about->close();
    update();
}

//creates message about completed work
void MainWindow::message_maker()
{
    m_message = new QWidget(this);
    m_message->setGeometry(((int)m_width * for_message1.first) / (int)percent, ((int)m_height * for_message1.second) / (int)percent,
                           ((int)m_width * for_message.first) / (int)percent , ((int)m_height * for_message.second) / (int)percent);
    m_message->setStyleSheet("QWidget { background-color : green; color : black; }");
    QLabel *L = new QLabel(m_message);
    L->setGeometry(0, 0, m_message->width(), (m_message->height()) * 2 / 3);
    L->setStyleSheet("QLabel { background-color : transparent; color : white; }");
    L->setFont(QFont("Sans", L->width() / 16, L->width() / 16));
    L->setText("     Minimal spanning \n          tree found");
    QPushButton *B = new QPushButton("OK", m_message);
    B->setGeometry(m_message->width()/3, m_message->height() *2 / 3, m_message->width() / 3, m_message->height() / 3);
    B->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
    B->setFont(QFont("Sans", L->width()/ 16 , L->width() / 16));
    m_message->hide();
    connect(B, SIGNAL(clicked()), this, SLOT(message_hide()));
}

//paints background
void MainWindow::paintEvent(QPaintEvent *)
{
    vector<QString> V{" NEW", "ABOUT", "  PRIM'S \n  ALGORITHM", "  KRUSKAL'S \n  ALGORITHM", " EXIT"};
    QPainter painter(this);
    QBrush B(Qt::SolidPattern);
    QPen p(Qt::white);
    QRectF R(0, m_scene_height, m_width, m_height-m_scene_height);
    B.setColor(QColor("#CBDEDF"));
    painter.fillRect(R, B);
}

void MainWindow::message_hide()
{
    m_message->close();
    m_scene->update();
}

//Controlls algorithm pause and restart
void MainWindow::pause_restart_slot()
{
    if (m_state)
    {
        if (!m_pause.second.second)
        {
            m_pause.first->setIcon(QIcon(m_app_path + for_paths[0] + for_paths[6]));
            for (int i = 0; i < 3; ++i)
            {
                if (m_prim_timers[i]->isActive())
                {
                    m_prim_timers[i]->stop();
                    m_pause.second.first = i;
                    break;
                }
                if (m_kruskal_timers[i]->isActive())
                {
                    m_kruskal_timers[i]->stop();
                    m_pause.second.first = i;
                    break;
                }
            }
        }
        else
        {
            m_pause.first->setIcon(QIcon(m_app_path + for_paths[0] + for_paths[5]));
            if (m_pause.second.first != -1)
            {
                if (m_state == PRIM)
                    m_prim_timers[m_pause.second.first]->start(5000);
                if (m_state == KRUSKAL)
                     m_kruskal_timers[m_pause.second.first]->start(5000);
            }
        }
        m_pause.second.second = 1 - m_pause.second.second;
    }
}

//back to the initial state
void MainWindow::new_slot()
{
    m_state = 0;
    m_pause.first->setIcon(QIcon(m_app_path + for_paths[0] + for_paths[5]));
    m_pause.second=make_pair(-1, false);
    m_buttons[2]->setEnabled(true);
    m_buttons[3]->setEnabled(true);
    m_buttons[2]->setStyleSheet("QPushButton { background-color : blue; color : white; }");
    m_buttons[3]->setStyleSheet("QPushButton { background-color : blue; color : white; }");
    for (int i = 0; i < 3; ++i)
    {
        if (m_prim_timers[i]->isActive())
            m_prim_timers[i]->stop();
        if (m_kruskal_timers[i]->isActive())
            m_kruskal_timers[i]->stop();
    }
    m_prim->restore();
    if (m_message->isActiveWindow())
        m_message->close();
    m_graphic_graph->restore();
    update();
}

void MainWindow::about_slot()
{
    m_about->showFullScreen();
    this->close();
}

//starts Prim's algo.. demonstration
void MainWindow::Prim_starting_slot()
{
    if (!m_state)
    {
        m_state = PRIM;
        m_buttons[2]->setDisabled(true);
        m_buttons[3]->setDisabled(true);
        m_buttons[2]->setStyleSheet("QPushButton { background-color : #00ff00; color : white; }");
        m_buttons[3]->setStyleSheet("QPushButton { background-color : black; color : white; }");
        m_prim->run();
    }
}

//starts Kruskal's algo.. demonstration
void MainWindow::Kruskal_starting_slot()
{
    if (!m_state)
    {
        m_state = KRUSKAL;
        m_buttons[2]->setDisabled(true);
        m_buttons[3]->setDisabled(true);
        m_buttons[2]->setStyleSheet("QPushButton { background-color : black; color : white; }");
        m_buttons[3]->setStyleSheet("QPushButton { background-color : #00ff00; color : white; }");
        m_kruskal->run();
    }
}

void MainWindow::Prim_considering()
{
    m_prim->step1();
}

void MainWindow::Prim_considering_helper()
{
    m_prim->step3();
}

void MainWindow::Prim_appending()
{
    m_prim->step2();
}

void MainWindow::Kruskal_forest_creator()
{
    m_kruskal->step1();
}

void MainWindow::Kruskal_edge_considering()
{
    m_kruskal->step2();
}

void MainWindow::Kruskal_DSU()
{
    m_kruskal->step3();
}
