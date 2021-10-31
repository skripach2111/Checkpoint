#ifndef MODELFORCOMBOBOX_H
#define MODELFORCOMBOBOX_H

#include <QAbstractTableModel>
#include <QObject>

class ModelForComboBox : public QAbstractTableModel
{
    Q_OBJECT

    QString startText;
public:
    explicit ModelForComboBox(QObject *parent = nullptr);

    void setSourceModel(QAbstractTableModel *model) { sourceModel = model; }
    void setStartText(QString text) { startText = text; }


private:
    QAbstractTableModel *sourceModel;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // MODELFORCOMBOBOX_H
