#include "microTuple.h"
int one = 1;

void print(int one, float two, String tree){
	Serial.print(one);
	Serial.print(two);
	Serial.println(tree);
}

void setup(){
	Serial.begin(9600);
	MicroTuple<typeof(one), float, String> data(one, 2.1, "Hello");  //create Args data structure
	ParamsPack<typeof(one), float, String> p = { data, print };		//add data structure and function pointer 
	p.getPack();													//do the callback (arguments...)

	//could aslo use only the data structure if needed:
	int firstItem = data.get<0>();  								//get the firts item of the pack, this case an integer
}
void loop(){

}