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
/// @brief Contains definition of CFG-PRT (@b USB) message and its fields.

#pragma once

#include "ublox/Message.h"
#include "CfgPrt.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the CFG-PRT (@b USB) message fields.
/// @see CfgPrtUsb
struct CfgPrtUsbFields : public CfgPrtFields
{
    /// @brief Definition of "portID" field.
    using portID =
        field::common::EnumT<
            PortId,
            comms::option::ValidNumValueRange<(int)PortId::USB, (int)PortId::USB>,
            comms::option::DefaultNumValue<(int)PortId::USB>
        >;

    /// @brief Definition of "reserved2" field
    using reserved2 = field::common::res4;

    /// @brief Definition of "reserved4" field
    using reserved4 = field::common::res2;

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        portID,
        reserved0,
        txReady,
        reserved2,
        reserved3,
        inProtoMask,
        outProtoMask,
        reserved4,
        reserved5
    >;
};

/// @brief Definition of CFG-PRT (@b USB) message
/// @details Inherits from
///     <a href="https://dl.dropboxusercontent.com/u/46999418/comms_champion/comms/html/classcomms_1_1MessageBase.html">comms::MessageBase</a>
///     while providing @b TMsgBase as common interface class as well as
///     @b comms::option::StaticNumIdImpl, @b comms::option::FieldsImpl, and
///     @b comms::option::DispatchImpl as options. @n
///     See @ref CfgPrtUsbFields and for definition of the fields this message contains.
/// @tparam TMsgBase Common interface class for all the messages.
template <typename TMsgBase = Message>
class CfgPrtUsb : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_PRT>,
        comms::option::FieldsImpl<CfgPrtUsbFields::All>,
        comms::option::DispatchImpl<CfgPrtUsb<TMsgBase> >
    >
{
    typedef comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_PRT>,
        comms::option::FieldsImpl<CfgPrtUsbFields::All>,
        comms::option::DispatchImpl<CfgPrtUsb<TMsgBase> >
    > Base;
public:

    /// @brief Index to access the fields
    enum FieldIdx
    {
        FieldIdx_portID, ///< @b portID field, see @ref CfgPrtUsbFields::portID
        FieldIdx_reserved0, ///< @b reserved0 field, see @ref CfgPrtUsbFields::reserved0
        FieldIdx_txReady, ///< @b txReady field, see @ref CfgPrtUsbFields::txReady
        FieldIdx_reserved2, ///< @b reserved2 field, see @ref CfgPrtUsbFields::reserved2
        FieldIdx_reserved3, ///< @b reserved3 field, see @ref CfgPrtUsbFields::reserved3
        FieldIdx_inProtoMask, ///< @b inProtoMask field, see @ref CfgPrtUsbFields::inProtoMask
        FieldIdx_outProtoMask, ///< @b outProtoMask field, see @ref CfgPrtUsbFields::outProtoMask
        FieldIdx_reserved4, ///< @b reserved4 field, see @ref CfgPrtUsbFields::reserved4
        FieldIdx_reserved5, ///< @b reserved5 field, see @ref CfgPrtUsbFields::reserved5
        FieldIdx_numOfValues ///< number of available fields
    };

    static_assert(std::tuple_size<typename Base::AllFields>::value == FieldIdx_numOfValues,
        "Number of fields is incorrect");

    /// @brief Default constructor
    CfgPrtUsb() = default;

    /// @brief Copy constructor
    CfgPrtUsb(const CfgPrtUsb&) = default;

    /// @brief Move constructor
    CfgPrtUsb(CfgPrtUsb&& other) = default;

    /// @brief Destructor
    virtual ~CfgPrtUsb() = default;

    /// @brief Copy assignment
    CfgPrtUsb& operator=(const CfgPrtUsb&) = default;

    /// @brief Move assignment
    CfgPrtUsb& operator=(CfgPrtUsb&&) = default;

protected:
    /// @brief Overrides read functionality provided by the base class.
    /// @details Reads only first "portID" field (@ref CfgPrtUsbFields::portID) and
    ///     checks its value. If the value is @b NOT CfgPrtUsbFields::PortId::USB,
    ///     the read operation fails with comms::ErrorStatus::InvalidMsgData error
    ///     status. Otherwise the read operation continues as expected.
    virtual comms::ErrorStatus readImpl(
        typename Base::ReadIterator& iter,
        std::size_t len) override
    {
        auto es = Base::template readFieldsUntil<FieldIdx_reserved0>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        auto& allFields = Base::fields();
        auto& portIdField = std::get<FieldIdx_portID>(allFields);
        if (portIdField.value() != CfgPrtUsbFields::PortId::USB) {
            return comms::ErrorStatus::InvalidMsgData;
        }

        return Base::template readFieldsFrom<FieldIdx_reserved0>(iter, len);
    }

    /// @brief Overrides default refreshing functionality provided by the interface class.
    /// @details This function makes sure that the value of the
    ///     "portID" field (@ref CfgPrtUsbFields::portID) remains CfgPrtUsbFields::PortId::USB.
    /// @return @b true in case the "portID" field was modified, @b false otherwise
    virtual bool refreshImpl() override
    {
        auto& allFields = Base::fields();
        auto& portIdField = std::get<FieldIdx_portID>(allFields);
        if (portIdField.value() == CfgPrtUsbFields::PortId::USB) {
            return false;
        }

        portIdField.value() = CfgPrtUsbFields::PortId::USB;
        return true;
    }

};


}  // namespace message

}  // namespace ublox





