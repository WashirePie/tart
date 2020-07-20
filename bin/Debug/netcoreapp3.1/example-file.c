/******************************************************************************
Example Source File
*******************************************************************************

******************************************************************************/


#include "memlist_f.h"                  // XXXX
#include "iolist_f.h"                   // XXXX


module  PMCOPT(X12_2323JSJSJJJ) ; NAME=TITLE_62500; IO=IO_LIST;
/***************************************************************************

/**************************************************************************
** XXXXXXXXXXXXXXX
****************************************************************************/
#ifdef ESAFETY_EDGE_NOT_ACTUATED
 RD     ESAFETY_EDGE_NOT_ACTUATED           WRT     MESAFETY_EDGE_NOT_ACTUATED
#endif
// XXXX
// XXXX
RD      EMMC_STATUS                         WRT     MEMMC_STATUS
RD      SWI_SICHERHEIT_EIN                  WRT     MSWI_SICHERHEIT_EIN
RD      E_XESP                              WRT     ME_XESP
// XXXX
// XXXX


/**************************************************************************
** XXXXXXXXXXXXXXX
****************************************************************************
**/

 // XXXX
 RD     AALL_DOOR_CLOSED
 DIFU   ALL_DOOR_CLOSED_ON                  WRT     ALL_DOOR_CLOSED_IMP

// XXXX
// XXXX
// XXXX

// XXXX
RD      BMI_ESP_ENTRIEGELN          // XXXX
OR.NOT  PMCOPT(PMCSET_BMI_INF_2)    // XXXX
#ifdef EESP1_FEEDBACK
 AND     EESP1_FEEDBACK             // XXXX
 AND     PMCOPT(OPTION_SET)         // XXXX
#endif
TMRBF   TMBF_FEEDBACK_ESP1 600              WRT    ESP1_FEEDBACK_LONG


// XXXX
#ifdef  EMDOOR1_FEEDBACK
// XXXX
RD.NOT  EMDOOR1_LOCKED
OR.NOT  E_ESP
AND     EMDOOR1_FEEDBACK
TMRBF   TMBF_FEEDBACK_MDOOR1 600            WRT     MDOOR1_FEEDBACK_LONG
#endif


// XXXX
RD      E_SPANNMITTEL_FEEDBACK
TMRBF   TMBF_FEEDBACK_SPANNM 600            WRT     SPANNM_FEEDBACK_LONG



 /**************************************************************************
** XXXXXXXXXXXXXXX
****************************************************************************
*
*/
// XXXX
RD      BUT_ZUSTI_BETAETIGT
#ifdef BUT_ZUSTI_HBA_BETAETIGT // XXXX
 OR      BUT_ZUSTI_HBA_BETAETIGT
#endif
#ifdef AUX_SCHALTER                         // XXXX
RD.STK  AUX_SCHALTER                        // XXXX
OR.NOT  SCHLUESSEL_SCHALTER
AND.STK
#endif
DIFU    ZUSTIMMUNG_ON                       SET     ZUSTIMMUNG_SET
                                            WRT     ZUSTIMMUNG_IMP

// XXXX
#ifdef AUX_SCHALTER                                                 // XXXX
RD.NOT  AUX_SCHALTER                                                // XXXX
AND     SCHLUESSEL_SCHALTER
AND     MLD(1526)                                                   // XXXX
                                            WRT     MLD(2135)       // XXXX
#endif

// XXXX
RD.NOT  BUT_ZUSTI_BETAETIGT
#ifdef BUT_ZUSTI_HBA_BETAETIGT // XXXX
 AND.NOT BUT_ZUSTI_HBA_BETAETIGT
#endif
                                            RESET   ZUSTIMMUNG_SET

RD      DUAL_BUT_ZUSTI_BETAETIGT
DIFD    ZUSTIMMUNG_OFF                      RESET   ZUSTIMMUNG_SET
#ifdef DIFD_DUAL_BUT_ZUSTI_BETAETIGT
                                            WRT     DIFD_DUAL_BUT_ZUSTI_BETAETIGT
#endif
// XXXX
RD      ZUSTIMMUNG_SET                      WRT     W_ZUST_BETAETIGT

// XXXX
RD      ZUSTIMMUNG_SET
AND     R_ZUST_BETAETIGT
TMRB    TMB_DELAY_ACK        40             WRT     DUAL_BUT_ZUSTI_BETAETIGT

// XXXX
RD.NOT  ZUSTIMMUNG_SET
AND     R_ZUST_BETAETIGT

RD.STK  ZUSTIMMUNG_SET
AND.NOT R_ZUST_BETAETIGT
OR.STK
TMRB    TMB_ACK_SYNCHRON   400              RESET   ZUSTIMMUNG_SET

/**************************************************************************
** XXXXXXXXXXXXXXX
***************************************************************************/

// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX

// XXXX
// XXXX
#ifdef  EDREHT_H1OD1
RD.NOT  ESICHER_H1OD1
OR.NOT  PMCOPT(PMCSET_ODDRIVES_SSPEED)                                      // XXXX
AND     EDREHT_H1OD1                        SET     ANTRIEBE_NICHT_SICHER
#endif

// XXXX
#ifdef  EDREHT_H1OD2
RD.NOT  ESICHER_H1OD2
OR.NOT  PMCOPT(PMCSET_ODDRIVES_SSPEED)                                      // XXXX
AND     EDREHT_H1OD2                        SET     ANTRIEBE_NICHT_SICHER
#endif

// XXXX

// XXXX
#ifdef  EDREHT_HXDD1
RD      EDREHT_HXDD1
AND.NOT SAFE_WHEEL_COVER(4)                 SET     ANTRIEBE_NICHT_SICHER
#endif

// XXXX
#ifdef  EDREHT_HXDD2
RD      EDREHT_HXDD2
AND.NOT SAFE_WHEEL_COVER(5)                 SET     ANTRIEBE_NICHT_SICHER
#endif

// XXXX
#ifdef  EDREHT_H2ID1
RD      EDREHT_H2ID1
AND.NOT SAFE_WHEEL_COVER(18)                SET     ANTRIEBE_NICHT_SICHER
#endif

// XXXX
#ifdef  EDREHT_H2ID2
RD      EDREHT_H2ID2
AND.NOT SAFE_WHEEL_COVER(19)                SET     ANTRIEBE_NICHT_SICHER
#endif

// XXXX
#ifdef  EDREHT_H2ID3
RD      EDREHT_H2ID3
AND.NOT SAFE_WHEEL_COVER(20)                SET     ANTRIEBE_NICHT_SICHER
#endif

// XXXX
#ifdef  EDREHT_H2ID4
RD      EDREHT_H2ID4
AND.NOT SAFE_WHEEL_COVER(21)                SET     ANTRIEBE_NICHT_SICHER
#endif

// XXXX
#ifdef  EDREHT_H2ID5
RD      EDREHT_H2ID5
AND.NOT SAFE_WHEEL_COVER(22)                SET     ANTRIEBE_NICHT_SICHER
#endif

// XXXX
#ifdef  EDREHT_H2ID6
RD      EDREHT_H2ID6
AND.NOT SAFE_WHEEL_COVER(23)                SET     ANTRIEBE_NICHT_SICHER
#endif


// XXXX
#ifdef  EDREHT_H3ID6
RD      EDREHT_H3ID6
AND.NOT SAFE_WHEEL_COVER(32)                SET     ANTRIEBE_NICHT_SICHER
#endif



// XXXX
// XXXX
// XXXX
// XXXX

// XXXX



// XXXX
#ifdef AFREIGABE_BEDIENTUERE
 RD      RSV1
 OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(1))

 RD.STK  RSV2
 OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(2))
 AND.STK

 RD.STK  RSV3
 OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(3))
 AND.STK

 RD.STK  RSV4
 OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(4))
 AND.STK

 RD.STK  RSV5
 OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(5))
 AND.STK

 RD.STK  RSV6
 OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(6))
 AND.STK

 RD.STK  RSV7
 OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(7))
 AND.STK

 RD.STK  RSV8
 OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(8))
 AND.STK

 RD.STK  RSV9
 OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(9))
 AND.STK

 RD.STK  RSV10
 OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(10))
 AND.STK

 // XXXX
 RD.STK  RSP1
 OR.NOT  PMCOPT(PMCSET_SPINDLE(1))
 AND.STK

 RD.STK  RSP2
 OR.NOT  PMCOPT(PMCSET_SPINDLE(2))
 AND.STK

 RD.STK  RSP3
 OR.NOT  PMCOPT(PMCSET_SPINDLE(3))
 AND.STK

 RD.STK  RSP4
 OR.NOT  PMCOPT(PMCSET_SPINDLE(4))
 AND.STK
 AND.NOT  ANTRIEBE_NICHT_SICHER             WRT   AFREIGABE_BEDIENTUERE
#endif

// XXXX
// XXXX

RD      ALL_DOOR_CLOSED                     // XXXX
AND.NOT SERVICE_MODE_AKTIV                  // XXXX
AND.NOT TEST_DNOTSA
TMRBF   TMBF_DRIVES_NOT_SAFE   400          RESET   ANTRIEBE_NICHT_SICHER

// XXXX
// XXXX
// XXXX
// XXXX
RD      LOG_0                               // XXXX
// XXXX
#ifdef  EDREHT_H1OD1
RD.STK  EDREHT_H1OD1
AND.NOT  ESICHER_H1OD1
OR.STK
#endif

// XXXX
#ifdef  EDREHT_H1OD2
RD.STK  EDREHT_H1OD2
AND.NOT  ESICHER_H1OD2
OR.STK
#endif

// XXXX
#ifdef  EDREHT_H1OD3
RD.STK  EDREHT_H1OD3
AND.NOT  ESICHER_H1OD3
OR.STK
#endif

// XXXX
// XXXX
#ifdef  EDREHT_H2OD1
RD.STK  EDREHT_H2OD1
AND.NOT  ESICHER_H2OD1
OR.STK
#endif

// XXXX
#ifdef  EDREHT_H2OD2
RD.STK  EDREHT_H2OD2
AND.NOT  ESICHER_H2OD2
OR.STK
#endif

// XXXX
#ifdef  EDREHT_H2OD3
RD.STK  EDREHT_H2OD3
AND.NOT  ESICHER_H2OD3
OR.STK
#endif

// XXXX
// XXXX
#ifdef  EDREHT_H3OD1
RD.STK  EDREHT_H3OD1
AND.NOT  ESICHER_H3OD1
OR.STK
#endif

// XXXX
#ifdef  EDREHT_H3OD2
RD.STK  EDREHT_H3OD2
AND.NOT  ESICHER_H3OD2
OR.STK
#endif

// XXXX
#ifdef  EDREHT_H3OD3
RD.STK  EDREHT_H3OD3
AND.NOT  ESICHER_H3OD3
OR.STK
#endif

// XXXX
RD.STK     FKT_G9871C_BIT(0)
OR         OPT_HATCH_LIKE_ODOOR
AND.STK                                     SET     ANTRIEBE_NICHT_SICHER_LL
// XXXX
// XXXX
// XXXX
RD      LOG_0                           // XXXX
// XXXX
#ifdef  EDREHT_H1ID1
 RD.STK  EDREHT_H1ID1
 AND.NOT SAFE_WHEEL_COVER(3)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H1ID2
 RD.STK  EDREHT_H1ID2
 AND.NOT SAFE_WHEEL_COVER(7)
 OR.STK
#endif


// XXXX
#ifdef  EDREHT_H1ID3
 RD.STK  EDREHT_H1ID3
 AND.NOT SAFE_WHEEL_COVER(8)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H1ID4
 RD.STK  EDREHT_H1ID4
 AND.NOT SAFE_WHEEL_COVER(10)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H1ID5
 RD.STK  EDREHT_H1ID5
 AND.NOT SAFE_WHEEL_COVER(11)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H1ID6
 RD.STK  EDREHT_H1ID6
 AND.NOT SAFE_WHEEL_COVER(12)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H1ID7
 RD.STK  EDREHT_H1ID7
 AND.NOT SAFE_WHEEL_COVER(13)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H1ID8
 RD.STK  EDREHT_H1ID8
 AND.NOT SAFE_WHEEL_COVER(14)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_HXDD1
 RD.STK  EDREHT_HXDD1
 AND.NOT SAFE_WHEEL_COVER(4)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_HXDD2
 RD.STK  EDREHT_HXDD2
 AND.NOT SAFE_WHEEL_COVER(5)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_HXDD3
 RD.STK  EDREHT_HXDD3
 AND.NOT SAFE_WHEEL_COVER(9)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H2ID1
 RD.STK  EDREHT_H2ID1
 AND.NOT SAFE_WHEEL_COVER(18)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H2ID2
 RD.STK  EDREHT_H2ID2
 AND.NOT SAFE_WHEEL_COVER(19)
 OR.STK

#endif

// XXXX
#ifdef  EDREHT_H2ID3
 RD.STK  EDREHT_H2ID3
 AND.NOT SAFE_WHEEL_COVER(20)
 OR.STK

#endif

// XXXX
#ifdef  EDREHT_H2ID4
 RD.STK  EDREHT_H2ID4
 AND.NOT SAFE_WHEEL_COVER(21)
 OR.STK

#endif

// XXXX
#ifdef  EDREHT_H2ID5
 RD.STK  EDREHT_H2ID5
 AND.NOT SAFE_WHEEL_COVER(22)
 OR.STK

#endif

// XXXX
#ifdef  EDREHT_H2ID6
 RD.STK  EDREHT_H2ID6
 AND.NOT SAFE_WHEEL_COVER(23)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H3ID1
 RD.STK  EDREHT_H3ID1
 AND.NOT SAFE_WHEEL_COVER(27)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H3ID2
 RD.STK  EDREHT_H3ID2
 AND.NOT SAFE_WHEEL_COVER(28)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H3ID3
 RD.STK  EDREHT_H3ID3
 AND.NOT SAFE_WHEEL_COVER(29)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H3ID4
 RD.STK  EDREHT_H3ID4
 AND.NOT SAFE_WHEEL_COVER(30)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H3ID5
 RD.STK  EDREHT_H3ID5
 AND.NOT SAFE_WHEEL_COVER(31)
 OR.STK
#endif

// XXXX
#ifdef  EDREHT_H3ID6
 RD.STK  EDREHT_H3ID6
 AND.NOT SAFE_WHEEL_COVER(32)
 OR.STK
#endif

RD.STK     FKT_G9871C_BIT(1)
OR         OPT_HATCH_LIKE_ODOOR
AND.STK                                     SET     ANTRIEBE_NICHT_SICHER_LL

// XXXX
// XXXX
RD      DACHLUKE_IST_SICHER
AND.NOT TEST_DNOTSA
TMRBF   TMBF_62500_SICHER_LL 400            RESET   ANTRIEBE_NICHT_SICHER_LL

// XXXX
// XXXX
 RD     SERVICE_MODE_AKTIV
 AND    DUAL_BUT_ZUSTI_BETAETIGT                                            // XXXX
 OR     ALL_DOOR_CLOSED
 AND    ESP1_FEEDBACK_LONG                                                  // XXXX
// XXXX
RD.STK  ANOTSTOP_OK                                                         // XXXX
AND.NOT ESP1_FEEDBACK_LONG
OR.STK
// XXXX
AND     E_XESP                                                              // XXXX
AND     NC_READY_PMC1                                                       // XXXX
AND     SWI_SICHERHEIT_EIN                                                  // XXXX
AND.NOT R_ESP_GLOBAL                                                        // XXXX
AND.NOT W_ESP_GLOBAL
AND.NOT ANTRIEBE_NICHT_SICHER                                               // XXXX
AND.NOT ANTRIEBE_NICHT_SICHER_LL                                            // XXXX
AND     _DCALM                                                              // XXXX
AND     DCS_VORHANDEN                                                       // XXXX
#ifdef ESAFETY_EDGE_NOT_ACTUATED
 RD.STK  ESAFETY_EDGE_NOT_ACTUATED                                           // XXXX
 OR.NOT  RELEASE_ENERGIE_DD                                                  // XXXX
 OR.NOT  PMCOPT(PMCOM_TUERANTRIEB_FANUC)
 OR      ODOOR_LOCKED
 OR      PMCOPT(PMCSET_LIGHT_BARRIER)                                        // XXXX
#ifdef ATEST_SUPPLY_2HAND // XXXX
  OR.NOT ATEST_SUPPLY_2HAND                                                  // XXXX
#endif // XXXX
 AND.STK
#endif
#ifdef TMB_DELAY_EMGOK // XXXX
 TMRB    TMB_DELAY_EMGOK 32                                                 // XXXX
#endif

                                            WRT     ANOTSTOP_OK             // XXXX
                                            WRT     E_ESP                   // XXXX
                                            WRT     MANOTSTOP_OK            // XXXX
                                            WRT     XSCEMG                  // XXXX

// XXXX
RD      LOG_1                               RESET   ANTRIEBE_NICHT_SICHER
// XXXX
RD      LOG_1                               RESET   ANTRIEBE_NICHT_SICHER_LL

// XXXX
#ifdef AHYDR_EIN  // XXXX
 RD.NOT      AHYDR_EIN
 AND         ANOTSTOP_OK
 AND.NOT     DUAL_BUT_ZUSTI_BETAETIGT
 AND         SERVICE_MODE_AKTIV              RESET   CHECK_FEEDBACK
#endif

// XXXX
// XXXX
// XXXX

// XXXX
#ifdef EESP1_FEEDBACK  // XXXX
RD          ANOTSTOP_OK
AND         EESP1_FEEDBACK                  SET     CHECK_FEEDBACK
#ifdef FE_ESP
                                            WRT     FE_ESP
#endif
#endif
/*******************************************************************************************/
/**************************************************************************
** XXXXXXXXXXXXXXX
***************************************************************************/

// XXXX
// XXXX

// XXXX

// XXXX
// XXXX
RD.NOT  EODOOR1_CLOSED                      AND     PMCOPT(PMCSET_OD_4131)
RD.STK  EODOOR1_CLOSED                      AND.NOT PMCOPT(PMCSET_OD_4131)
OR.STK                                      WRT     ODOOR1_CLOSED_HM

// XXXX
RD      ODOOR1_CLOSED_HM                    AND     EODOOR1_LOCKED          // XXXX
#ifdef DCS_CROSS_CHECK
OR      DCS_CROSS_CHECK                                                     // XXXX
#endif
RD.NOT.STK  OPT_HATCH_LIKE_ODOOR                                            // XXXX
OR          DACHLUKE_IST_SICHER                                             // XXXX
RD.STK      DUAL_BUT_ZUSTI_BETAETIGT        AND     ESP1_FEEDBACK_LONG
OR.STK      AND.STK
RD.STK  ODOOR1_FEEDBACK_LONG                OR      ODOOR_LOCKED            // XXXX
OR      ATUEREN_ODER_ZUSTIMMUNG
AND.STK                                     WRT     ODOOR_LOCKED


// XXXX
RD        EODOOR1_LOCKED
#ifdef      EODOOR2_LOCKED
AND       EODOOR2_LOCKED
#endif
#ifdef DCS_CROSS_CHECK
OR      DCS_CROSS_CHECK                                                     // XXXX
#endif
                                            WRT     ALL_ODOORS_LOCKED
// XXXX
RD          FKT_G9871C_BIT(5)
OR          FKT_G9871C_BIT(6)               WRT     OPT_HATCH_LIKE_ODOOR
// XXXX

// XXXX

// XXXX
// XXXX
RD.NOT  EMDOOR1_CLOSED                      AND     PMCOPT(PMCSET_MD_4131)
RD.STK  EMDOOR1_CLOSED                      AND.NOT PMCOPT(PMCSET_MD_4131)
OR.STK                                      WRT     MDOOR1_CLOSED_HM

RD      MDOOR1_CLOSED_HM                    AND     EMDOOR1_LOCKED
#ifdef DCS_CROSS_CHECK
 OR      DCS_CROSS_CHECK
#endif
RD.STK  MDOOR1_FEEDBACK_LONG                OR      MDOOR_LOCKED
AND.STK
OR.NOT  PMCOPT(PMCSET_WARTUNGSTUERE1)       WRT     MDOOR_LOCKED

// XXXX


/**************************************************************************
** XXXXXXXXXXXXXXX
***************************************************************************/

// XXXX
// XXXX
// XXXX
// XXXX
// XXXX

// XXXX
RD      MDOOR1_FEEDBACK_LONG
OR      AMDOOR_CLOSED
OR.NOT  PMCOPT(PMCSET_WARTUNGSTUERE1)

AND     E_ESP
AND     MDOOR_LOCKED
TMRB    TMB_MAINTENANCEDOOR_ON_DLY  200     WRT     AMDOOR_CLOSED       // XXXX
                                            WRT     MAMDOOR_CLOSED      // XXXX
                                            WRT     XSCMDO              // XXXX

// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
RD      SERVICE_MODE
TMRB    TMB_SERVICEMODE 2000                WRT     SERVICE_MODE_AKTIV

RD      SERVICE_MODE
AND.NOT SERVICE_MODE_AKTIV                  RESET   ANOTSTOP_OK

// XXXX
// XXXX
// XXXX

// XXXX
RD      AMDOOR_CLOSED
AND     EMDOOR1_FEEDBACK                    SET     CHECK_FEEDBACK
#ifdef FE_MDOOR
                                            WRT     FE_MDOOR
#endif

// XXXX
RD      ATUEREN_ODER_ZUSTIMMUNG
AND     ODOOR_LOCKED                        WRT     AALL_DOOR_CLOSED
                                            WRT     MAALL_DOOR_CLOSED       // XXXX
                                            WRT     XSCSOA                  // XXXX

// XXXX
// XXXX
// XXXX

// XXXX
RD      AALL_DOOR_CLOSED
AND     EODOOR1_FEEDBACK                    SET     CHECK_FEEDBACK
#ifdef FE_ODOOR
                                            WRT     FE_ODOOR
#endif


// XXXX
RD      ALL_ODOORS_LOCKED
OR      DUAL_BUT_ZUSTI_BETAETIGT

RD.STK  ODOOR1_FEEDBACK_LONG
OR      ATUEREN_ODER_ZUSTIMMUNG
// XXXX
AND.STK
RD.NOT.STK OPT_HATCH_LIKE_ODOOR       // XXXX
OR         B3LAD_INLUKE_SICHER_ZU
OR         B3LADER_SICHERT_DACHLUKE
OR         DUAL_BUT_ZUSTI_BETAETIGT
AND.STK
AND     E_ESP
AND     MDOOR_LOCKED
                                            WRT     ATUEREN_ODER_ZUSTIMMUNG
                                            WRT     MATUEREN_ODER_ZUSTIMMUNG    // XXXX
                                            WRT     XSCACK                  // XXXX

// XXXX
// XXXX
// XXXX

// XXXX
RD      ATUEREN_ODER_ZUSTIMMUNG
AND     EODOOR1_FEEDBACK                    SET     CHECK_FEEDBACK
#ifdef FE_ACK
                                            WRT     FE_ACK
#endif



// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX

// XXXX
// XXXX
RD      ATUEREN_ODER_ZUSTIMMUNG
OR      EODOOR1_LOCKED                       // XXXX
#ifdef DCS_CROSS_CHECK
 OR      DCS_CROSS_CHECK
#endif
#ifdef  ELAD_ZAUN_ZU
 OR     ELAD_ZAUN_ZU
#endif
#ifdef B3LAD_INLUKE_SICHER_ZU
RD.NOT.STK  OPT_HATCH_LIKE_ODOOR
OR          B3LAD_INLUKE_SICHER_ZU
#ifdef B3LADER_SICHERT_DACHLUKE
 OR      B3LADER_SICHERT_DACHLUKE
#endif
#ifdef B3LADER_SICHERT_LUKE_ZAUN
 OR          B3LADER_SICHERT_LUKE_ZAUN
#endif // XXXX
OR      DUAL_BUT_ZUSTI_BETAETIGT
AND.STK
#endif
OR      SWI_FUSS_ZU
OR      SWI_FUSS_AUF
AND     E_ESP
#ifndef MC_TYPE_S242
AND     MDOOR_LOCKED                        WRT     CLAMP_POWER_ON
#else
                                            WRT     CLAMP_REL_MDOOR

RD      CLAMP_REL_MDOOR                     AND     MDOOR_LOCKED
                                            WRT     CLAMP_POWER_ON
#endif

#ifdef DIFD_CLAMP_POWER_ON
RD      CLAMP_POWER_ON
DIFD    DIF_CLAMP_POWER_ON                  WRT     DIFD_CLAMP_POWER_ON
#endif

// XXXX
RD      SPANNM_FEEDBACK_LONG
OR      ASPANNMITTEL_ENERGIE
AND     CLAMP_POWER_ON
                                            WRT     ASPANNMITTEL_ENERGIE
                                            WRT     XSCCLP                  // XXXX

// XXXX
// XXXX
// XXXX

// XXXX
RD      ASPANNMITTEL_ENERGIE
AND     E_SPANNMITTEL_FEEDBACK              SET     CHECK_FEEDBACK
#ifdef FE_CLAMP
                                            WRT     FE_CLAMP
#endif

RD      SWI_SICHERHEIT_EIN                  TMRBF   TMBF_SWI_SICHERH_OFF_DLY   5000
                                            WRT     MSWI_SICHERHEIT_OFF_DLY

// XXXX
RD      ODOOR_LOCKED
AND     MDOOR_LOCKED
AND     MSWI_SICHERHEIT_OFF_DLY             WRT     ALL_DOOR_CLOSED

// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
#ifdef ADOOR_STATUS_TO_LOADER
 RD      DOORSTATUS_FEEDBACK_LONG           // XXXX
 AND     ODOOR1_FEEDBACK_LONG               // XXXX
 OR      ADOOR_STATUS_TO_LOADER             // XXXX
 RD.STK  EODOOR1_LOCKED
#ifdef DCS_CROSS_CHECK
 OR      DCS_CROSS_CHECK
#endif
#ifdef  ELAD_ZAUN_ZU
 OR     ELAD_ZAUN_ZU
#endif
 AND.STK
 AND    MDOOR_LOCKED
 AND     SWI_SICHERHEIT_EIN
 RD.STK  E_XESP
 OR.NOT  PMCOPT(PMCSET_LOAD_ESTOP_INTL)
 AND.STK                                    WRT     ADOOR_STATUS_TO_LOADER
                                            WRT     MADOOR_STATUS_TO_LOADER     // XXXX
                                            WRT     XSCFEN                    // XXXX

// XXXX
RD      ADOOR_STATUS_TO_LOADER
AND     DOORSTATUS_FEEDBACK_LONG            SET     CHECK_FEEDBACK
#ifdef FE_DOST
                                            WRT     FE_DOST
#endif
#endif

// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
#ifdef ASAFETY_MACHINEROOM
 RD      SAFEMCROOM_FEEDBACK_LONG           // XXXX
 OR      ASAFETY_MACHINEROOM                // XXXX
 AND     ALL_DOOR_CLOSED                    WRT     ASAFETY_MACHINEROOM
                                            WRT     MASAFETY_MACHINEROOM        // XXXX
                                            WRT     XSCADC                      // XXXX

// XXXX
RD      ASAFETY_MACHINEROOM
AND     SAFEMCROOM_FEEDBACK_LONG            SET     CHECK_FEEDBACK
#ifdef FE_SAMR
                                            WRT     FE_SAMR
#endif
#endif // XXXX

// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
#ifdef ASCHUTZ1_GESCHLOSSEN
 RD      SAFESCHUTZ1_FEEDBACK_LONG           // XXXX
 OR      ASCHUTZ1_GESCHLOSSEN                // XXXX
 RD.STK  ESCHUTZ1_ZU
 OR      ALL_DOOR_CLOSED                    AND.STK
                                            WRT     ASCHUTZ1_GESCHLOSSEN
                                            WRT     MASCHUTZ1_GESCHLOSSEN        // XXXX
                                            // XXXX

// XXXX
RD      ASCHUTZ1_GESCHLOSSEN
AND     SAFESCHUTZ1_FEEDBACK_LONG         SET     CHECK_FEEDBACK

#ifdef FE_ASCHUTZ1
                                          WRT     FE_ASCHUTZ1
#endif // XXXX

#endif // XXXX

/**************************************************************************
** XXXXXXXXXXXXXXX
***************************************************************************/

// XXXX
RD      EMMC_STATUS                         WRT     _SMC

// XXXX
// XXXX
// XXXX
// XXXX
// XXXX

RD      _MCFV1                              OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(1))
RD.STK  _MCFV2                              OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(2))
AND.STK
RD.STK  _MCFV3                              OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(3))
AND.STK
RD.STK  _MCFV4                              OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(4))
AND.STK
RD.STK  _MCFV5                              OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(5))
AND.STK
RD.STK  _MCFV6                              OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(6))
AND.STK
RD.STK  _MCFV7                              OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(7))
AND.STK
RD.STK  _MCFV8                              OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(8))
AND.STK
RD.STK  _MCFV9                              OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(9))
AND.STK
RD.STK  _MCFV10                             OR.NOT  PMCOPT(PMCSET_SERVO_ACHSE(10))
AND.STK

// XXXX
RD.STK  _MCFP1                              OR.NOT  PMCOPT(PMCSET_SPINDLE(1))
AND.STK
RD.STK  _MCFP2                              OR.NOT  PMCOPT(PMCSET_SPINDLE(2))
AND.STK
RD.STK  _MCFP3                              OR.NOT  PMCOPT(PMCSET_SPINDLE(3))
AND.STK
RD.STK  _MCFP4                              OR.NOT  PMCOPT(PMCSET_SPINDLE(4))
AND.STK

// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
AND     _DCALM
AND     _MCF                                // XXXX
AND     SWI_SICHERHEIT_EIN
AND     NC_READY_PMC1
RD.STK  E_ESP
OR      MCC_EIN_OK
AND.STK
#ifndef MC_TYPE_S242
AND     MDOOR_LOCKED
#endif
                                            WRT     MCC_EIN_OK

// XXXX
RD      MCC_EIN_OK
AND.NOT MCC_OFF_TEST                        // XXXX
RD.STK  EMMC_STATUS
OR      AMCC_EIN
AND.STK
TMRB    TMB_MCC_ON_DLY 200                  // XXXX
                                            WRT     AMCC_EIN
                                            WRT     MAMCC_EIN   // XXXX
                                            WRT     XSCMCC                  // XXXX


// XXXX

// XXXX
// XXXX
// XXXX

// XXXX
RD.NOT  ODOOR_LOCKED
AND     AMCC_EIN
TMRB    TMB_62500_DCS_DELAY 500             WRT     DCS_CONTROL_AKTIV


RD.NOT  PMCOPT(PMCSET_SERVO_ACHSE(1))
OR.NOT  DCS_CONTROL_AKTIV                   WRT     _VLDV1

RD.NOT  PMCOPT(PMCSET_SERVO_ACHSE(2))
OR.NOT  DCS_CONTROL_AKTIV                   WRT     _VLDV2

RD.NOT  PMCOPT(PMCSET_SERVO_ACHSE(3))
OR.NOT  DCS_CONTROL_AKTIV                   WRT     _VLDV3

RD.NOT  PMCOPT(PMCSET_SERVO_ACHSE(4))
OR.NOT  DCS_CONTROL_AKTIV                   WRT     _VLDV4

RD.NOT  PMCOPT(PMCSET_SERVO_ACHSE(5))
OR.NOT  DCS_CONTROL_AKTIV                   WRT     _VLDV5

RD.NOT  PMCOPT(PMCSET_SERVO_ACHSE(6))
OR.NOT  DCS_CONTROL_AKTIV                   WRT     _VLDV6

RD.NOT  PMCOPT(PMCSET_SERVO_ACHSE(7))
OR.NOT  DCS_CONTROL_AKTIV                   WRT     _VLDV7

RD.NOT  PMCOPT(PMCSET_SERVO_ACHSE(8))
OR.NOT  DCS_CONTROL_AKTIV                   WRT     _VLDV8

RD.NOT  PMCOPT(PMCSET_SERVO_ACHSE(9))
OR.NOT  DCS_CONTROL_AKTIV                   WRT     _VLDV9

#ifdef MC_TYPE_S242
 RD.NOT  PMCOPT(PMCSET_SERVO_ACHSE(10))
 OR.NOT  DCS_CONTROL_AKTIV                  WRT     _VLDV10
#endif

/**************************************************************************
** XXXXXXXXXXXXXXX
***************************************************************************

***************************************************************************/
// XXXX
// XXXX

// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX

RD.NOT  SVA1
AND.NOT SVB1
AND.NOT ODOOR_LOCKED
AND     E_ESP
AND     AMCC_EIN                            WRT     SVZR1

RD      SVZR1                               WRT     SVZR2
                                            WRT     SVZR3   // XXXX
                                            WRT     SVZR4
                                            WRT     SVZR5
                                            WRT     SVZR7   // XXXX
                                            WRT     SVZR8
// XXXX
#ifndef MC_TYPE_S242
                                            WRT     SVZR6
#endif // XXXX

#ifdef MC_TYPE_S242
                                            WRT     SVZR9
                                            WRT     SVZR10
#endif // XXXX

#ifndef MC_TYPE_S242
RD.NOT  SVA9
AND.NOT SVB9
AND.NOT ODOOR_LOCKED
AND     E_ESP
AND     AMCC_EIN                            WRT     SVZR9
#endif // XXXX


// XXXX
// XXXX
RD      OPT_HATCH_LIKE_ODOOR                                                   // XXXX
AND     CLAMP_POWER_ON
AND     EODOOR1_LOCKED
#ifdef  ELAD_ZAUN_ZU                                                            // XXXX
RD.STK  CLAMP_POWER_ON
AND     ELAD_ZAUN_ZU
OR.STK
#endif
OR      DUAL_BUT_ZUSTI_BETAETIGT
AND.NOT ODOOR_LOCKED                                                            // XXXX
AND     MDOOR_LOCKED
AND     E_ESP
AND.NOT SVB1                                SET     SVA1

// XXXX
// XXXX

// XXXX
// XXXX
RD      OPTION_SET_IMP                      SET_WORD(TM_ADR(TM_ODOOR_UNLOCKED), 120)
RD      OPTION_SET_IMP                      SET_WORD(TM_ADR(TM_62500_SVA6), 120)

// XXXX
RD.NOT  DUAL_BUT_ZUSTI_BETAETIGT
AND.NOT CLAMP_POWER_ON
OR      ODOOR_LOCKED
OR.NOT  E_ESP
TMR     TM_ODOOR_UNLOCKED                   RESET   SVA1

// XXXX
// XXXX
// XXXX

// XXXX
// XXXX

// XXXX
RD      SVA1                                WRT     SVA2
                                            WRT     SVA4
                                            WRT     SVA5
#ifndef MC_TYPE_S242
                                            WRT     SVA6
#endif // XXXX
                                            WRT     SVA8
#ifdef MC_TYPE_S242
                                            WRT     SVA9
                                            WRT     SVA10
#endif // XXXX

// XXXX
RD      SVA1        AND.NOT SVB3            WRT     SVA3
RD      SVA1        AND.NOT SVB7            WRT     SVA7

// XXXX
RD      CLAMP_POWER_ON
OR      SVA1
#ifdef MC_TYPE_S242
                                            SET     SVA6
#endif // XXXX

#ifndef MC_TYPE_S242
                                            SET     SVA9
#endif // XXXX

// XXXX
RD      ODOOR_LOCKED
#ifdef MC_TYPE_S242
                                            RESET   SVA6
#endif

#ifndef MC_TYPE_S242
                                            RESET   SVA9
#endif // XXXX

// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX

#ifdef EA_C_ACHSE_FREILAUF
 RD PMCOPT(PMCSET_SPINDLE_SAFE_OFF)
 AND.NOT    MEA_C_ACHSE_FREILAUF
 // XXXX
 AND.NOT ODOOR_LOCKED
 AND.NOT DUAL_BUT_ZUSTI_BETAETIGT
 AND     E_ESP                              RESET   SVZR3   // XXXX
                                            WRT     SVB3

 // XXXX
 RD     PMCOPT(PMCSET_7AXIS_SYNC_3AXIS)
 AND    SVB3                                RESET   SVZR7   // XXXX
                                            WRT     SVB7
 // XXXX
 RD     PMCOPT(PMCSET_6AXIS_SYNC_3AXIS)
 AND    SVB3                                RESET   SVZR6   // XXXX
                                            WRT     SVB6
#endif


/**************************************************************************
** XXXXXXXXXXXXXXX
***************************************************************************/
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX

RD      LOG_1                               RESET   W_ESP_GLOBAL

RD      CHECK_FEEDBACK
TMRB    TMB_CHECK_FEEDBACK 800              RESET   ANOTSTOP_OK
                                            RESET   E_ESP
                                            SET     W_ESP_GLOBAL

// XXXX
RD      LOG_1                               RESET   CHECK_FEEDBACK

/**************************************************************************
** XXXXXXXXXXXXXXX
***************************************************************************/
// XXXX
// XXXX
// XXXX
// XXXX


#ifndef MC_TYPE_S242
// XXXX
// XXXX
// XXXX
RD  PMCOPT(PMCSET_SPINDLE(1))
OR  PMCOPT(PMCSET_SPINDLE(2))               WRT     PMCOPT(PMCSM_DCS_OD_AC_SPINDLE)
#endif

/**************************************************************************
** XXXXXXXXXXXXXXX
***************************************************************************/
// XXXX
// XXXX
// XXXX
// XXXX

/*

// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX
// XXXX

#endif
*/

/**************************************************************************
** XXXXXXXXXXXXXXX
***************************************************************************/
/*
*/

RD      DUAL_BUT_ZUSTI_BETAETIGT
OR      ZYKLUS_LAEUFT
AND     SERVICE_MODE_AKTIV                  SET     CYCLE_SERVICE_MODE

// XXXX
RD      CYCLE_SERVICE_MODE
AND.NOT DUAL_BUT_ZUSTI_BETAETIGT
                                            SET     SVA1    // XXXX
                                            SET     SVB1
                                            SET     SVA2    // XXXX
                                            SET     SVB2
                                            SET     SVA3    // XXXX
                                            SET     SVB3

#ifdef MC_TYPE_S242
                                            SET     SVA4    // XXXX
                                            SET     SVB4
                                            SET     SVA8    // XXXX
                                            SET     SVB8
#endif

// XXXX

RD.NOT  CYCLE_SERVICE_MODE                  RESET   SVB1
                                            RESET   SVB2
                                            // XXXX
#ifdef MC_TYPE_S242
                                            RESET   SVB4
                                            RESET   SVB8
#endif

// XXXX
RD      SERVICE_MODE_AKTIV
AND     DUAL_BUT_ZUSTI_BETAETIGT            SET     SVB2

// XXXX
RD.NOT  E_XESP                              RESET   SERVICE_MODE
                                            RESET   CYCLE_SERVICE_MODE
 /**************************************************************************
** XXXXXXXXXXXXXXX
****************************************************************************
*
*/
#ifdef ETWO_HAND_START

// XXXX
RD     PMCOPT(PMCSET_2HANDSTART_IMP)
OR     PMCOPT(PMCSET_2HANDSTART)            WRT     OPTION_2_HAND

// XXXX
RD.NOT  OPTION_2_HAND   JMP 0

 RD      ETWO_HAND_START
#ifdef ETWO_HAND_START1  // XXXX
   OR   ETWO_HAND_START1
#endif // XXXX
#ifdef BUT_ZYK_START1  // XXXX
   OR   BUT_ZYK_START1
#endif // XXXX
 DIFU    TWO_HAND_ON                        SET     TWO_HAND_CHANEL_SET

 // XXXX
 RD.NOT  ETWO_HAND_START
#ifdef ETWO_HAND_START1  // XXXX
  AND.NOT   ETWO_HAND_START1
#endif // XXXX
                                            RESET   TWO_HAND_CHANEL_SET

 RD      TWO_HAND_SWITCH_OK
 DIFD    TWO_HAND_OFF                       RESET   TWO_HAND_CHANEL_SET

 // XXXX
 // XXXX
// XXXX
#ifdef TWO_HANDSTART_IMP_200  // XXXX
 RD      TWO_HAND_SWITCH_OK
 AND.NOT MCMD_DOING(63)
 TMRBF   TMBF_IMPULS_TWO_HAND 500           WRT     TWO_HANDSTART_IMP_200   // XXXX
#endif

 // XXXX
 RD.NOT  TWO_HAND_CHANEL_SET
 AND     R_TWO_HAND_START

 RD.STK  TWO_HAND_CHANEL_SET
 AND.NOT R_TWO_HAND_START
 OR.STK
 TMRB    TMB_TWO_HAND   2000                RESET   TWO_HAND_CHANEL_SET

JMPE
#endif // XXXX

 /**************************************************************************
** XXXXXXXXXXXXXXX
****************************************************************************
*/
// XXXX

RD      STUDERWIN_USER_ADMIN                WRT     PROGRAMMER_ENABLE
                                            WRT     MEMORY_WRITE_ENABLE
                                            WRT     EDIT_ENABLE
                                            WRT     WRITE_TO_F_ROM
                                            WRT     ALLOW_PMC_STOP
                                            WRT     DISP_IO_GROUP_SELECT_SCREEN
                                            WRT.NOT PROTECT_PMC_PARAMETER

/****************************************************************************
** XXXXXXXXXXXXXXX
****************************************************************************/
#ifdef AMCC2_EIN
// XXXX

 // XXXX
 // XXXX
 // XXXX
RD.NOT  PMCOPT (PMCSET_SPINDLE(1))
AND.NOT PMCOPT (PMCSET_SPINDLE(2))              JMP 0

 RD      MCC_EIN_OK
 AND.NOT MCC_OFF_TEST                       // XXXX
 RD.STK  EMMC2_STATUS
 OR      AMCC2_EIN
 AND.STK                                        WRT   AMCC2_EIN
                                                WRT   MAMCC2_EIN        // XXXX
JMPE
#endif // XXXX

/****************************************************************************
** XXXXXXXXXXXXXXX
****************************************************************************/
// XXXX
// XXXX
// XXXX
#ifdef DCS_CROSS_CHECK
 RD      LOG_1                  CLEAR_DWORD (byte:SAFE_WHEEL_COVER(0))
#endif


// XXXX
#ifdef MC_TYPE_S110
 RD      ESCHUTZ1_ZU            WRT SAFE_WHEEL_COVER(3) // XXXX
                                WRT SAFE_WHEEL_COVER(7) // XXXX

#endif

endmod
