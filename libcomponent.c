#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float getE12Resistance(float resistance) {
    int i;
    int numberOfZeroes =0;
    float countDown = 0;
    static float E12table[] = {
        1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2
    };

    numberOfZeroes = log10(resistance);

    for(i = 11; countDown <= 1; i--) {
	    countDown = resistance / ((pow(10, numberOfZeroes) * E12table[i]));
    }

    return (E12table[(i+1)] * pow(10, numberOfZeroes));
}

int e_resistance(float orig_resistance, float *res_array )
{
        int count = 0;
        float resistance = 0;
        resistance = orig_resistance;
		// Medans ersättningsresistancen är över 1 och count (komponenter) är under 3
        while(resistance >= 1.0 && count < 3)
        {
                *(res_array + count) = getE12Resistance(resistance);
                resistance -= *(res_array + count);
                count++;
        }
        return count;
}
