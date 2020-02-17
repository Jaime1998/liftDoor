#include "LiftDoor_interface.h"
#include "LiftDoor_type.h"
#include "LiftDoor_mapping.h"
#include "SmuVTable.h"
#include <string.h>

#define UNUSED(x) (void)(x)
/* context */

inC_liftDoor inputs_ctx;
static inC_liftDoor inputs_ctx_execute;
outC_liftDoor outputs_ctx;

static void _SCSIM_RestoreInterface(void) {
    init_kcg_bool(&inputs_ctx.openRequest);
    init_kcg_bool(&inputs_ctx_execute.openRequest);
    init_kcg_bool(&inputs_ctx.closeRequest);
    init_kcg_bool(&inputs_ctx_execute.closeRequest);
    init_kcg_bool(&inputs_ctx.stopped);
    init_kcg_bool(&inputs_ctx_execute.stopped);
    init_kcg_bool(&inputs_ctx.atLevel);
    init_kcg_bool(&inputs_ctx_execute.atLevel);
    memset((void*)&outputs_ctx, 0, sizeof(outputs_ctx));
}

static void _SCSIM_ExecuteInterface(void) {
    pSimulator->m_pfnAcquireValueMutex(pSimulator);
    inputs_ctx_execute.openRequest = inputs_ctx.openRequest;
    inputs_ctx_execute.closeRequest = inputs_ctx.closeRequest;
    inputs_ctx_execute.stopped = inputs_ctx.stopped;
    inputs_ctx_execute.atLevel = inputs_ctx.atLevel;
    pSimulator->m_pfnReleaseValueMutex(pSimulator);
}

#ifdef __cplusplus
extern "C" {
#endif

const int  rt_version = Srtv62;

const char* _SCSIM_CheckSum = "dadeba11857a926eafec3860b1db7602";
const char* _SCSIM_SmuTypesCheckSum = "f59a7f532a7d2323bdffcdce912b7ce3";

/* simulation */

int SimInit(void) {
    int nRet = 0;
    _SCSIM_RestoreInterface();
#ifdef EXTENDED_SIM
    BeforeSimInit();
#endif
#ifndef KCG_USER_DEFINED_INIT
    liftDoor_init(&outputs_ctx);
    nRet = 1;
#else
    nRet = 0;
#endif
#ifdef EXTENDED_SIM
    AfterSimInit();
#endif
    return nRet;
}

int SimReset(void) {
    int nRet = 0;
    _SCSIM_RestoreInterface();
#ifdef EXTENDED_SIM
    BeforeSimInit();
#endif
#ifndef KCG_NO_EXTERN_CALL_TO_RESET
    liftDoor_reset(&outputs_ctx);
    nRet = 1;
#else
    nRet = 0;
#endif
#ifdef EXTENDED_SIM
    AfterSimInit();
#endif
    return nRet;
}

#ifdef __cplusplus
    #ifdef pSimoutC_liftDoorCIVTable_defined
        extern struct SimCustomInitVTable *pSimoutC_liftDoorCIVTable;
    #else 
        struct SimCustomInitVTable *pSimoutC_liftDoorCIVTable = NULL;
    #endif
#else
    struct SimCustomInitVTable *pSimoutC_liftDoorCIVTable;
#endif

int SimCustomInit(void) {
    int nRet = 0;
    if (pSimoutC_liftDoorCIVTable != NULL && 
        pSimoutC_liftDoorCIVTable->m_pfnCustomInit != NULL) {
        /* VTable function provided => call it */
        nRet = pSimoutC_liftDoorCIVTable->m_pfnCustomInit ((void*)&outputs_ctx);
    }
    else {
        /* VTable misssing => error */
        nRet = 0;
    }
    return nRet;
}

#ifdef EXTENDED_SIM
    int GraphicalInputsConnected = 1;
#endif

int SimStep(void) {
#ifdef EXTENDED_SIM
    if (GraphicalInputsConnected)
        BeforeSimStep();
#endif
    _SCSIM_ExecuteInterface();
    liftDoor(&inputs_ctx_execute, &outputs_ctx);
#ifdef EXTENDED_SIM
    AfterSimStep();
#endif
    return 1;
}

int SimStop(void) {
#ifdef EXTENDED_SIM
    ExtendedSimStop();
#endif
    return 1;
}

void SsmUpdateValues(void) {
#ifdef EXTENDED_SIM
    UpdateValues();
#endif
}

void SsmConnectExternalInputs(int bConnect) {
#ifdef EXTENDED_SIM
    GraphicalInputsConnected = bConnect;
#else
    UNUSED(bConnect);
#endif
}

/* dump */

int SsmGetDumpSize(void) {
    int nSize = 0;
    nSize += sizeof(inC_liftDoor);
    nSize += sizeof(outC_liftDoor);
#ifdef EXTENDED_SIM
    nSize += ExtendedGetDumpSize();
#endif
    return nSize;
}

void SsmGatherDumpData(char * pData) {
    char* pCurrent = pData;
    memcpy(pCurrent, &inputs_ctx, sizeof(inC_liftDoor));
    pCurrent += sizeof(inC_liftDoor);
    memcpy(pCurrent, &outputs_ctx, sizeof(outC_liftDoor));
    pCurrent += sizeof(outC_liftDoor);
#ifdef EXTENDED_SIM
    ExtendedGatherDumpData(pCurrent);
#endif
}

void SsmRestoreDumpData(const char * pData) {
    const char* pCurrent = pData;
    memcpy(&inputs_ctx, pCurrent, sizeof(inC_liftDoor));
    pCurrent += sizeof(inC_liftDoor);
    memcpy(&outputs_ctx, pCurrent, sizeof(outC_liftDoor));
    pCurrent += sizeof(outC_liftDoor);
#ifdef EXTENDED_SIM
    ExtendedRestoreDumpData(pCurrent);
#endif
}

/* snapshot */

int SsmSaveSnapshot(const char * szFilePath, size_t nCycle) {
    /* Test Services API not available */
    UNUSED(szFilePath);
    UNUSED(nCycle);
    return 0;
}

int SsmLoadSnapshot(const char * szFilePath, size_t *nCycle) {
    /* Test Services API not available */
    UNUSED(szFilePath);
    UNUSED(nCycle);
    return 0;
}

/* checksum */

const char * SsmGetCheckSum() {
    return _SCSIM_CheckSum;
}

const char * SsmGetSmuTypesCheckSum() {
    return _SCSIM_SmuTypesCheckSum;
}

#ifdef __cplusplus
} /* "C" */
#endif

