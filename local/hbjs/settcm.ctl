Load data
append into table SETT_ITEM_CM
TRAILING NULLCOLS
(
REPORT_ID            position(1  :6  ),
ACCT_ITEM_NAME       position(7  :66 ),
DETAIL_ITEM_NAME     position(67 :126),
TOTAL_CNT            position(127:135),
TOTAL_MIN            position(136:144),
DISTANCE_FEE         position(145:153),
SETT_RULE            position(154:213),
CHARGE               position(214:225),
LATN_ID              position(226:229),
SETT_CYCLE_ID        position(230:235),
PAGE                 position(236:237),
LINE                 position(238:240)
)
