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

package lab_6_5;

//
// TODO auto-generated type
//

simple Nodes
{
	parameters:
		@display("i=device/pc");
		int type;
		int des = default(-1);
		int k = 4;
		int EXB_SIZE;
		double TIMEOUT;
		double TIME_INTERVAL;
		double CHANNEL_DELAY;
		double CREDIT_DELAY;
		double TIME_GEN_MSG;
		double TIME_OPERATION_OF_SWITCH;
	gates:
		input in[4];
		output out[4];
}

network fattree
{
	parameters:
		Node[4].type = 2;
		Node[5].type = 2;
		Node[6].type = 2;
		Node[7].type = 2;
		Node[12].type = 2;
		Node[13].type = 2;
		Node[14].type = 2;
		Node[15].type = 2;
		Node[20].type = 2;
		Node[21].type = 2;
		Node[22].type = 2;
		Node[23].type = 2;
		Node[28].type = 2;
		Node[29].type = 2;
		Node[30].type = 2;
		Node[31].type = 2;
		Node[32].type = 2;
		Node[33].type = 2;
		Node[34].type = 2;
		Node[35].type = 2;
		Node[11].type = 1;
		Node[11].des = 8;
		Node[8].type = 3;
		Node[27].type = 1;
		Node[27].des = 1;
		Node[1].type = 3;
		Node[3].type = 1;
		Node[3].des = 9;
		Node[9].type = 3;
		Node[26].type = 1;
		Node[26].des = 17;
		Node[17].type = 3;
		Node[19].type = 1;
		Node[19].des = 18;
		Node[18].type = 3;
		Node[0].type = 1;
		Node[0].des = 2;
		Node[2].type = 3;
		Node[16].type = 1;
		Node[16].des = 24;
		Node[24].type = 3;
		Node[10].type = 1;
		Node[10].des = 25;
		Node[25].type = 3;

	types:
		 channel Channel extends ned.DatarateChannel {
			datarate = 1Gbps;
		}
	submodules:
		Node[36]: Nodes;
	connections allowunconnected:
		for p=0..3, for e=0..1, for s=0..1{
			Node[int(8*p + e*4/2 + s)].out++ --> Channel --> Node[int(8*p + 4*4/4 + e)].in++;
			Node[int(8*p + e*4/2 + s)].in++ <-- Channel <-- Node[int(8*p + 4*4/4 + e)].out++;
		}
		for p=0..3, for e=0..1, for s=2..3{
			Node[int(8*p + 4*4/4 + e)].out++ --> Channel --> Node[int(8*p + 4*4/4 + s)].in++;
			Node[int(8*p + 4*4/4 + e)].in++ <-- Channel <-- Node[int(8*p + 4*4/4 + s)].out++;
		}
		for p=0..3, for e=0..1, for s=0..1{
			Node[int(8*p + 4*4/4 + 4/2 + e)].out++ --> Channel --> Node[int(e*4/2 + s + 32)].in++;
			Node[int(8*p + 4*4/4 + 4/2 + e)].in++ <-- Channel <-- Node[int(e*4/2 + s + 32)].out++;
		}
}
