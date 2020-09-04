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

#ifndef __INET_PACKETBUFFERBASE_H
#define __INET_PACKETBUFFERBASE_H

#include "inet/queueing/base/PacketProcessorBase.h"
#include "inet/queueing/contract/IPacketQueue.h"

namespace inet {
namespace queueing {

class INET_API PacketBufferBase : public PacketProcessorBase, public virtual IPacketCollection
{
  protected:
    const char *displayStringTextFormat = nullptr;
    int numAddedPackets = -1;
    int numRemovedPackets = -1;
    int numDroppedPackets = -1;

  protected:
    virtual void initialize(int stage) override;
    virtual void emit(simsignal_t signal, cObject *object, cObject *details = nullptr) override;
    virtual void updateDisplayString();
};

} // namespace queueing
} // namespace inet

#endif

