//
// Copyright (C) 2014 OpenSim Ltd.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "inet/routing/ospfv2/router/OspfRouteData.h"

namespace inet {
namespace ospf {

std::string OspfRouteData::str() const
{
    std::ostringstream out;
    out << "destType:" << OspfRoutingTableEntry::getDestinationTypeString(destType)
    << " pathType:" << OspfRoutingTableEntry::getPathTypeString(pathType)
    << " area:" << area.str(false);

    return out.str();
};

} // namespace aodv
} // namespace inet
