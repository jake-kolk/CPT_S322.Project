/**
 * @file        search.h
 * @brief       define abstact class search
 * @author      Jacob Kolk
 * @date        2025-3-7
 */

#ifndef SEARCH_H
#define SEARCH_H

#include <QNetworkAccessManager>

class search : public QObject
{
    Q_OBJECT

protected:
    QString ApiKey;
    QNetworkAccessManager* manager;
public:
    explicit search(QString inApiKey) // Constructor declaration
    {
        // Initialize manager
        this->manager = new QNetworkAccessManager(this);
        this->ApiKey = inApiKey;
    }
    virtual ~search() { // Virtual destructor
        delete manager;
    }
};
#endif // SEARCH_H
