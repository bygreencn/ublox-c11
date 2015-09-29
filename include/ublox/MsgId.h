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


#pragma once

#include <cstdint>

namespace ublox
{

enum MsgId : std::uint16_t
{
    MsgId_NAV_POSECEF = 0x0101,
    MsgId_NAV_POSLLH = 0x0102,
    MsgId_NAV_STATUS = 0x0103,
    MsgId_NAV_DOP = 0x0104,
    MsgId_NAV_SOL = 0x0106,
    MsgId_NAV_PVT = 0x0107,
    MsgId_NAV_VELECEF = 0x0111,
    MsgId_NAV_VELNED = 0x0112,
    MsgId_NAV_TIMEGPS = 0x0120,
    MsgId_NAV_TIMEUTC = 0x0121,
    MsgId_NAV_CLOCK = 0x0122,
    MsgId_NAV_SVINFO = 0x0130,
    MsgId_NAV_DGPS = 0x0131,
    MsgId_NAV_SBAS = 0x0132,
    MsgId_NAV_EKFSTATUS = 0x0140,
    MsgId_NAV_AOPSTATUS = 0x0160,
    MsgId_RXM_RAW = 0x0210,
    MsgId_RXM_SFRB = 0x0211,
    MsgId_RXM_SVSI = 0x0220,
    MsgId_RXM_ALM = 0x0230,
    MsgId_RXM_EPH = 0x0231,
    MsgId_RXM_PMREQ = 0x0241,
    MsgId_INF_ERROR = 0x0400,
    MsgId_INF_WARNING = 0x0401,
    MsgId_INF_NOTICE = 0x0402,
    MsgId_INF_TEST = 0x0403,
    MsgId_INF_DEBUG = 0x0404,
    MsgId_ACK_NAK = 0x0500,
    MsgId_ACK_ACK = 0x0501,
    MsgId_CFG_PRT = 0x0600,
    MsgId_CFG_MSG = 0x0601,
    MsgId_CFG_INF = 0x0602,
    MsgId_CFG_RST = 0x0604,
    MsgId_CFG_DAT = 0x0606,
    MsgId_CFG_TP = 0x0607,
    MsgId_CFG_RATE = 0x0608,
    MsgId_CFG_CFG = 0x0609,
    MsgId_CFG_FXN = 0x060E,
    MsgId_CFG_RXM = 0x0611,
    MsgId_CFG_EKF = 0x0612,
    MsgId_CFG_ANT = 0x0613,
    MsgId_CFG_SBAS = 0x0616,
    MsgId_CFG_NMEA = 0x0617,
    MsgId_CFG_USB = 0x061b,
    MsgId_CFG_TMODE = 0x061d,
    MsgId_CFG_NVS = 0x0622,
    MsgId_CFG_NAVX5 = 0x0623,
    MsgId_CFG_NAV5 = 0x0624,
    MsgId_CFG_ESFGWT = 0x0629,
    MsgId_CFG_TP5 = 0x0631,
    MsgId_CFG_PM = 0x0632,
    MsgId_CFG_RINV = 0x0634,
    MsgId_CFG_ITFM = 0x0639,
    MsgId_CFG_PM2 = 0x063b,
    MsgId_CFG_TMODE2 = 0x063d,
    MsgId_CFG_GNSS = 0x063e,
    MsgId_CFG_LOGFILTER = 0x0647,
    MsgId_MON_IO = 0x0a02,
    MsgId_MON_VER = 0x0a04,
    MsgId_MON_MSGPP = 0x0a06,
    MsgId_MON_RXBUF = 0x0a07,
    MsgId_MON_TXBUF = 0x0a08,
    MsgId_MON_HW = 0x0a09,
    MsgId_MON_HW2 = 0x0a0b,
    MsgId_MON_RXR = 0x0a21,
    MsgId_AID_REQ = 0x0b00,
    MsgId_AID_INI = 0x0b01,
    MsgId_AID_HUI = 0x0b02,
    MsgId_AID_DATA = 0x0b10,
    MsgId_AID_ALM = 0x0b30,
    MsgId_AID_EPH = 0x0b31,
    MsgId_AID_ALPSRV = 0x0b32,
    MsgId_AID_AOP = 0x0b33,
    MsgId_AID_ALP = 0x0b50,
    MsgId_TIM_TP = 0x0d01,
    MsgId_TIM_TM2 = 0x0d03,
    MsgId_TIM_SVIN = 0x0d04,
    MsgId_TIM_VRFY = 0x0d06,
};

}  // namespace ublox


