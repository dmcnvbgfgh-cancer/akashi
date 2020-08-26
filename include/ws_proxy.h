//////////////////////////////////////////////////////////////////////////////////////
//    akashi - a server for Attorney Online 2                                       //
//    Copyright (C) 2020  scatterflower                                             //
//                                                                                  //
//    This program is free software: you can redistribute it and/or modify          //
//    it under the terms of the GNU Affero General Public License as                //
//    published by the Free Software Foundation, either version 3 of the            //
//    License, or (at your option) any later version.                               //
//                                                                                  //
//    This program is distributed in the hope that it will be useful,               //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of                //
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                 //
//    GNU Affero General Public License for more details.                           //
//                                                                                  //
//    You should have received a copy of the GNU Affero General Public License      //
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.        //
//////////////////////////////////////////////////////////////////////////////////////
#ifndef WS_PROXY_H
#define WS_PROXY_H

#include <QMap>
#include <QTcpSocket>
#include <QtWebSockets/QtWebSockets>

class WSProxy : public QObject {
    Q_OBJECT
  public:
    WSProxy(QObject* parent);

  public slots:
    void wsConnected();

  private:
    QWebSocketServer* server;
    QMap<QWebSocket*, QTcpSocket*> tcp_sockets;
    QMap<QTcpSocket*, QWebSocket*> web_sockets;
};

#endif // WS_PROXY_H
