M:intro_screen
F:Fintro_screen$print$0_0$0({2}DF,SV:S),C,0,0,0,0,0
S:Lintro_screen.print$index$1_0$110({1}SC:U),B,1,4
S:Lintro_screen.print$x$1_0$110({1}SC:U),B,1,5
S:Lintro_screen.print$y$1_0$110({1}SC:U),B,1,6
F:G$screen_intro_screen_load$0_0$0({2}DF,SV:S),Z,0,0,0,0,0
S:Lintro_screen.screen_intro_screen_load$col$1_0$112({1}SC:U),R,0,0,[]
S:Lintro_screen.screen_intro_screen_load$row$1_0$112({1}SC:U),R,0,0,[]
F:G$screen_intro_screen_update$0_0$0({2}DF,SV:S),Z,0,0,0,0,0
S:Lintro_screen.screen_intro_screen_update$screen_type$1_0$113({2}DG,SC:U),B,1,4
S:Lintro_screen.screen_intro_screen_update$input1$1_0$114({1}SC:U),R,0,0,[c]
S:Lintro_screen.screen_intro_screen_update$delay$1_0$114({1}SC:U),R,0,0,[l]
T:Fintro_screen$tag_struct_scroll_object[({0}S:S$scrollLeftX$0_0$0({1}SC:U),Z,0,0)({1}S:S$scrollRight$0_0$0({1}SC:U),Z,0,0)({2}S:S$scrollColumn$0_0$0({2}SI:U),Z,0,0)({4}S:S$scrollChecks$0_0$0({2}SI:U),Z,0,0)({6}S:S$scrollPoints$0_0$0({2}SI:U),Z,0,0)({8}S:S$scrollFinish$0_0$0({2}SI:U),Z,0,0)({10}S:S$scrollLeftX0$0_0$0({1}SC:U),Z,0,0)({11}S:S$scrollLeftX1$0_0$0({1}SC:U),Z,0,0)({12}S:S$scrollLeftX2$0_0$0({1}SC:U),Z,0,0)({13}S:S$scrollLeftX3$0_0$0({1}SC:U),Z,0,0)({14}S:S$scrollLeftX4$0_0$0({1}SC:U),Z,0,0)({15}S:S$scrollLeftX5$0_0$0({1}SC:U),Z,0,0)({16}S:S$scroll_half$0_0$0({1}SC:U),Z,0,0)({17}S:S$lineCnt$0_0$0({1}SC:U),Z,0,0)]
T:Fintro_screen$tag_struct_game_object[({0}S:S$game_difficulty$0_0$0({1}SC:U),Z,0,0)({1}S:S$game_world$0_0$0({1}SC:U),Z,0,0)({2}S:S$game_round$0_0$0({1}SC:U),Z,0,0)({3}S:S$game_level$0_0$0({1}SC:U),Z,0,0)({4}S:S$game_point$0_0$0({1}SC:U),Z,0,0)({5}S:S$game_saved$0_0$0({1}SC:U),Z,0,0)({6}S:S$game_start$0_0$0({1}SC:U),Z,0,0)({7}S:S$game_music$0_0$0({1}SC:U),Z,0,0)({8}S:S$game_cloud$0_0$0({1}SC:U),Z,0,0)({9}S:S$game_isgod$0_0$0({1}SC:U),Z,0,0)({10}S:S$game_sheet$0_0$0({1}SC:U),Z,0,0)]
T:Fintro_screen$tag_struct_frame_object[({0}S:S$frame_count$0_0$0({2}SI:U),Z,0,0)]
T:Fintro_screen$tag_struct_delay_object[({0}S:S$delay_value$0_0$0({2}SI:U),Z,0,0)({2}S:S$delay_timer$0_0$0({2}SI:U),Z,0,0)]
T:Fintro_screen$tag_struct_reset_object[({0}S:S$reset_value$0_0$0({2}SI:U),Z,0,0)({2}S:S$reset_timer$0_0$0({2}SI:U),Z,0,0)]
S:G$global_game_object$0_0$0({11}STtag_struct_game_object:S),E,0,0
S:G$global_scroll_object$0_0$0({18}STtag_struct_scroll_object:S),E,0,0
S:G$global_delay_object$0_0$0({4}STtag_struct_delay_object:S),E,0,0
S:G$global_frame_object$0_0$0({2}STtag_struct_frame_object:S),E,0,0
S:G$global_reset_object$0_0$0({4}STtag_struct_reset_object:S),E,0,0
S:G$locale_object_texts$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:G$locale_object_blank$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:G$locale_object_difficulty$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:G$locale_object_intro$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:G$song_object_texts$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:G$riff_object_texts$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:Fintro_screen$delay$0_0$0({1}SC:U),E,0,0
S:G$engine_font_manager_char$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_text$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_data$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_valu$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_init$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_set_cloud_form$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_set_difficulty$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_set_level_data$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_set_game_saved$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_set_game_start$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_set_game_music$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_set_game_sheet$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_inc_checkpoint$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_graphics_manager_common$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_graphics_manager_screen$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_graphics_manager_sea$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_graphics_manager_clouds$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_graphics_manager_title$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_graphics_manager_image$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_graphics_manager_image_flip$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_graphics_manager_level_stats$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_graphics_manager_level_texts$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_input_manager_init$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_input_manager_update$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_input_manager_hold$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_move$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_scroll_manager_load$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_scroll_manager_update$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_scroll_manager_full_load$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_scroll_manager_full_update$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_scroll_manager_para_load$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_scroll_manager_para_update$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_scroll_manager_demo_update$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_delay_manager_load$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_delay_manager_update$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_delay_manager_draw$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_frame_manager_load$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_frame_manager_update$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_frame_manager_draw$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_reset_manager_load$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_reset_manager_update$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_reset_manager_reset$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_init$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VDPturnOnFeature$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VDPturnOffFeature$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_VDPFEATURE_EXTRAHEIGHT$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_SHIFTSPRITES$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_HIDEFIRSTCOL$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_LEFTCOLBLANK$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_LOCKHSCROLL$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_LOCKVSCROLL$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_ZOOMSPRITES$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_USETALLSPRITES$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_240LINES$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_224LINES$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_FRAMEIRQ$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_SHOWDISPLAY$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_SMS_displayOn$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_displayOff$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setBGScrollX$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setBGScrollY$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setBackdropColor$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_useFirstHalfTilesforSprites$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setSpriteMode$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SPRITEMODE_NORMAL$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SPRITEMODE_TALL$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SPRITEMODE_ZOOMED$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SPRITEMODE_TALL_ZOOMED$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_mapROMBank$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_enableSRAM$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_enableSRAMBank$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_disableSRAM$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_SRAM$0_0$0({2}DF,DG,SC:U),C,0,0
S:G$devkit_SMS_waitForVBlank$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_crt0_RST08$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_crt0_RST18$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setTile$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setAddr$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_XYtoADDR$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setNextTileatXY$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setNextTileatLoc$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setNextTileatAddr$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setTileatXY$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_TILEtoADDR$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_TILE_FLIPPED_X$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_TILE_FLIPPED_Y$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_TILE_USE_SPRITE_PALETTE$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_TILE_PRIORITY$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_SMS_loadTiles$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_load1bppTiles$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadPSGaidencompressedTilesatAddr$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadPSGaidencompressedTiles$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_loadZX7compressedTilesatAddr$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_loadZX7compressedTiles$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_loadaPLibcompressedTilesatAddr$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_loadaPLibcompressedTiles$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadTileMap$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadTileMapArea$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadSTMcompressedTileMapatAddr$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadSTMcompressedTileMap$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadSTMcompressedTileMapArea$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_initSprites$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addSprite$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addTwoAdjoiningSprites$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addThreeAdjoiningSprites$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_reserveSprite$0_0$0({2}DF,SC:S),C,0,0
S:G$devkit_SMS_updateSpritePosition$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_updateSpriteImage$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_hideSprite$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setClippingWindow$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addSpriteClipping$0_0$0({2}DF,SC:S),C,0,0
S:G$devkit_SMS_finalizeSprites$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_copySpritestoSAT$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setBGPaletteColor$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setSpritePaletteColor$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadBGPalette$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadSpritePalette$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setNextBGColoratIndex$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setNextSpriteColoratIndex$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setColor$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_RGB$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_RGB8$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_loadBGPaletteHalfBrightness$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadSpritePaletteHalfBrightness$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_zeroBGPalette$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_zeroSpritePalette$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_configureTextRenderer$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_autoSetUpTextRenderer$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_decompressZX7$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_getKeysStatus$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_SMS_getKeysPressed$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_SMS_getKeysHeld$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_SMS_getKeysReleased$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_UP$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_DOWN$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_LEFT$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_RIGHT$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_1$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_2$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_START$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_UP$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_DOWN$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_LEFT$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_RIGHT$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_1$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_2$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_START$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_RESET_KEY$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_CARTRIDGE_SLOT$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_TH$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_TH$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_PORT_B$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_detectPaddle$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_readPaddle$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_queryPauseRequested$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_resetPauseRequest$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VDPFlags$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_VDPFLAG_SPRITEOVERFLOW$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_VDPFLAG_SPRITECOLLISION$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_setLineInterruptHandler$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setLineCounter$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_enableLineInterrupt$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_disableLineInterrupt$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_getVCount$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_getHCount$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_VRAMmemcpy$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VRAMmemcpy_brief$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VRAMmemset$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VRAMmemsetW$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_copySpritestoSAT$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_VRAMmemcpy32$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_VRAMmemcpy64$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_VRAMmemcpy128$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_load1Tile$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_load2Tiles$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_load4Tiles$0_0$0({2}DF,SV:S),C,0,0
S:G$dekvit_SMS_isr$0_0$0({2}DF,SV:S),C,0,0
S:G$dekvit_SMS_nmi_isr$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addSprite_bulk8$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addSprite_bulk12$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setTilePriority$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_isCollisionDetected$0_0$0({2}DF,SC:U),C,0,0
S:Fintro_screen$print$0_0$0({2}DF,SV:S),C,0,0
