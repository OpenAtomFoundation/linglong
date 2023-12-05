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

#include "Schema_NewUploadTaskReq.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "Helpers.h"

namespace linglong {
namespace api {
namespace client {

Schema_NewUploadTaskReq::Schema_NewUploadTaskReq(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

Schema_NewUploadTaskReq::Schema_NewUploadTaskReq() {
    this->initializeModel();
}

Schema_NewUploadTaskReq::~Schema_NewUploadTaskReq() {}

void Schema_NewUploadTaskReq::initializeModel() {

    m_ref_isSet = false;
    m_ref_isValid = false;

    m_repo_name_isSet = false;
    m_repo_name_isValid = false;
}

void Schema_NewUploadTaskReq::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void Schema_NewUploadTaskReq::fromJsonObject(QJsonObject json) {

    m_ref_isValid = ::linglong::api::client::fromJsonValue(m_ref, json[QString("ref")]);
    m_ref_isSet = !json[QString("ref")].isNull() && m_ref_isValid;

    m_repo_name_isValid = ::linglong::api::client::fromJsonValue(m_repo_name, json[QString("repoName")]);
    m_repo_name_isSet = !json[QString("repoName")].isNull() && m_repo_name_isValid;
}

QString Schema_NewUploadTaskReq::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject Schema_NewUploadTaskReq::asJsonObject() const {
    QJsonObject obj;
    if (m_ref_isSet) {
        obj.insert(QString("ref"), ::linglong::api::client::toJsonValue(m_ref));
    }
    if (m_repo_name_isSet) {
        obj.insert(QString("repoName"), ::linglong::api::client::toJsonValue(m_repo_name));
    }
    return obj;
}

QString Schema_NewUploadTaskReq::getRef() const {
    return m_ref;
}
void Schema_NewUploadTaskReq::setRef(const QString &ref) {
    m_ref = ref;
    m_ref_isSet = true;
}

bool Schema_NewUploadTaskReq::is_ref_Set() const{
    return m_ref_isSet;
}

bool Schema_NewUploadTaskReq::is_ref_Valid() const{
    return m_ref_isValid;
}

QString Schema_NewUploadTaskReq::getRepoName() const {
    return m_repo_name;
}
void Schema_NewUploadTaskReq::setRepoName(const QString &repo_name) {
    m_repo_name = repo_name;
    m_repo_name_isSet = true;
}

bool Schema_NewUploadTaskReq::is_repo_name_Set() const{
    return m_repo_name_isSet;
}

bool Schema_NewUploadTaskReq::is_repo_name_Valid() const{
    return m_repo_name_isValid;
}

bool Schema_NewUploadTaskReq::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_ref_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_repo_name_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool Schema_NewUploadTaskReq::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace linglong
} // namespace api
} // namespace client
