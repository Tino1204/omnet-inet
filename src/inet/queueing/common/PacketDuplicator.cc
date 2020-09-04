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

#include "inet/common/ModuleAccess.h"
#include "inet/queueing/common/PacketDuplicator.h"

namespace inet {
namespace queueing {

Define_Module(PacketDuplicator);

void PacketDuplicator::pushPacket(Packet *packet, cGate *gate)
{
    Enter_Method("pushPacket");
    take(packet);
    int numDuplicates = par("numDuplicates");
    for (int i = 0; i < numDuplicates; i++) {
        EV_INFO << "Forwarding duplicate packet" << EV_FIELD(packet) << EV_ENDL;
        auto duplicate = packet->dup();
        pushOrSendPacket(duplicate, outputGate, consumer);
    }
    EV_INFO << "Forwarding original packet" << EV_FIELD(packet) << EV_ENDL;
    pushOrSendPacket(packet, outputGate, consumer);
    numProcessedPackets++;
    processedTotalLength += packet->getTotalLength();
    updateDisplayString();
}

void PacketDuplicator::handleCanPushPacketChanged(cGate *gate)
{
    Enter_Method("handleCanPushPacketChanged");
    if (producer != nullptr)
        producer->handleCanPushPacketChanged(inputGate->getPathStartGate());
}

void PacketDuplicator::handlePushPacketProcessed(Packet *packet, cGate *gate, bool successful)
{
    Enter_Method("handlePushPacketProcessed");
    producer->handlePushPacketProcessed(packet, gate, successful);
}

} // namespace queueing
} // namespace inet

