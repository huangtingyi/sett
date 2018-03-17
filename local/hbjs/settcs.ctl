Load data
append into table SETT_ITEM_CS
TRAILING NULLCOLS
(
REPORT_ID            position(1  :6  ),
ACCT_ITEM_NAME       position(7  :66 ),
DETAIL_ITEM_NAME     position(67 :126),
TOTAL_DURATION       position(127:138),
TOTAL_CNT            position(139:147),
TOTAL_SEC            position(148:159),
TOTAL_MIN            position(160:168),
CHARGE               position(179:180),
LATN_ID              position(181:184),
SETT_CYCLE_ID        position(185:190),
PAGE                 position(191:192),
LINE                 position(193:195)
)
