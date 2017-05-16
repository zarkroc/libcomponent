#include <stdio.h>
#include "libcomponent.h"
int main(int argc, char** argv) {
	float orig_resistances[4] = {
		0.1,4.7,33.0,470
	};
	int nrOfResistors;
	int i;
	float res_array[3];
	float err;
	for(i = 0; i < 4; i++) {
		res_array[0] = 0.0;
		res_array[1] = 0.0;
		res_array[2] = 0.0;
		nrOfResistors = e_resistance(orig_resistances[i], res_array);
		err = orig_resistances[i]-res_array[0]-res_array[1]-res_array[2];
		printf("-- %d --\n",i);
		printf("orig_resistance: %2.2f\n",orig_resistances[i]);
		printf("Difference: %2.2f\n",err);
		printf("nrOfResistors: %d\n",nrOfResistors);
		printf("res_array: %2.2f, %2.2f, %2.2f\n",res_array[0],res_array[1],res_array[2]);
		printf("-----------------------------\n");
	}
	return 0;
}
