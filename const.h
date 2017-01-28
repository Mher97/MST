#ifndef CONST_H
#define CONST_H

#include <QtCore>
#include <algorithm>
#include <vector>
using namespace std;

/*constants  are designated for widgets and graphic items geometry,
 *  source paths and etc*/

const int n = 8;      //count of vertices
const int m = 12;     //count of edges

//defined colors and program states
const int _BLACK = 1;
const int _YELLOW = 2;
const int _GREEN = 3;
const int PRIM = 1;
const int KRUSKAL = 2;

//defined variables
const qreal real_zero = 0.0;
const qreal _two = 2.0;
const qreal _ten = 10.0;
const qreal _eight = 8.0;
const qreal percent = 100;

//edges of demo graph
const vector<pair<pair<int,int>,int> > for_edges{make_pair(make_pair(0,6),51), make_pair(make_pair(0,1),32),
                                                 make_pair(make_pair(0,2),29), make_pair(make_pair(0,5),60),
                                                 make_pair(make_pair(0,7),31), make_pair(make_pair(1,7),21),
                                                 make_pair(make_pair(3,4),34), make_pair(make_pair(3,5),18),
                                                 make_pair(make_pair(4,7),46), make_pair(make_pair(4,5),40),
                                                 make_pair(make_pair(4,6),51), make_pair(make_pair(6,7),25)};
//variables for geometry and  source paths
const pair<qreal,qreal> for_view = make_pair(100,86);
const qreal for_scene_size = 99.6;
const qreal for_radius = 1.83;
const qreal for_font = 3.3;

const pair<qreal,qreal> for_texts_x(make_pair(10,36));
const qreal for_texts_y=1.2;

const pair<int,int> for_message = make_pair(20,27);
const pair<int,int> for_message1 = make_pair(40,36);
const pair<pair<int,int>,int > for_pause(make_pair(make_pair(96,93),3));

const vector<pair<qreal,qreal> > for_vertices{make_pair(7.3,19.1), make_pair(18,52), make_pair(25,15), make_pair(20,72),
                                              make_pair(36,85), make_pair(7.3,85), make_pair(42,26), make_pair(27,45)};

const vector<pair<qreal,qreal> > for_edges_weights{make_pair(30,18), make_pair(10,35), make_pair(13,13),
                                                   make_pair(3,47),  make_pair(17,26), make_pair(20,40),
                                                   make_pair(28,66), make_pair(12,65), make_pair(31,54),
                                                   make_pair(20,78), make_pair(41,50), make_pair(30,30)};

const vector<qreal> for_buttons{6.1, 24.4, 42.7, 61, 79.4, 88.7, 14.6, 9.1};

const vector<pair<qreal,qreal>> for_sound{make_pair(96,88), make_pair(3,3), make_pair(95,78), make_pair(4.5,10)};

const vector<pair<qreal,qreal> > for_MST_vertices{make_pair(72,15), make_pair(72,50), make_pair(61,30), make_pair(92,70),
                                     make_pair(92,50), make_pair(92,90), make_pair(82,50), make_pair(82,30)};

const vector<QString> for_paths{"/resources", "/USSR.wav", "/sound.png", "/about.jpg", "/mst.html", "/pause.png", "/restart.png"};

const vector<int> for_about{1724, 990, 92, 6, 2, 15, 40, 80, 10, 88};
const qreal for_about_font = 1.5;

#endif // CONST_H


