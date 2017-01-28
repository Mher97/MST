#include "about_window.h"

//constructor
about_window::about_window(QWidget *parent, int w, int h, QString S)
{
    m_parent = parent;
    m_width = w;
    m_height = h;
    m_app_path = S;
    buttons_maker();
    this->setGeometry(0, 0, (int)m_width, (int)m_height);
    m_background = new QImage(m_app_path + for_paths[0] + for_paths[3]);
    connect(m_back, SIGNAL(clicked()), this, SLOT(back_slot()));
    connect(m_more, SIGNAL(clicked()), this, SLOT(more_slot()));
}

//destructor
about_window::~about_window()
{
    delete m_parent;
    delete m_back;
    delete m_more;
    delete m_background;
}

QRect about_window::boundingRect(int a, int b, int c, int d)
{
    return QRect(a, b, c, d);
}

void about_window::buttons_maker()
{
    QFont font("Courier", m_height * for_about[4] / (int)percent, m_height * for_about[4] / (int)percent);
    m_back=new QPushButton("Back", this);
    m_back->setFont(font);
    m_back->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
    m_back->setGeometry((m_width * for_about[2]) / (int)percent,(m_height * for_about[4]) / (int)percent,
                        (m_width * for_about[3]) / (int)percent,(m_height * for_about[3]) / (int)percent);
    m_more = new QPushButton("More \n...", this);
    font.setPointSizeF((qreal)m_height * for_about_font/percent);
    m_more->setFont(font);
    m_more->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
    m_more->setGeometry((m_width * for_about[5]) / (int)percent,(m_height * for_about[7]) / (int)percent,
                        (m_width * for_about[3]) / (int)percent,(m_height * for_about[3]) / (int)percent);

}

void about_window::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(boundingRect(0, 0, m_width, m_height),*m_background, boundingRect(0, 0, for_about[0], for_about[1]));
    painter.setPen(Qt::white);
    QFont font("Courier", m_height * for_about[4] / (int)percent,m_height * for_about[4] / (int)percent);
    painter.setFont(font);
    painter.drawText(boundingRect(m_width * for_about[4] / (int)percent, m_height * for_about[4] / (int)percent,
                                    m_width * for_about[6] / (int)percent, m_height * for_about[7] / (int)percent),
                      QString("This program demonstrates\n""work of Prim's and  \n""Kruskal's algorithms. \n"
                              "These algorithms find \n""MINIMAL SPANNING TREE \n""(MST) in the connected, \n"
                              "weighted, undirected graph.\n""In this program \n""those vertices and \n"
                              "edges which have already being \n""in the MST\n""marked green,\n"
                              "which are considering\n""in this moment \n""marked yellow, \n"
                              "and the rest in the black.\n""If you want to read more \n""about MST and algorithms \n"
                              "press follow button. \n\n"));
    font.setItalic(true);
    font.setUnderline(true);
    painter.setFont(font);
    painter.drawText(boundingRect(m_width * for_about[4] / (int)percent,m_height * for_about[9] / (int)percent,
                                  m_width*for_about[6] / (int)percent,m_height * for_about[8] / (int)percent),
                     QString("Created by Mher Hakobyan"));
}

void about_window::back_slot()
{
    this->m_parent->showFullScreen();
    this->close();
}

void about_window::more_slot()
{
    QString path = m_app_path + for_paths[0] + for_paths[4];
    QFile file(path);
    if (file.exists())
        QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}
