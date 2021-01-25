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

package lab_1_1;

simple Computer
{
    gates:
        input in;
        output out;
}

//
// TODO auto-generated type
//
network Network
{
    @display("bgb=287,164");
    submodules:
        computer_tic: Computer {
            @display("p=65,66");
        }
        computer_toc: Computer {
            @display("p=223,66");
        }
    connections:
        computer_tic.out --> computer_toc.in;
        computer_toc.out --> computer_tic.in;
}
