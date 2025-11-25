# D-META
世界線變動率探測儀

# 藍芽指令

- N : 報時
- t : 設定時間，格式HHMMSS
- d : 設定日期，格式YYMMDDW
- m : 設定 mod
  - DMETA_MOD_CLOCK 0
  - DMETA_MOD_TEMP  1
  - DMETA_MOD_DMETA 2
  - DMETA_MOD_JUMP  3
 
- c : 設定單管 管子|數字|點顯示 ex: c081 : 第0根顯示8，點顯示
- j : 隨機跳躍
- ja+7位數字 : 精準跳躍，跳過小數點設置7個數字
