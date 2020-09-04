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

#ifndef __INET_IPACKETSCHEDULERFUNCTION_H
#define __INET_IPACKETSCHEDULERFUNCTION_H

#include "inet/queueing/contract/IPassivePacketSource.h"

namespace inet {
namespace queueing {

/**
 * This class defines the interface for packet scheduler functions.
 */
class INET_API IPacketSchedulerFunction
{
  public:
    virtual ~IPacketSchedulerFunction() {}

    /**
     * Returns the index of the scheduled provider.
     */
    virtual int schedulePacket(const std::vector<IPassivePacketSource *>& sources) const = 0;
};

} // namespace queueing
} // namespace inet

#endif

