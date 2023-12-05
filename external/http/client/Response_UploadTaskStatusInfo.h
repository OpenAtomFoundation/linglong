/**
 * linglong仓库
 * 玲珑仓库接口
 *
 * The version of the OpenAPI document: 1.0.0
 * Contact: wurongjie@deepin.org
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

/*
 * Response_UploadTaskStatusInfo.h
 *
 * 
 */

#ifndef Response_UploadTaskStatusInfo_H
#define Response_UploadTaskStatusInfo_H

#include <QJsonObject>

#include <QString>

#include "Enum.h"
#include "Object.h"

namespace linglong {
namespace api {
namespace client {

class Response_UploadTaskStatusInfo : public Object {
public:
    Response_UploadTaskStatusInfo();
    Response_UploadTaskStatusInfo(QString json);
    ~Response_UploadTaskStatusInfo() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getStatus() const;
    void setStatus(const QString &status);
    bool is_status_Set() const;
    bool is_status_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString m_status;
    bool m_status_isSet;
    bool m_status_isValid;
};

} // namespace linglong
} // namespace api
} // namespace client

Q_DECLARE_METATYPE(linglong::api::client::Response_UploadTaskStatusInfo)

#endif // Response_UploadTaskStatusInfo_H
