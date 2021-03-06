//
// Copyright 2015 - 2016 (C). Alex Robenko. All rights reserved.
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

/// @file
/// @brief Contains definition of LOG-FINDTIME message and its fields.

#pragma once

#include "ublox/Message.h"
#include "ublox/field/common.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the LOG-FINDTIME message fields.
/// @see LogFindtime
struct LogFindtimeFields
{
    /// @brief Definition of "version" field.
    using version =
        field::common::U1T<
            comms::option::DefaultNumValue<1>,
            comms::option::ValidNumValueRange<1, 1>
        >;

    /// @brief Definition of "type" field.
    using type  =
        field::common::U1T<
            comms::option::DefaultNumValue<1>,
            comms::option::ValidNumValueRange<1, 1>
        >;

    /// @brief Definition of "reserved1" field.
    using reserved1 = field::common::res2;

    /// @brief Definition of "entryNumber" field.
    using entryNumber  = field::common::U4;

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        version,
        type,
        reserved1,
        entryNumber
    >;
};

/// @brief Definition of LOG-FINDTIME message
/// @details Inherits from
///     <a href="https://dl.dropboxusercontent.com/u/46999418/comms_champion/comms/html/classcomms_1_1MessageBase.html">comms::MessageBase</a>
///     while providing @b TMsgBase as common interface class as well as
///     @b comms::option::StaticNumIdImpl, @b comms::option::FieldsImpl, and
///     @b comms::option::DispatchImpl as options. @n
///     See @ref LogFindtimeFields and for definition of the fields this message contains.
/// @tparam TMsgBase Common interface class for all the messages.
template <typename TMsgBase = Message>
class LogFindtime : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_LOG_FINDTIME>,
        comms::option::FieldsImpl<LogFindtimeFields::All>,
        comms::option::DispatchImpl<LogFindtime<TMsgBase> >
    >
{
    typedef comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_LOG_FINDTIME>,
        comms::option::FieldsImpl<LogFindtimeFields::All>,
        comms::option::DispatchImpl<LogFindtime<TMsgBase> >
    > Base;
public:

    /// @brief Index to access the fields
    enum FieldIdx
    {
        FieldIdx_version, ///< @b version field, see @ref LogFindtimeFields::version
        FieldIdx_type, ///< @b type field, see @ref LogFindtimeFields::type
        FieldIdx_reserved1, ///< @b reserved1 field, see @ref LogFindtimeFields::reserved1
        FieldIdx_entryNumber, ///< @b entryNumber field, see @ref LogFindtimeFields::entryNumber
        FieldIdx_numOfValues ///< number of available fields
    };

    static_assert(std::tuple_size<typename Base::AllFields>::value == FieldIdx_numOfValues,
        "Number of fields is incorrect");

    /// @brief Default constructor
    LogFindtime() = default;

    /// @brief Copy constructor
    LogFindtime(const LogFindtime&) = default;

    /// @brief Move constructor
    LogFindtime(LogFindtime&& other) = default;

    /// @brief Destructor
    virtual ~LogFindtime() = default;

    /// @brief Copy assignment
    LogFindtime& operator=(const LogFindtime&) = default;

    /// @brief Move assignment
    LogFindtime& operator=(LogFindtime&&) = default;

protected:

    /// @brief Overrides read functionality provided by the base class.
    /// @details The function performs read up to the @b type field (@ref
    /// LogFindtimeFields::type) and checks its value. If it's valid (has value 1),
    /// the read continues for the rest of the fields. Otherwise
    /// comms::ErrorStatus::InvalidMsgData is returned.
    virtual comms::ErrorStatus readImpl(
        typename Base::ReadIterator& iter,
        std::size_t len) override
    {
        auto es = Base::template readFieldsUntil<FieldIdx_reserved1>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        auto& allFields = Base::fields();
        auto& typeField = std::get<FieldIdx_type>(allFields);
        if (!typeField.valid()) {
            return comms::ErrorStatus::InvalidMsgData;
        }

        return Base::template readFieldsFrom<FieldIdx_reserved1>(iter, len);
    }
};


}  // namespace message

}  // namespace ublox

