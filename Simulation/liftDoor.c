/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/USER/SCADE/LiftDoor/Simulation/config.txt
** Generation date: 2020-01-10T17:37:34
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "liftDoor.h"

/* liftDoor/ */
void liftDoor(inC_liftDoor *inC, outC_liftDoor *outC)
{
  outC->_L2 = inC->closeRequest;
  outC->_L8 = !outC->_L2;
  outC->_L7 = kcg_false;
  outC->_L4 = inC->atLevel;
  outC->_L3 = inC->stopped;
  outC->_L1 = inC->openRequest;
  outC->_L5 = outC->_L1 & outC->_L3 & outC->_L4;
  /* _L6= */
  if (outC->_L5) {
    outC->_L6 = outC->_L8;
  }
  else {
    outC->_L6 = outC->_L7;
  }
  outC->safeOpen = outC->_L6;
}

#ifndef KCG_USER_DEFINED_INIT
void liftDoor_init(outC_liftDoor *outC)
{
  outC->_L8 = kcg_true;
  outC->_L7 = kcg_true;
  outC->_L6 = kcg_true;
  outC->_L5 = kcg_true;
  outC->_L4 = kcg_true;
  outC->_L3 = kcg_true;
  outC->_L2 = kcg_true;
  outC->_L1 = kcg_true;
  outC->safeOpen = kcg_true;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void liftDoor_reset(outC_liftDoor *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** liftDoor.c
** Generation date: 2020-01-10T17:37:34
*************************************************************$ */

