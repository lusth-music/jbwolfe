#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/"
#define base "drums"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "drums";
char *PROGRAM_VERSION = "0.01";

int
main()
    {
    int instrument;
    int octave = 4;
    int spot;

    songInit();

    instrument = readScale(dir,base);

    setTempo(200);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.4);

    openOutput("drums.rra",0,0);

    drumkitKick (1, 1, "x---x---x---x---", SX);
    int i;
    for(i=0; i<2; ++i) {
      drumkitSnare (1,1,"xg", SX);
      drumkitSnare (1,1,"xg", SX);
      drumkitSnare (1,1,"xg", SX);
      drumkitSnare (1,1,"xg", SX);
    }
    /*
    int i;
    for(i=0; i<2;++i) {
      spot = getLocation();
      drumkitCrash (1,1,"----------------", SX); setLocation(spot);
      drumkitHHOpen(1,1,"----------------", SX); setLocation(spot);
      drumkitSnare (1,1,"----------------", SX); setLocation(spot);
      drumkitKick  (1,1,"----------------", SX);
    }
    */
    /*
    spot = getLocation();
    drumkitHHOpen(2,1,"X-x-x-x-x-X-x-x-", SX); setLocation(spot);
    drumkitSnare (2,1,"X-g-g-g-g-X-g-g-", SX);

    spot = getLocation();
    drumkitHHOpen(1,1,"X-x-x-x-X-x-x-X-", SX); setLocation(spot);
    drumkitSnare (1,1,"X-g-g-g-X-g-g-X-", SX);

    spot = getLocation();
    drumkitHHOpen(1,1,"x-X-x-X-X-X-X-X-", SX); setLocation(spot);
    drumkitSnare (1,1,"g-X-g-X-X-X-X-X-", SX);

    spot = getLocation();
    drumkitCrash (1,1,"x---------------", SX); setLocation(spot);
    drumkitHHOpen(1,1,"----x-x-x-x-x-x-", SX); setLocation(spot);
    drumkitSnare (1,1,"----x-------x---", SX); setLocation(spot);
    drumkitKick  (1,2,"x-------x-x-----", SX);

    int i;
    for(i = 0; i < 4; ++i) {
      spot = getLocation();
      drumkitCrash (1,1,"----------------", SX); setLocation(spot);
      drumkitHHOpen(1,1,"x-x-x-x-x-x-x-x-", SX); setLocation(spot);
      drumkitSnare (1,1,"----x-------x---", SX); setLocation(spot);
      drumkitKick  (1,2,"x-x-----x-x-----", SX);
    }
    */

    closeOutput();

    return 0;
    }
