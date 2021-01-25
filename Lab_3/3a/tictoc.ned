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

package lab3;

simple Txc
{
    parameters:
        @display("i=block/routing");
    gates:
        inout gate[];
}

//
// TODO auto-generated type
//
network Tictoc
{
    types:
        channel Channel extends ned.DelayChannel
        {
            delay = 100ms;
        }
    submodules:
        txc0: Txc {
            @display("p=52,106");
        }
        txc1: Txc {
            @display("p=52,202");
        }
        txc2: Txc {
            @display("p=52,296");
        }
        txc3: Txc {
            @display("p=143,269");
        }
        txc4: Txc {
            @display("p=182,202");
        }
        txc5: Txc {
            @display("p=143,132");
        }
        txc6: Txc {
            @display("p=259,106");
        }
        txc7: Txc {
            @display("p=259,202");
        }
        txc8: Txc {
            @display("p=259,296");
        }
        txc9: Txc {
            @display("p=345,296");
        }
        txc10: Txc {
            @display("p=423,296");
        }
        txc11: Txc {
            @display("p=423,202");
        }
        txc12: Txc {
            @display("p=423,106");
        }
        txc13: Txc {
            @display("p=511,296");
        }
        txc14: Txc {
            @display("p=511,202");
        }
        txc15: Txc {
            @display("p=511,106");
        }
        txc16: Txc {
            @display("p=580,163");
        }
        txc17: Txc {
            @display("p=631,230");
        }
        txc18: Txc {
            @display("p=685,296");
        }
        txc19: Txc {
            @display("p=685,202");
        }
        txc20: Txc {
            @display("p=685,102");
        }
        txc21: Txc {
            @display("p=943,102");
        }
        txc22: Txc {
            @display("p=860,102");
        }
        txc23: Txc {
            @display("p=775,102");
        }
        txc24: Txc {
            @display("p=775,202");
        }
        txc25: Txc {
            @display("p=775,296");
        }
        txc26: Txc {
            @display("p=860,296");
        }
        txc27: Txc {
            @display("p=943,296");
        }
        txc28: Txc {
            @display("p=943,219");
        }
        txc29: Txc {
            @display("p=884,219");
        }
    connections:
        txc0.gate++ <--> Channel <--> txc1.gate++;
        txc1.gate++ <--> Channel <--> txc2.gate++;
        txc2.gate++ <--> Channel <--> txc3.gate++;
        txc3.gate++ <--> Channel <--> txc4.gate++;
        txc4.gate++ <--> Channel <--> txc5.gate++;
        txc5.gate++ <--> Channel <--> txc0.gate++;
        txc4.gate++ <--> Channel <--> txc7.gate++;
        txc6.gate++ <--> Channel <--> txc7.gate++;
        txc7.gate++ <--> Channel <--> txc8.gate++;
        txc8.gate++ <--> Channel <--> txc9.gate++;
        txc9.gate++ <--> Channel <--> txc10.gate++;
        txc10.gate++ <--> Channel <--> txc11.gate++;
        txc11.gate++ <--> Channel <--> txc12.gate++;
        txc11.gate++ <--> Channel <--> txc14.gate++;
        txc13.gate++ <--> Channel <--> txc14.gate++;
        txc14.gate++ <--> Channel <--> txc15.gate++;
        txc15.gate++ <--> Channel <--> txc16.gate++;
        txc16.gate++ <--> Channel <--> txc17.gate++;
        txc17.gate++ <--> Channel <--> txc18.gate++;
        txc18.gate++ <--> Channel <--> txc19.gate++;
        txc19.gate++ <--> Channel <--> txc20.gate++;
        txc19.gate++ <--> Channel <--> txc24.gate++;
        txc24.gate++ <--> Channel <--> txc23.gate++;
        txc23.gate++ <--> Channel <--> txc22.gate++;
        txc22.gate++ <--> Channel <--> txc21.gate++;
        txc24.gate++ <--> Channel <--> txc25.gate++;
        txc25.gate++ <--> Channel <--> txc26.gate++;
        txc26.gate++ <--> Channel <--> txc27.gate++;
        txc27.gate++ <--> Channel <--> txc28.gate++;
        txc28.gate++ <--> Channel <--> txc29.gate++;
}
