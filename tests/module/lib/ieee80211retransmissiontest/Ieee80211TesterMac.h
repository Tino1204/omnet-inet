//
// Copyright (C) 2015 OpenSim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see http://www.gnu.org/licenses/.
//
//

#ifndef __INET_IEEE80211TESTERMAC_H
#define __INET_IEEE80211TESTERMAC_H

#include "inet/linklayer/ieee80211/mac/Ieee80211Mac.h"

namespace inet {

using namespace ieee80211;
using namespace physicallayer;

class INET_API Ieee80211TesterMac : public Ieee80211Mac
{
    protected:
        int msgCounter = 0;
        const char *actions = nullptr;

    protected:
        virtual void handleLowerPacket(Packet *packet) override;
};

} // namespace inet

#endif

