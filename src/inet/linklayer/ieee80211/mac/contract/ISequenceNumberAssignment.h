//
// Copyright (C) 2016 OpenSim Ltd.
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

#ifndef __INET_ISEQUENCENUMBERASSIGNMENT_H
#define __INET_ISEQUENCENUMBERASSIGNMENT_H

#include "inet/linklayer/ieee80211/mac/Ieee80211Frame_m.h"

namespace inet {
namespace ieee80211 {

class INET_API ISequenceNumberAssignment
{
    public:
        virtual ~ISequenceNumberAssignment() { }

        virtual void assignSequenceNumber(const Ptr<Ieee80211DataOrMgmtHeader>& header) = 0;
};

} // namespace ieee80211
} // namespace inet

#endif

