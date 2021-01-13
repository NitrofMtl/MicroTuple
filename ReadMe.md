# MicroTuple

MicroTuple is a small Arduino library that enables variadic data structures and variadic callbacks.

## Usage

```
 	MicroTuple<int, float, String> data(one, 2.1, "Hello");  		//create data structure
	ParamsPack<int, float, String> p = { data, print };				//add data structure and function pointer to print(int, float, String)
	p.getPack();													//do the callback (arguments...)

	//could aslo use only the data structure if needed:
	int firstItem = data.get<0>();  								//get the first item of the pack, this case an integer
	data.set<0>(newValue);											//set the first item of the pack to a new value
```


Copyright (c) 02/04/2020 NitrofMtl - License GPL-V3.0
