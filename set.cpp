#include "set.h"

Set::Set()
{

}

Set::Set(QStringList data)
{
    m_elements = data;
}

QString Set::GetElements() const
{
   return m_elements.join(", ");
}

void Set::SetElements(QString data)
{
    m_elements = data.split(", ");
}

void Set::AddElement(QString elem)
{
    m_elements.append(elem);
}

void Set::sort()
{
    m_elements.sort();
}

void Set::clear()
{
    m_elements.clear();
}

Set Set::Union(const Set &s)
{
    QStringList res = m_elements + s.m_elements;
    res.removeDuplicates();;
    return Set(res);

}

Set Set::Intersect(const Set &s)
{
    QString sData = s.GetElements();
    Set res;
    for(QString &elem : m_elements)
    {
        if (sData.indexOf(elem) != -1)
        {
            res.AddElement(elem);
        }
    }

    return res;
}

Set Set::Diff(const Set &s)
{
    QString sData = s.GetElements();
    Set res;
    for(QString &elem : m_elements)
    {
        if (sData.indexOf(elem) == -1)
        {
            res.AddElement(elem);
        }
    }

    return res;
}

Set Set::SimDif(const Set &s)
{
    QString sData = s.GetElements();
    Set res;
    for(const QString &elem : m_elements)
    {
        if (sData.indexOf(elem) == -1)
        {
            res.AddElement(elem);
        }
    }

    for(const QString &elem : s.m_elements)
    {
        if(m_elements.indexOf(elem) == -1)
        {
            res.AddElement(elem);
        }
    }

    return res;
}

void Set::Invert()
{
    QStringList res;
    for(const QString &elem : universum)
    {
        if (m_elements.indexOf(elem) == -1)
        {
            res.append(elem);
        }
    }

    m_elements = res;
}



Set &Set::operator=(Set s)
{
    m_elements = s.m_elements;
    return *this;
}

void Set::SetUniversum(QString univ)
{
    universum = univ.split(", ");
}

void Set::SortUniversum()
{
    universum.sort();
}

void Set::SetDefUniversum()
{
    universum = defUniversum;

}

void Set::ClearUniversum()
{
    universum.clear();
}

QString Set::GetUnivStr()
{
    return universum.join(", ");
}

QStringList Set::defUniversum(QString("0 1 2 3 4 5 6 7 8 9").split(" "));
QStringList Set::universum;
