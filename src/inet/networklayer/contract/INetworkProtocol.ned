//
// Copyright (C) 2012 Opensim Ltd
// Author: Levente Meszaros
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
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

package inet.networklayer.contract;

//
// This interface provides an abstraction for different network protocols.
//
moduleinterface INetworkProtocol
{
    parameters:
        @display("i=block/fork");
    gates:
        input transportIn @labels(INetworkProtocolControlInfo/down);
        output transportOut @labels(INetworkProtocolControlInfo/up);
        input queueIn @labels(INetworkHeader);
        output queueOut @labels(INetworkHeader);
}

