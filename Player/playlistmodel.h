#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractItemModel>

class PlaylistModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit PlaylistModel(QObject *parent = 0);

signals:

public slots:

};

#endif // PLAYLISTMODEL_H
