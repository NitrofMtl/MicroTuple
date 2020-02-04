# MicroTuple

MicroTuple is a small libraries that enable variadic data structure and variadic callack.

Usage:

 	MicroTuple<int, float, String> data(one, 2.1, "Hello");  //create data structure
	ParamsPack<int, float, String> p = { data, print };		//add data structure and function pointer to print(int, float, String)
	p.getPack();													//do the callback (arguments...)

	//could aslo use only the data structure if needed:
	int firstItem = data.get<0>();  								//get the firts item of the pack, this case an integer

` 




// This file is part of MicroTuple.
//
// MicroTuple is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// uHTTP is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Nome-Programma.  If not, see <http://www.gnu.org/licenses/>.


//Copyright (c) 02/04/2020 NitrofMtl