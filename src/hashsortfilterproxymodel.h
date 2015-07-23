#ifndef HASHSORTFILTERPROXYMODEL_H
#define HASHSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QList>

class HashSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    HashSortFilterProxyModel(QObject *parent = 0);
    void setFilteredColumns(const QList<int> &index);
    QList<int> filteredColumns();

public slots:
    void setShowCheckedRowsOnly(bool showCheckedOnly);
    void checkBoxHasChanged();

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const Q_DECL_OVERRIDE;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const Q_DECL_OVERRIDE;

private:
    QList<int> m_filteredColumns;
    bool       m_showCheckedRowsOnly;
};
#endif // HASHSORTFILTERPROXYMODEL_H
