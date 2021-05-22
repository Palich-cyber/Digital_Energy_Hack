#ifndef MATERIALLIBRARY_H
#define MATERIALLIBRARY_H

#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>

#include "materials.h"

class MaterialLibrary
{
public:
    MaterialLibrary();
    void addMaterial(Materials *materialValue);
    Materials *getMaterial(const quint32 &indexValue);
    Materials *getMaterial(const QString &materialNameValue);
    quint32 getCountMaterials();
    void loadMaterialsFromFile(const QString &pathToFileValue);

private:
    QVector <Materials *> materialList;

private:
    void clearMaterials();
};

#endif // MATERIALLIBRARY_H
