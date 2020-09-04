//
// Copyright (C) OpenSim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "inet/common/IProtocolRegistrationListener.h"
#include "inet/protocol/checksum/FcsHeaderChecker.h"
#include "inet/protocol/checksum/header/FcsHeader_m.h"
#include "inet/protocol/common/AccessoryProtocol.h"

namespace inet {

Define_Module(FcsHeaderChecker);

void FcsHeaderChecker::initialize(int stage)
{
    FcsCheckerBase::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        headerPosition = parseHeaderPosition(par("headerPosition"));
        registerService(AccessoryProtocol::fcs, nullptr, inputGate);
        registerProtocol(AccessoryProtocol::fcs, nullptr, outputGate);
    }
}

void FcsHeaderChecker::processPacket(Packet *packet)
{
    popHeader<FcsHeader>(packet, headerPosition, B(4));
}

bool FcsHeaderChecker::matchesPacket(const Packet *packet) const
{
    const auto& header = peekHeader<FcsHeader>(packet, headerPosition, B(4));
    auto fcsMode = header->getFcsMode();
    auto fcs = header->getFcs();
    return checkFcs(packet, fcsMode, fcs);
}

} // namespace inet

