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
/// @brief Contains definition of CFG-NMEA (@b extended) message and its fields.

#pragma once

#include "ublox/Message.h"
#include "ublox/field/common.h"
#include "CfgNmea.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the CFG-NMEA (@b extended) message fields.
/// @see CfgNmeaExt
struct CfgNmeaExtFields : public CfgNmeaFields
{
    /// @brief Bits access enumeration for @ref gnssToFilter bitmask field.
    enum
    {
        gnssToFilter_gps, ///< @b gps bit index
        gnssToFilter_sbas, ///< @b sbas bit index
        gnssToFilter_qzss = 4, ///< @b qzss bit index
        gnssToFilter_glonass, ///< @b glonass bit index
        gnssToFilter_numOfValues ///< upper limit for available bits
    };

    /// @brief Value enumeration for @ref svNumbering field.
    enum class SvNumbering : std::uint8_t
    {
        Strict, ///< strict
        Extended, ///< extended
        NumOfValues ///< number of available values
    };

    /// @brief Value enumeration for @ref mainTalkerId field.
    enum class MainTalkerId : std::uint8_t
    {
        NotOverriden, ///< not overridden
        GP, ///< GP
        GL, ///< GL
        GN, ///< GN
        NumOfValues ///< number of available values
    };

    /// @brief Value enumeration for @ref gsvTalkerId field.
    enum class GsvTalkerId : std::uint8_t
    {
        GnssSpecific, ///<  use GNSS specific talker id
        Main, ///< use main talker id
        NumOfValues ///< number of available values
    };

    /// @brief Definition of "gnssToFilter" field.
    using gnssToFilter =
        field::common::X4T<
            comms::option::BitmaskReservedBits<0xffffffcc, 0>
        >;

    /// @brief Definition of "svNumbering" field.
    using svNumbering =
        field::common::EnumT<
            SvNumbering,
            comms::option::ValidNumValueRange<0, (int)SvNumbering::NumOfValues - 1>
        >;

    /// @brief Definition of "mainTalkerId" field.
    using mainTalkerId =
        field::common::EnumT<
            MainTalkerId,
            comms::option::ValidNumValueRange<0, (int)MainTalkerId::NumOfValues - 1>
        >;

    /// @brief Definition of "gsvTalkerId" field.
    using gsvTalkerId =
        field::common::EnumT<
            GsvTalkerId,
            comms::option::ValidNumValueRange<0, (int)GsvTalkerId::NumOfValues - 1>
        >;

    /// @brief Definition of "reserved" field.
    using reserved = field::common::res1;

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        filter,
        nmeaVersion,
        numSV,
        flags,
        gnssToFilter,
        svNumbering,
        mainTalkerId,
        gsvTalkerId,
        reserved
    >;

};

/// @brief Definition of CFG-NMEA (@b extended) message
/// @details Inherits from
///     <a href="https://dl.dropboxusercontent.com/u/46999418/comms_champion/comms/html/classcomms_1_1MessageBase.html">comms::MessageBase</a>
///     while providing @b TMsgBase as common interface class as well as
///     @b comms::option::StaticNumIdImpl, @b comms::option::FieldsImpl, and
///     @b comms::option::DispatchImpl as options. @n
///     See @ref CfgNmeaExtFields and for definition of the fields this message contains.
/// @tparam TMsgBase Common interface class for all the messages.
template <typename TMsgBase = Message>
class CfgNmeaExt : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_NMEA>,
        comms::option::FieldsImpl<CfgNmeaExtFields::All>,
        comms::option::DispatchImpl<CfgNmeaExt<TMsgBase> >
    >
{
    typedef comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_NMEA>,
        comms::option::FieldsImpl<CfgNmeaExtFields::All>,
        comms::option::DispatchImpl<CfgNmeaExt<TMsgBase> >
    > Base;
public:

    /// @brief Index to access the fields
    enum FieldIdx
    {
        FieldIdx_filter, ///< @b filter field, see @ref CfgNmeaExtFields::filter
        FieldIdx_nmeaVersion, ///< @b nmeaVersion field, see @ref CfgNmeaExtFields::nmeaVersion
        FieldIdx_numSV, ///< @b numSV field, see @ref CfgNmeaExtFields::numSV
        FieldIdx_flags, ///< @b flags field, see @ref CfgNmeaExtFields::flags
        FieldIdx_gnssToFilter, ///< @b gnssToFilter field, see @ref CfgNmeaExtFields::gnssToFilter
        FieldIdx_svNumbering, ///< @b svNumbering field, see @ref CfgNmeaExtFields::svNumbering
        FieldIdx_mainTalkerId, ///< @b mainTalkerId field, see @ref CfgNmeaExtFields::mainTalkerId
        FieldIdx_gsvTalkerId, ///< @b gsvTalkerId field, see @ref CfgNmeaExtFields::gsvTalkerId
        FieldIdx_reserved, ///< @b reserved field, see @ref CfgNmeaExtFields::reserved
        FieldIdx_numOfValues ///< number of available fields
    };

    static_assert(std::tuple_size<typename Base::AllFields>::value == FieldIdx_numOfValues,
        "Number of fields is incorrect");

    /// @brief Default constructor
    CfgNmeaExt() = default;

    /// @brief Copy constructor
    CfgNmeaExt(const CfgNmeaExt&) = default;

    /// @brief Move constructor
    CfgNmeaExt(CfgNmeaExt&& other) = default;

    /// @brief Destructor
    virtual ~CfgNmeaExt() = default;

    /// @brief Copy assignment
    CfgNmeaExt& operator=(const CfgNmeaExt&) = default;

    /// @brief Move assignment
    CfgNmeaExt& operator=(CfgNmeaExt&&) = default;
};


}  // namespace message

}  // namespace ublox

