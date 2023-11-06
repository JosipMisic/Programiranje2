#include "MyHeader.h"

int main(void)
{
    PUTOVANJE* putovanja, * max1, * max2;

    int brojPutovanja;
    int max;

    unosBrojaPutovanja(brojPutovanja);

    putovanja = alokacijaPutovanja(brojPutovanja);

    max = unosPutovanja(putovanja, brojPutovanja);


    printf("REZULTATI:\n");
    ispisPutovanja(max);

    free(putovanja);
    return 0;
}
