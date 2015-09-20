//
// Copyright 2015 (C). Alex Robenko. All rights reserved.
//

// This file is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <cassert>

#include "MonVer.h"
#include "cc_plugin/field/common.h"

template class ublox::message::MonVer<ublox::cc_plugin::Message>;
template class ublox::cc_plugin::ProtocolMessageBase<
    ublox::message::MonVer<ublox::cc_plugin::Message>,
    ublox::cc_plugin::message::MonVer>;

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

QVariantMap createProps_extensions()
{
    QVariantMap elemProps = cc::Property::createPropertiesMap(QString());
    auto props = cc::Property::createPropertiesMap("extensions", std::move(elemProps));
    cc::Property::setSerialisedHidden(props);
    return props;
}

QVariantList createFieldsProperties()
{
    QVariantList props;
    props.append(cc::Property::createPropertiesMap("swVersion"));
    props.append(cc::Property::createPropertiesMap("hwVersion"));
    props.append(createProps_extensions());

    assert(props.size() == MonVer::FieldIdx_numOfValues);
    return props;
}

}  // namespace

MonVer::MonVer() = default;
MonVer::~MonVer() = default;

MonVer& MonVer::operator=(const MonVer&) = default;
MonVer& MonVer::operator=(MonVer&&) = default;

const char* MonVer::nameImpl() const
{
    static const char* Str = "MON-VER";
    return Str;
}

const QVariantList& MonVer::fieldsPropertiesImpl() const
{
    static const auto Props = createFieldsProperties();
    return Props;
}

}  // namespace message

}  // namespace cc_plugin

}  // namespace ublox

