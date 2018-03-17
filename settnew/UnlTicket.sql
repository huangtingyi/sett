--�߶�
DELETE FROM ST_@NETWORK@_UNNORMAL_GE_TICKET_@MONTH@ PARTITION(PART@BILLDATE@);
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_GE_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CM_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_GE_@MONTH@ WHERE SETT_DATE='@BILLDATE@') 
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE FEE_TYPE='0'));
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_GE_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CT_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_GE_@MONTH@ WHERE SETT_DATE='@BILLDATE@')
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE FEE_TYPE='0'));
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_GE_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CTC_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_GE_@MONTH@ WHERE SETT_DATE='@BILLDATE@')
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE FEE_TYPE='0'));
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_GE_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CRC_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_GE_@MONTH@ WHERE SETT_DATE='@BILLDATE@')
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE FEE_TYPE='0'));
COMMIT;

--����
DELETE FROM ST_@NETWORK@_UNNORMAL_CC_TICKET_@MONTH@ PARTITION(PART@BILLDATE@);
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_CC_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CM_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_CC_@MONTH@ WHERE SETT_DATE='@BILLDATE@') 
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE CALL_TYPE='1'));
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_CC_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CT_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_CC_@MONTH@ WHERE SETT_DATE='@BILLDATE@')
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE CALL_TYPE='1'));
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_CC_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CTC_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_CC_@MONTH@ WHERE SETT_DATE='@BILLDATE@')
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE CALL_TYPE='1'));
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_CC_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CRC_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_CC_@MONTH@ WHERE SETT_DATE='@BILLDATE@')
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE CALL_TYPE='1'));
COMMIT;

--��Ƶ
DELETE FROM ST_@NETWORK@_UNNORMAL_CP_TICKET_@MONTH@ PARTITION(PART@BILLDATE@);
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_CP_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CM_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_CP_@MONTH@ WHERE SETT_DATE='@BILLDATE@') 
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE CALL_TYPE='1'));
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_CP_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CT_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_CP_@MONTH@ WHERE SETT_DATE='@BILLDATE@')
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE CALL_TYPE='1'));
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_CP_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CTC_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_CP_@MONTH@ WHERE SETT_DATE='@BILLDATE@')
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE CALL_TYPE='1'));
COMMIT;

INSERT INTO ST_@NETWORK@_UNNORMAL_CP_TICKET_@MONTH@
(SELECT * FROM ST_@NETWORK@_TICKET_CRC_@MONTH@_TEST PARTITION(PART@BILLDATE@)
WHERE 
MSISDN IN(SELECT DISTINCT MSISDN FROM AN_STAT_UNL_TICKET_@NETWORK@_CP_@MONTH@ WHERE SETT_DATE='@BILLDATE@')
AND 
PROD_ID IN (SELECT PROD_ID FROM PARAM.TICKET_TYPE_MAP WHERE CALL_TYPE='1'));
COMMIT;
