#ifndef SET_H
#define SET_H

#include<QStringList>

class Set
{
public:
    Set();
    Set(QStringList data);

    QString GetElements() const;
    void SetElements(QString data);
    void AddElement(QString elem);

    void sort();
    void clear();

    Set Union(const Set& s);
    Set Intersect(const Set& s);
    Set Diff(const Set& s);
    Set SimDif(const Set& s);
    void Invert();

    Set &operator=(Set s);

    static void SetUniversum(QString univ);
    static void SortUniversum();
    static void SetDefUniversum();
    static void ClearUniversum();
    static QString GetUnivStr();

    static QStringList universum;
    static QStringList defUniversum;

private:
    QStringList m_elements;

};


#endif // SET_H
