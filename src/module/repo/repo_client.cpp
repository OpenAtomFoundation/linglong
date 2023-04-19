/*
 * SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.
 *
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#include "repo_client.h"

#include "module/package/package.h"
#include "module/util/config/config.h"
#include "module/util/http/http_client.h"
#include "module/util/qserializer/deprecated.h"

#include <QJsonObject>

namespace linglong {
namespace repo {

QSERIALIZER_IMPL(Response);

std::tuple<util::Error, QList<QSharedPointer<package::AppMetaInfo>>>
RepoClient::QueryApps(const package::Ref &ref)
{
    // TODO: query cache Here
    QUrl url(ConfigInstance().repos[package::kDefaultRepo]->endpoint);
    // FIXME: normalize the path
    url.setPath(url.path() + "/api/v0/apps/fuzzysearchapp");
    QNetworkRequest request(url);

    QJsonObject obj;
    obj["AppId"] = ref.appId;
    obj["version"] = ref.version;
    obj["arch"] = ref.arch;
    obj["repoName"] = ref.repo;

    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();

    util::HttpRestClient hc;
    auto reply = hc.post(request, data);
    data = reply->readAll();
    auto resp = util::loadJsonBytes<repo::Response>(data);

    return { Success(), (resp->data) };
}

} // namespace repo
} // namespace linglong
