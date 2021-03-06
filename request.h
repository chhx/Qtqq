#pragma once

#include <QString>
#include <QByteArray>

#include "cookie.h"

enum RequestModes { kPost, kGet };

class Request
{
public:
    Request();
    ~Request();

public:
    void addHeaderItem(QString key, QString value);
    void addRequestContent(QByteArray content);
    void create(RequestModes mode, QString url);
    void setCookie(const Cookie& cookie);

    QByteArray toByteArray();

private:
    void addDefaultHeader();
    void clear();

private:
    QByteArray req_str_; //The real request String;
    bool has_content_;
};
