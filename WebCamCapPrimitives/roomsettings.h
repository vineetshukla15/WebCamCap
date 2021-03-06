/*
 *
 * Copyright (C) 2015  Miroslav Krajicek (https://github.com/kaajo).
 * All Rights Reserved.
 *
 * This file is part of WebCamCap.
 *
 * WebCamCap is free software: you can redistribute it and/or modify
 * it under the terms of the GNU LGPL version 3 as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * WebCamCap is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU LGPL version 3
 * along with WebCamCap. If not, see <http://www.gnu.org/licenses/lgpl-3.0.txt>.
 *
 */

#ifndef ROOMSETTINGS_H
#define ROOMSETTINGS_H

#include "webcamcapprimitives_global.h"

#include <QVector3D>
#include <QObject>

/**
 * @author Miroslav Krajicek
 * @brief The RoomSettings class contains all settings for class #IVirtualRoom and its derivatives
 */
class WEBCAMCAPPRIMITIVESSHARED_EXPORT RoomSettings : public QObject
{
    Q_OBJECT

    QString m_name = "Default project";
    QVector3D m_roomDimensions;
    double m_maxError;

    bool m_recordScene = false;
    bool m_recordAnimation = false;
    bool m_saved = false;

public:

    /**
     * @brief The RoomSettingsType enum used mainly in changed(RoomSettings::RoomSettingsType)
     */
    enum class RoomSettingsType {
        ALL,
        NAME,
        DIMENSIONS,
        MAXERROR,
        RECORD,
        RECORDANIMATION
    };

    explicit RoomSettings(QObject *parent = 0);

    QVariantMap toVariantMap();
    bool fromVariantMap(QVariantMap map);

    QString name() const;
    void setName(const QString &name);

    QVector3D roomDimensions() const;
    void setRoomDimensions(const QVector3D &roomDimensions);

    double maxError() const;
    void setMaxError(double maxError);

    bool recordScene() const;
    bool recordAnimation() const;

    bool saved() const;
    void save();

public slots:
    /**
     * @brief setRecordScene
     * @param recordScene
     */
    void setRecordScene(bool recordScene);
    /**
     * @brief setRecordAnimation
     * @param recordAnimation
     */
    void setRecordAnimation(bool recordAnimation);

signals:
    /**
     * @brief SIGNAL for indicating changed property
     * @param type type of changed settings
     */
    void changed(RoomSettings::RoomSettingsType type);

private slots:
    void setSave(RoomSettings::RoomSettingsType type);

};

#endif // ROOMSETTINGS_H
