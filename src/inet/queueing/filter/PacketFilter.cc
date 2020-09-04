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

#include "inet/queueing/filter/PacketFilter.h"

namespace inet {
namespace queueing {

Define_Module(PacketFilter);

void PacketFilter::initialize(int stage)
{
    PacketFilterBase::initialize(stage);
    if (stage == INITSTAGE_LOCAL)
        packetFilterFunction = createFilterFunction(par("filterClass"));
}

IPacketFilterFunction *PacketFilter::createFilterFunction(const char *filterClass) const
{
    return check_and_cast<IPacketFilterFunction *>(createOne(filterClass));
}

bool PacketFilter::matchesPacket(const Packet *packet) const
{
    return packetFilterFunction->matchesPacket(packet);
}

} // namespace queueing
} // namespace inet

