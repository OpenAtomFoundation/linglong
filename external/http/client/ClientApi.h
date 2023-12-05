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

#ifndef _ClientApi_H
#define _ClientApi_H

#include "Helpers.h"
#include "HttpRequest.h"
#include "ServerConfiguration.h"
#include "Oauth.h"

#include "FuzzySearchApp_200_response.h"
#include "GetRepo_200_response.h"
#include "HttpFileElement.h"
#include "NewUploadTaskID_200_response.h"
#include "Request_FuzzySearchReq.h"
#include "Schema_NewUploadTaskReq.h"
#include "UploadTaskFile_200_response.h"
#include "UploadTaskInfo_200_response.h"
#include <QString>

#include <QObject>
#include <QByteArray>
#include <QStringList>
#include <QList>
#include <QNetworkAccessManager>

namespace linglong {
namespace api {
namespace client {

class ClientApi : public QObject {
    Q_OBJECT

public:
    ClientApi(const int timeOut = 0);
    ~ClientApi();

    void initializeServerConfigs();
    int setDefaultServerValue(int serverIndex,const QString &operation, const QString &variable,const QString &val);
    void setServerIndex(const QString &operation, int serverIndex);
    void setApiKey(const QString &apiKeyName, const QString &apiKey);
    void setBearerToken(const QString &token);
    void setUsername(const QString &username);
    void setPassword(const QString &password);
    void setTimeOut(const int timeOut);
    void setWorkingDirectory(const QString &path);
    void setNetworkAccessManager(QNetworkAccessManager* manager);
    int addServerConfiguration(const QString &operation, const QUrl &url, const QString &description = "", const QMap<QString, ServerVariable> &variables = QMap<QString, ServerVariable>());
    void setNewServerForAllOperations(const QUrl &url, const QString &description = "", const QMap<QString, ServerVariable> &variables =  QMap<QString, ServerVariable>());
    void setNewServer(const QString &operation, const QUrl &url, const QString &description = "", const QMap<QString, ServerVariable> &variables =  QMap<QString, ServerVariable>());
    void addHeaders(const QString &key, const QString &value);
    void enableRequestCompression();
    void enableResponseCompression();
    void abortRequests();
    QString getParamStylePrefix(const QString &style);
    QString getParamStyleSuffix(const QString &style);
    QString getParamStyleDelimiter(const QString &style, const QString &name, bool isExplode);

    /**
    * @param[in]  data Request_FuzzySearchReq [required]
    */
    void fuzzySearchApp(const Request_FuzzySearchReq &data);

    /**
    * @param[in]  repo QString [required]
    */
    void getRepo(const QString &repo);

    /**
    * @param[in]  x_token QString [required]
    * @param[in]  req Schema_NewUploadTaskReq [required]
    */
    void newUploadTaskID(const QString &x_token, const Schema_NewUploadTaskReq &req);

    /**
    * @param[in]  x_token QString [required]
    * @param[in]  task_id QString [required]
    * @param[in]  file HttpFileElement [required]
    */
    void uploadTaskFile(const QString &x_token, const QString &task_id, const HttpFileElement &file);

    /**
    * @param[in]  x_token QString [required]
    * @param[in]  task_id QString [required]
    */
    void uploadTaskInfo(const QString &x_token, const QString &task_id);


private:
    QMap<QString,int> _serverIndices;
    QMap<QString,QList<ServerConfiguration>> _serverConfigs;
    QMap<QString, QString> _apiKeys;
    QString _bearerToken;
    QString _username;
    QString _password;
    int _timeOut;
    QString _workingDirectory;
    QNetworkAccessManager* _manager;
    QMap<QString, QString> _defaultHeaders;
    bool _isResponseCompressionEnabled;
    bool _isRequestCompressionEnabled;
    HttpRequestInput _latestInput;
    HttpRequestWorker *_latestWorker;
    QStringList _latestScope;
    OauthCode _authFlow;
    OauthImplicit _implicitFlow;
    OauthCredentials _credentialFlow;
    OauthPassword _passwordFlow;
    int _OauthMethod = 0;

    void fuzzySearchAppCallback(HttpRequestWorker *worker);
    void getRepoCallback(HttpRequestWorker *worker);
    void newUploadTaskIDCallback(HttpRequestWorker *worker);
    void uploadTaskFileCallback(HttpRequestWorker *worker);
    void uploadTaskInfoCallback(HttpRequestWorker *worker);

Q_SIGNALS:

    void fuzzySearchAppSignal(FuzzySearchApp_200_response summary);
    void getRepoSignal(GetRepo_200_response summary);
    void newUploadTaskIDSignal(NewUploadTaskID_200_response summary);
    void uploadTaskFileSignal(UploadTaskFile_200_response summary);
    void uploadTaskInfoSignal(UploadTaskInfo_200_response summary);

    void fuzzySearchAppSignalFull(HttpRequestWorker *worker, FuzzySearchApp_200_response summary);
    void getRepoSignalFull(HttpRequestWorker *worker, GetRepo_200_response summary);
    void newUploadTaskIDSignalFull(HttpRequestWorker *worker, NewUploadTaskID_200_response summary);
    void uploadTaskFileSignalFull(HttpRequestWorker *worker, UploadTaskFile_200_response summary);
    void uploadTaskInfoSignalFull(HttpRequestWorker *worker, UploadTaskInfo_200_response summary);

    void fuzzySearchAppSignalE(FuzzySearchApp_200_response summary, QNetworkReply::NetworkError error_type, QString error_str);
    void getRepoSignalE(GetRepo_200_response summary, QNetworkReply::NetworkError error_type, QString error_str);
    void newUploadTaskIDSignalE(NewUploadTaskID_200_response summary, QNetworkReply::NetworkError error_type, QString error_str);
    void uploadTaskFileSignalE(UploadTaskFile_200_response summary, QNetworkReply::NetworkError error_type, QString error_str);
    void uploadTaskInfoSignalE(UploadTaskInfo_200_response summary, QNetworkReply::NetworkError error_type, QString error_str);

    void fuzzySearchAppSignalEFull(HttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void getRepoSignalEFull(HttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void newUploadTaskIDSignalEFull(HttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void uploadTaskFileSignalEFull(HttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void uploadTaskInfoSignalEFull(HttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);

    void abortRequestsSignal();
    void allPendingRequestsCompleted();

public Q_SLOTS:
    void tokenAvailable();
    
};

} // namespace linglong
} // namespace api
} // namespace client
#endif
