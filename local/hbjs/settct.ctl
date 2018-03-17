Load data
append into table SETT_ITEM_CT
TRAILING NULLCOLS
(
REPORT_ID            position(1  :6  ),
ACCT_ITEM_NAME       position(7  :66 ),
DETAIL_ITEM_NAME     position(67 :126),
TOTAL_CNT            position(127:135),
TOTAL_MIN            position(136:144),
SETT_RULE            position(145:204),
CHARGE               position(205:216),
LATN_ID              position(217:220),
SETT_CYCLE_ID        position(221:226),
PAGE                 position(227:228),
LINE                 position(229:231)
)
