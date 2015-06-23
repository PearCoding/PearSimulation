#pragma once

#include <QTreeWidget>

class PropertyTable;
class PropertyView : public QTreeWidget
{
	Q_OBJECT
public:
	explicit PropertyView(QWidget* parent = nullptr);
	virtual ~PropertyView();

	void setPropertyTable(PropertyTable* table);
	PropertyTable* propertyTable() const;

public slots:
	void reset();

protected:
	void drawRow(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

private:
	PropertyTable* mProperties;
};
