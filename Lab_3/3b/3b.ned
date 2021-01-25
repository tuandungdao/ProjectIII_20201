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

package lab3b;

simple WirelessNode
{
    parameters:
        int posX = default(0); 
        int posY =  default(0);
    @display("i=block/triangle,grey,2;is=vs");
    gates:
        input radioIn @directIn;
}
//
// TODO auto-generated type
//
network WirelessA
{
    parameters:
        int n @prompt("Number of nodes") = default(100);
        
        @display("bgb=800,800;bgu=cm");
    submodules:
        node[n]: WirelessNode {
            parameters:
                
                @display("p=0,0");
        }
}

