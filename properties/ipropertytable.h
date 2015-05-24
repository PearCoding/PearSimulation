#ifndef IPROPERTYTABLE_H
#define IPROPERTYTABLE_H

#include <QVariant>
#include <QString>
#include <QMap>

struct PropertyDefinition
{
    QString ParentKey;
};

struct ActionDefinition
{
    QString ParentKey;
};

class IPropertyTable : QObject
{
    Q_OBJECT
public:
    IPropertyTable();
    ~IPropertyTable();

    void add(const QString& key, const QVariant& value, const PropertyDefinition& def);
    void addAction(const ActionDefinition& def);

    void setValue(const QString& key, const QVariant& value);
    QVariant value(const QString& key) const;

    void setPropertyDefinition(const QString& key, const PropertyDefinition& def);
    PropertyDefinition propertyDefinition(const QString& key) const;

signals:
    void propertyChanged(const QString& key, const QVariant& value);
    void actionToggled();

private:
    QMap<QString, QVariant> mProperties;
    QMap<QString, PropertyDefinition> mDefinitions;
    QList<ActionDefinition> mActions;
};

#endif // IPROPERTYTABLE_H
