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
#include "inet/common/ProtocolTag_m.h"
#include "inet/protocol/checksum/FcsHeaderInserter.h"
#include "inet/protocol/checksum/header/FcsHeader_m.h"
#include "inet/protocol/common/AccessoryProtocol.h"

namespace inet {

Define_Module(FcsHeaderInserter);

void FcsHeaderInserter::initialize(int stage)
{
    FcsInserterBase::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        headerPosition = parseHeaderPosition(par("headerPosition"));
        registerService(AccessoryProtocol::fcs, inputGate, nullptr);
        registerProtocol(AccessoryProtocol::fcs, outputGate, nullptr);
    }
}

void FcsHeaderInserter::processPacket(Packet *packet)
{
    const auto& header = makeShared<FcsHeader>();
    auto fcs = computeFcs(packet, fcsMode);
    header->setFcs(fcs);
    header->setFcsMode(fcsMode);
    insertHeader<FcsHeader>(packet, header, headerPosition);
    packet->addTagIfAbsent<PacketProtocolTag>()->setProtocol(&AccessoryProtocol::fcs);
}

} // namespace inet

