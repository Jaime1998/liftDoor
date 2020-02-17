/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/USER/SCADE/LiftDoor/Simulation/config.txt
** Generation date: 2020-01-10T17:37:34
*************************************************************$ */
#ifndef _liftDoor_H_
#define _liftDoor_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_bool /* openRequest/ */ openRequest;
  kcg_bool /* closeRequest/ */ closeRequest;
  kcg_bool /* stopped/ */ stopped;
  kcg_bool /* atLevel/ */ atLevel;
} inC_liftDoor;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* safeOpen/ */ safeOpen;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_bool /* _L1/ */ _L1;
  kcg_bool /* _L2/ */ _L2;
  kcg_bool /* _L3/ */ _L3;
  kcg_bool /* _L4/ */ _L4;
  kcg_bool /* _L5/ */ _L5;
  kcg_bool /* _L6/ */ _L6;
  kcg_bool /* _L7/ */ _L7;
  kcg_bool /* _L8/ */ _L8;
} outC_liftDoor;

/* ===========  node initialization and cycle functions  =========== */
/* liftDoor/ */
extern void liftDoor(inC_liftDoor *inC, outC_liftDoor *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void liftDoor_reset(outC_liftDoor *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void liftDoor_init(outC_liftDoor *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _liftDoor_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** liftDoor.h
** Generation date: 2020-01-10T17:37:34
*************************************************************$ */

