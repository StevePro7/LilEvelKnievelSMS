M:command_manager
F:G$engine_command_manager_init$0_0$0({2}DF,SV:S),Z,0,0,0,0,0
S:Lcommand_manager.engine_command_manager_init$co$1_0$24({2}DG,STtag_struct_command_object:S),R,0,0,[]
S:Lcommand_manager.engine_command_manager_init$index$1_0$24({1}SC:U),R,0,0,[e]
F:G$engine_command_manager_load$0_0$0({2}DF,SV:S),Z,0,0,0,0,0
S:Lcommand_manager.engine_command_manager_load$storage_frame_index$1_0$27({2}DG,SI:U),B,1,4
S:Lcommand_manager.engine_command_manager_load$storage_this_command$1_0$27({2}DG,SC:U),B,1,6
S:Lcommand_manager.engine_command_manager_load$co$1_0$28({2}DG,STtag_struct_command_object:S),R,0,0,[]
S:Lcommand_manager.engine_command_manager_load$index$1_0$28({1}SC:U),R,0,0,[c]
S:Lcommand_manager.engine_command_manager_load$sloc0$0_1$0({2}DD,SI:U),B,1,-2
F:G$engine_command_manager_record$0_0$0({2}DF,SV:S),Z,0,0,0,0,0
S:Lcommand_manager.engine_command_manager_record$frame$1_0$31({2}SI:U),B,1,4
S:Lcommand_manager.engine_command_manager_record$command$1_0$31({1}SC:U),B,1,6
S:Lcommand_manager.engine_command_manager_record$co$1_0$32({2}DG,STtag_struct_command_object:S),R,0,0,[]
F:G$engine_command_manager_update$0_0$0({2}DF,SV:S),Z,0,0,0,0,0
S:Lcommand_manager.engine_command_manager_update$command$1_0$34({1}SC:U),B,1,4
S:Lcommand_manager.engine_command_manager_update$co$1_0$35({2}DG,STtag_struct_command_object:S),R,0,0,[]
F:G$engine_command_manager_build$0_0$0({2}DF,SC:U),Z,0,0,0,0,0
S:Lcommand_manager.engine_command_manager_build$state$1_0$36({1}SC:U),B,1,4
S:Lcommand_manager.engine_command_manager_build$input1$1_0$36({1}SC:U),B,1,5
S:Lcommand_manager.engine_command_manager_build$input2$1_0$36({1}SC:U),B,1,6
S:Lcommand_manager.engine_command_manager_build$input3$1_0$36({1}SC:U),B,1,7
S:Lcommand_manager.engine_command_manager_build$input4$1_0$36({1}SC:U),B,1,8
S:Lcommand_manager.engine_command_manager_build$input5$1_0$36({1}SC:U),B,1,9
S:Lcommand_manager.engine_command_manager_build$input6$1_0$36({1}SC:U),B,1,10
S:Lcommand_manager.engine_command_manager_build$po$1_0$37({2}DG,STtag_struct_player_object:S),R,0,0,[]
S:Lcommand_manager.engine_command_manager_build$ho$1_0$37({2}DG,STtag_struct_hack_object:S),R,0,0,[]
S:Lcommand_manager.engine_command_manager_build$command$1_0$37({1}SC:U),R,0,0,[c]
T:Fcommand_manager$tag_struct_player_object[({0}S:S$initX$0_0$0({1}SC:U),Z,0,0)({1}S:S$posnX$0_0$0({2}SI:U),Z,0,0)({3}S:S$tileX$0_0$0({2}SI:U),Z,0,0)({5}S:S$lookX$0_0$0({1}SC:U),Z,0,0)({6}S:S$posnY$0_0$0({1}SC:U),Z,0,0)({7}S:S$tileY$0_0$0({1}SC:U),Z,0,0)({8}S:S$leapY$0_0$0({2}SI:U),Z,0,0)({10}S:S$drawX$0_0$0({1}SC:U),Z,0,0)({11}S:S$drawY$0_0$0({1}SC:U),Z,0,0)({12}S:S$player_state$0_0$0({1}SC:U),Z,0,0)({13}S:S$jumper_index$0_0$0({1}SC:U),Z,0,0)({14}S:S$deltaY_index$0_0$0({1}SC:U),Z,0,0)({15}S:S$player_frame$0_0$0({1}SC:U),Z,0,0)({16}S:S$player_lives$0_0$0({1}SC:U),Z,0,0)({17}S:S$motion_count$0_0$0({1}SC:U),Z,0,0)]
T:Fcommand_manager$tag_struct_hack_object[({0}S:S$hack_delay$0_0$0({1}SC:U),Z,0,0)({1}S:S$hack_isgod$0_0$0({1}SC:U),Z,0,0)({2}S:S$hack_inair$0_0$0({1}SC:U),Z,0,0)({3}S:S$hack_ultra$0_0$0({1}SC:U),Z,0,0)({4}S:S$hack_music$0_0$0({1}SC:U),Z,0,0)({5}S:S$hack_sound$0_0$0({1}SC:U),Z,0,0)({6}S:S$hack_riffs$0_0$0({1}SC:U),Z,0,0)]
T:Fcommand_manager$tag_struct_command_object[({0}S:S$frame_index$0_0$0({2}SI:U),Z,0,0)({2}S:S$curr_command$0_0$0({1}SC:U),Z,0,0)({3}S:S$prev_command$0_0$0({1}SC:U),Z,0,0)]
S:G$command_frame_index$0_0$0({0}DA0d,SI:U),E,0,0
S:G$command_this_command$0_0$0({0}DA0d,SC:U),E,0,0
S:G$global_hack_object$0_0$0({7}STtag_struct_hack_object:S),E,0,0
S:G$jump_array_ptr$0_0$0({0}DA0d,DG,SI:S),E,0,0
S:G$flip_array_ptr$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:G$global_player_object$0_0$0({18}STtag_struct_player_object:S),E,0,0
S:G$global_command_object$0_0$0({4}STtag_struct_command_object:S),E,0,0
S:G$engine_font_manager_char$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_text$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_data$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_valu$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_hack_manager_init$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_hack_manager_load$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_init$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_initX$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_loadX$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_loadY$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_lives$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_get_deltaX$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_player_manager_get_deltaY$0_0$0({2}DF,SI:S),C,0,0
S:G$engine_player_manager_set_action$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_horz$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_vert$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_bounds$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_animate$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_collision$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_player_manager_right$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_down$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_draw$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_head$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_finish$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_player_manager_dying$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_pass$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_pass_frame$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_dead$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_count$0_0$0({2}DF,SV:S),C,0,0
