Load data
append into table SETT_ITEM_CMSMS
TRAILING NULLCOLS
(
 REPORT_ID            position(1:6    ),
 MO_CNT               position(7:18   ),
 MT_CNT               position(19:30  ),
 PAY_FEE              position(31:39  ),
 INCOME_FEE           position(40:48  ),
 SETT_RULE            position(49:108 ),
 CHARGE               position(109:120),
 LATN_ID              position(121:124),
 SETT_CYCLE_ID        position(125:130),
 PAGE                 position(131:132),
 LINE                 position(133:135)
 )
