/* ScummVM - Scumm Interpreter
 * Copyright (C) 2003 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$
 *
 */

#include "stdafx.h"
#include "common/util.h"
#include "sky/debug.h"

static const char *section_0_compacts[] = {
	"UNDEFINED",
	"joey",
	"joey_park",
	"foster",
	"std_menu_logic",
	"text_mouse",
	"gallcard_menu",
	"rs_mega_alive",
	"citycard_menu",
	"shades_menu",
	"putty_menu",
	"lightbulb_menu",
	"low_get_seq",
	"mini_shrug_seq",
	"sml_up_mid_get_seq",
	"new_grid",
	"lamb",
	"floor",
	"coordinate_test",
	"save_restore_mouse",
	"whole_screen",
	"l_talk_s2",
	"r_talk_s2",
	"text_1",
	"text_2",
	"text_3",
	"text_4",
	"text_5",
	"text_6",
	"text_7",
	"text_8",
	"text_9",
	"text_10",
	"text_11",
	"wd40_menu",
	"skey_menu",
	"secateurs_menu",
	"rope_menu",
	"plaster_menu",
	"new_cable_menu",
	"shrug_seq",
	"rad_shrug_seq",
	"brick_menu",
	"tongs_menu",
	"talk1",
	"talk2",
	"menu_bar",
	"left_arrow",
	"right_arrow",
	"dog_food_menu",
	"UNDEFINED",
	"blank1",
	"blank2",
	"blank3",
	"blank4",
	"blank5",
	"blank6",
	"blank7",
	"blank8",
	"blank9",
	"blank10",
	"blank11",
	"UNDEFINED",
	"crow_bar_menu",
	"sarnie_menu",
	"spanner_menu",
	"joeyb_menu",
	"low_floor",
	"UNDEFINED",
	"stairs",
	"upstairs",
	"anita_card_menu",
	"rs_lamb_to_three",
	"rs_lamb_start_2",
	"anchor_menu",
	"magazine_menu",
	"tape_menu",
	"glass_menu",
	"rs_lamb_start_3",
	"ticket_menu",
	"s29_fast_list",
	"s6_fast_list",
	"fast_list_sc3",
	"s9_fast_list",
	"s10_fast_list",
	"bar",
	"s11_fast_list",
	"fast_list_0",
	"s0_fast_list",
	"s7_fast_list",
	"door",
	"s28_fast_list",
	"swing_list",
	"UNDEFINED",
	"UNDEFINED",
	"outside_ledge",
	"UNDEFINED",
	"r1_door",
	"UNDEFINED",
	"UNDEFINED",
	"UNDEFINED",
	"UNDEFINED",
	"fast_list_sc90",
	"UNDEFINED",
	"UNDEFINED",
	"small_door",
	"sc85_fast_list",
	"sc85_chip_list",
	"sc85_logic_list",
	"sc85_mouse_list",
	"sc85_palette",
	"right_exit0",
	"UNDEFINED",
	"UNDEFINED",
	"UNDEFINED",
	"s2_floor",
	"UNDEFINED",
	"s101_chip_list",
	"s101_pal",
	"s101_mouse",
	"s101_logic",
	"full_screen",
	"cancel_button",
	"button_0",
	"button_1",
	"button_2",
	"button_3",
	"button_4",
	"button_5",
	"button_6",
	"button_7",
	"button_8",
	"button_9",
	"rs_left_arrow",
	"rs_right_arrow",
	"rs_blank",
	"monitor",
	"anita",
	"UNDEFINED",
	"UNDEFINED",
	"UNDEFINED",
	"baby_logic_list",
	"rs_l_arr_linc",
	"rs_r_arr_linc",
	"rs_blanks_linc",
	"s5_fast_list",
	"but_e",
	"but_0",
	"but_1",
	"but_2",
	"but_3",
	"but_4",
	"but_5",
	"but_6",
	"but_7",
	"but_8",
	"but_9",
	"UNDEFINED",
	"s102_chip_list",
	"s102_pal",
	"s102_logic",
	"s102_mouse",
	"restart_butt",
	"restart_seq",
	"restore_butt",
	"restore_seq",
	"seq1_pal",
	"seq2_pal",
	"seq3_pal",
	"fast_intro",
	"chip_intro",
	"fast_intro_2",
	"fast_intro_3",
	"retina_scan",
	"retina_scan_cdt",
	"exit_butt",
	"exit_seq",
	"forklift_cpt",
	"forklift1_cdt",
	"forklift2_cdt",
};

static const char *logic_table_names[] = {
	"return",
	"SkyLogic::script",
	"SkyLogic::auto_route",
	"SkyLogic::ar_anim",
	"SkyLogic::ar_turn",
	"SkyLogic::alt",
	"SkyLogic::anim",
	"SkyLogic::turn",
	"SkyLogic::cursor",
	"SkyLogic::talk",
	"SkyLogic::listen",
	"SkyLogic::stopped",
	"SkyLogic::choose",
	"SkyLogic::frames",
	"SkyLogic::pause",
	"SkyLogic::wait_sync",
	"SkyLogic::simple_anim",
};

static const char opcode_par[] = {
	1,
	0,
	1,
	0,
	0,
	1,
	1,
	0,
	0,
	1,
	0,
	2,
	0,
	0,
	1,
	1,
	1,
	0,
	1,
	0,
	0,
};

static const char *opcodes[] = {
	"push_variable",
	"less_than",
	"push_number",
	"not_equal",
	"if_and",
	"skip_zero",
	"pop_var",
	"minus",
	"plus",
	"skip_always",
	"if_or",
	"call_mcode",
	"more_than",
	"script_exit",
	"switch",
	"push_offset",
	"pop_offset",
	"is_equal",
	"skip_nz",
	"script_exit",
	"restart_script",
};

static const char *mcodes[] = {
	"fn_cache_chip",
	"fn_cache_fast",
	"fn_draw_screen",
	"fn_ar",
	"fn_ar_animate",
	"fn_idle",
	"fn_interact",
	"fn_start_sub",
	"fn_they_start_sub",
	"fn_assign_base",
	"fn_disk_mouse",
	"fn_normal_mouse",
	"fn_blank_mouse",
	"fn_cross_mouse",
	"fn_cursor_right",
	"fn_cursor_left",
	"fn_cursor_down",
	"fn_open_hand",
	"fn_close_hand",
	"fn_get_to",
	"fn_set_to_stand",
	"fn_turn_to",
	"fn_arrived",
	"fn_leaving",
	"fn_set_alternate",
	"fn_alt_set_alternate",
	"fn_kill_id",
	"fn_no_human",
	"fn_add_human",
	"fn_add_buttons",
	"fn_no_buttons",
	"fn_set_stop",
	"fn_clear_stop",
	"fn_pointer_text",
	"fn_quit",
	"fn_speak_me",
	"fn_speak_me_dir",
	"fn_speak_wait",
	"fn_speak_wait_dir",
	"fn_chooser",
	"fn_highlight",
	"fn_text_kill",
	"fn_stop_mode",
	"fn_we_wait",
	"fn_send_sync",
	"fn_send_fast_sync",
	"fn_send_request",
	"fn_clear_request",
	"fn_check_request",
	"fn_start_menu",
	"fn_unhighlight",
	"fn_face_id",
	"fn_foreground",
	"fn_background",
	"fn_new_background",
	"fn_sort",
	"fn_no_sprite_engine",
	"fn_no_sprites_a6",
	"fn_reset_id",
	"fn_toggle_grid",
	"fn_pause",
	"fn_run_anim_mod",
	"fn_simple_mod",
	"fn_run_frames",
	"fn_await_sync",
	"fn_inc_mega_set",
	"fn_dec_mega_set",
	"fn_set_mega_set",
	"fn_move_items",
	"fn_new_list",
	"fn_ask_this",
	"fn_random",
	"fn_person_here",
	"fn_toggle_mouse",
	"fn_mouse_on",
	"fn_mouse_off",
	"fn_fetch_x",
	"fn_fetch_y",
	"fn_test_list",
	"fn_fetch_place",
	"fn_custom_joey",
	"fn_set_palette",
	"fn_text_module",
	"fn_change_name",
	"fn_mini_load",
	"fn_flush_buffers",
	"fn_flush_chip",
	"fn_save_coods",
	"fn_plot_grid",
	"fn_remove_grid",
	"fn_eyeball",
	"fn_cursor_up",
	"fn_leave_section",
	"fn_enter_section",
	"fn_restore_game",
	"fn_restart_game",
	"fn_new_swing_seq",
	"fn_wait_swing_end",
	"fn_skip_intro_code",
	"fn_blank_screen",
	"fn_print_credit",
	"fn_look_at",
	"fn_linc_text_module",
	"fn_text_kill2",
	"fn_set_font",
	"fn_start_fx",
	"fn_stop_fx",
	"fn_start_music",
	"fn_stop_music",
	"fn_fade_down",
	"fn_fade_up",
	"fn_quit_to_dos",
	"fn_pause_fx",
	"fn_un_pause_fx",
	"fn_printf",
};

static const char *scriptVars[] = {
	"result",
	"screen",
	"logic_list_no",
	"safe_logic_list",
	"low_list_no",
	"high_list_no",
	"mouse_list_no",
	"safe_mouse_list",
	"draw_list_no",
	"second_draw_list",
	"do_not_use",
	"music_module",
	"cur_id",
	"mouse_status",
	"mouse_stop",
	"button",
	"but_repeat",
	"special_item",
	"get_off",
	"safe_click",
	"click_id",
	"player_id",
	"cursor_id",
	"pointer_pen",
	"last_pal",
	"safex",
	"safey",
	"player_x",
	"player_y",
	"player_mood",
	"player_screen",
	"old_x",
	"old_y",
	"joey_x",
	"joey_y",
	"joey_list",
	"flag",
	"hit_id",
	"player_target",
	"joey_target",
	"mega_target",
	"layer_0_id",
	"layer_1_id",
	"layer_2_id",
	"layer_3_id",
	"grid_1_id",
	"grid_2_id",
	"grid_3_id",
	"stop_grid",
	"text_rate",
	"text_speed",
	"the_chosen_one",
	"chosen_anim",
	"text1",
	"anim1",
	"text2",
	"anim2",
	"text3",
	"anim3",
	"text4",
	"anim4",
	"text5",
	"anim5",
	"text6",
	"anim6",
	"text7",
	"anim7",
	"text8",
	"anim8",
	"o0",
	"o1",
	"o2",
	"o3",
	"o4",
	"o5",
	"o6",
	"o7",
	"o8",
	"o9",
	"o10",
	"o11",
	"o12",
	"o13",
	"o14",
	"o15",
	"o16",
	"o17",
	"o18",
	"o19",
	"o20",
	"o21",
	"o22",
	"o23",
	"o24",
	"o25",
	"o26",
	"o27",
	"o28",
	"o29",
	"first_icon",
	"menu_length",
	"scroll_offset",
	"menu",
	"object_held",
	"icon_lit",
	"at_sign",
	"fire_exit_flag",
	"small_door_flag",
	"jobs_greet",
	"lamb_greet",
	"knob_flag",
	"lazer_flag",
	"cupb_flag",
	"jobs_loop",
	"done_something",
	"rnd",
	"jobs_text",
	"jobs_loc1",
	"jobs_loc2",
	"jobs_loc3",
	"id_talking",
	"alarm",
	"alarm_count",
	"clearing_alarm",
	"jobs_friend",
	"joey_born",
	"joey_text",
	"joey_peeved",
	"knows_linc",
	"linc_overmann",
	"reich_entry",
	"seen_lock",
	"wshop_text",
	"knows_firedoor",
	"knows_furnace",
	"jobs_got_spanner",
	"jobs_got_sandwich",
	"jobs_firedoor",
	"knows_transporter",
	"joey_loc1",
	"joey_loc2",
	"joey_loc3",
	"joey_screen",
	"cur_section",
	"old_section",
	"joey_section",
	"lamb_section",
	"knows_overmann",
	"jobs_overmann",
	"jobs_seen_joey",
	"anita_text",
	"anit_loc1",
	"anit_loc2",
	"anit_loc3",
	"lamb_friend",
	"lamb_sick",
	"lamb_crawly",
	"lamb_loc1",
	"lamb_loc2",
	"lamb_loc3",
	"lamb_got_spanner",
	"lamb_text",
	"knows_auditor",
	"lamb_security",
	"lamb_auditor",
	"fore_text",
	"transporter_alive",
	"anita_friend",
	"anita_stop",
	"anita_count",
	"knows_security",
	"fore_loc1",
	"fore_loc2",
	"fore_loc3",
	"fore_friend",
	"knows_dlinc",
	"seen_lift",
	"player_sound",
	"guard_linc",
	"guard_text",
	"guar_loc1",
	"guar_loc2",
	"guar_loc3",
	"guard_talk",
	"lamb_out",
	"guard_warning",
	"wshp_loc1",
	"wshp_loc2",
	"wshp_loc3",
	"jobs_linc",
	"knows_port",
	"jobs_port",
	"joey_overmann",
	"joey_count",
	"knows_pipes",
	"knows_hobart",
	"fore_hobart",
	"fore_overmann",
	"anit_text",
	"seen_eye",
	"anita_dlinc",
	"seen_dis_lift",
	"lamb_move_anita",
	"lamb_stat",
	"machine_stops",
	"guard_stat",
	"guard_hobart",
	"gordon_text",
	"gord_loc1",
	"gord_loc2",
	"gord_loc3",
	"lamb_hobart",
	"anita_loc1",
	"anita_loc2",
	"anita_loc3",
	"knows_elders",
	"anita_elders",
	"anita_overmann",
	"stay_here",
	"joey_pause",
	"knows_break_in",
	"joey_break_in",
	"joey_lift",
	"stair_talk",
	"blown_top",
	"tamper_flag",
	"knows_reich",
	"gordon_reich",
	"open_panel",
	"panel_count",
	"wreck_text",
	"press_button",
	"touch_count",
	"gordon_overmann",
	"lamb_reich",
	"exit_stores",
	"henri_text",
	"henr_loc1",
	"henr_loc2",
	"henr_loc3",
	"got_sponsor",
	"used_deodorant",
	"lob_dad_text",
	"lob_son_text",
	"scan_talk",
	"dady_loc1",
	"dady_loc2",
	"dady_loc3",
	"samm_loc1",
	"samm_loc2",
	"samm_loc3",
	"dirty_card",
	"wrek_loc1",
	"wrek_loc2",
	"wrek_loc3",
	"crushed_nuts",
	"got_port",
	"anita_port",
	"got_jammer",
	"knows_anita",
	"anita_hobart",
	"local_count",
	"lamb_joey",
	"stop_store",
	"knows_suit",
	"joey_box",
	"asked_box",
	"shell_count",
	"got_cable",
	"local_flag",
	"search_flag",
	"rad_count",
	"rad_text",
	"radm_loc1",
	"radm_loc2",
	"radm_loc3",
	"gordon_off",
	"knows_jobsworth",
	"rad_back_flag",
	"lamb_lift",
	"knows_cat",
	"lamb_screwed",
	"tour_flag",
	"foreman_reactor",
	"foreman_anita",
	"burke_text",
	"burk_loc1",
	"burk_loc2",
	"burk_loc3",
	"burke_anchor",
	"jason_text",
	"jaso_loc1",
	"jaso_loc2",
	"helg_loc2",
	"say_to_helga",
	"interest_count",
	"anchor_text",
	"anchor_overmann",
	"anch_loc1",
	"anch_loc2",
	"anch_loc3",
	"anchor_count",
	"lamb_anchor",
	"anchor_port",
	"knows_stephen",
	"knows_ghoul",
	"anchor_talk",
	"joey_hook",
	"joey_done_dir",
	"bios_loc1",
	"bios_loc2",
	"bios_loc3",
	"got_hook",
	"anchor_anita",
	"trev_loc1",
	"trev_loc2",
	"trev_loc3",
	"trevor_text",
	"trev_text",
	"trev_overmann",
	"lamb_smell",
	"art_flag",
	"trev_computer",
	"helga_text",
	"helg_loc1",
	"helg_loc3",
	"bios_loc4",
	"gallagher_text",
	"gall_loc1",
	"gall_loc2",
	"gall_loc3",
	"warn_lamb",
	"open_apts",
	"store_count",
	"foreman_auditor",
	"frozen_assets",
	"read_report",
	"seen_holo",
	"knows_subway",
	"exit_flag",
	"father_text",
	"lamb_fix",
	"read_briefing",
	"seen_shaft",
	"knows_mother",
	"console_type",
	"hatch_selected",
	"seen_walters",
	"joey_fallen",
	"jbel_loc1",
	"lbel_loc1",
	"lbel_loc2",
	"jobsworth_speech",
	"jobs_alert",
	"jobs_alarmed_ref",
	"safe_joey_recycle",
	"safe_joey_sss",
	"safe_joey_mission",
	"safe_trans_mission",
	"safe_slot_mission",
	"safe_corner_mission",
	"safe_joey_logic",
	"safe_gordon_speech",
	"safe_button_mission",
	"safe_dad_speech",
	"safe_son_speech",
	"safe_skorl_speech",
	"safe_uchar_speech",
	"safe_wreck_speech",
	"safe_anita_speech",
	"safe_lamb_speech",
	"safe_foreman_speech",
	"joey_42_mission",
	"joey_junction_mission",
	"safe_welder_mission",
	"safe_joey_weld",
	"safe_radman_speech",
	"safe_link_7_29",
	"safe_link_29_7",
	"safe_lamb_to_3",
	"safe_lamb_to_2",
	"safe_burke_speech",
	"safe_burke_1",
	"safe_burke_2",
	"safe_dr_1",
	"safe_body_speech",
	"joey_bell",
	"safe_anchor_speech",
	"safe_anchor",
	"safe_pc_mission",
	"safe_hook_mission",
	"safe_trevor_speech",
	"joey_fact",
	"safe_helga_speech",
	"helga_mission",
	"gal_bel_speech",
	"safe_glass_mission",
	"safe_lamb_fact_return",
	"lamb_part_2",
	"safe_lamb_bell_return",
	"safe_lamb_bell",
	"safe_cable_mission",
	"safe_foster_tour",
	"safe_lamb_tour",
	"safe_foreman_logic",
	"safe_lamb_leave",
	"safe_lamb_3",
	"safe_lamb_2",
	"into_linc",
	"out_10",
	"out_74",
	"safe_link_28_31",
	"safe_link_31_28",
	"safe_exit_linc",
	"safe_end_game",
	"which_linc",
	"lift_moving",
	"lift_on_screen",
	"barrel_on_screen",
	"convey_on_screen",
	"shades_searched",
	"joey_wiz",
	"slot_slotted",
	"motor_flag",
	"panel_flag",
	"switch_flag",
	"steam_flag",
	"steam_fx_no",
	"factory_flag",
	"power_door_open",
	"left_skull_flag",
	"right_skull_flag",
	"monitor_watching",
	"left_lever_flag",
	"right_lever_flag",
	"lobby_door_flag",
	"weld_stop",
	"cog_flag",
	"sensor_flag",
	"look_through",
	"welder_nut_flag",
	"s7_lift_flag",
	"s29_lift_flag",
	"whos_at_lift_7",
	"whos_at_lift_29",
	"lift_power",
	"whats_joey",
	"seen_box",
	"seen_welder",
	"flap_flag",
	"s15_floor",
	"foreman_friend",
	"locker1_flag",
	"locker2_flag",
	"locker3_flag",
	"whats_in_locker",
	"knows_radsuit",
	"radman_anita",
	"at_anita",
	"coat_flag",
	"dressed_as",
	"s14_take",
	"reactor_door_flag",
	"joey_in_lift",
	"chair_27_flag",
	"at_body_flag",
	"at_gas_flag",
	"anchor_seated",
	"door_23_jam",
	"door_20_jam",
	"reich_door_flag",
	"reich_door_jam",
	"lamb_door_flag",
	"lamb_door_jam",
	"pillow_flag",
	"cat_food_flag",
	"helga_up",
	"got_magazine",
	"trevs_doing",
	"card_status",
	"card_fix",
	"lamb_gallager",
	"locker_11_flag",
	"ever_opened",
	"linc_10_flag",
	"chair_10_flag",
	"skorl_flag",
	"lift_pause",
	"lift_in_use",
	"gordon_back",
	"furnace_door_flag",
	"whos_with_gall",
	"read_news",
	"whos_at_lift_28",
	"s28_lift_flag",
	"mission_state",
	"anita_flag",
	"card_used",
	"gordon_catch",
	"car_flag",
	"first_jobs",
	"jobs_removed",
	"menu_id",
	"tonys_tour_flag",
	"joey_foster_phase",
	"start_info_window",
	"ref_slab_on",
	"ref_up_mouse",
	"ref_down_mouse",
	"ref_left_mouse",
	"ref_right_mouse",
	"ref_disconnect_foster",
	"k0",
	"k1",
	"k2",
	"k3",
	"k4",
	"k5",
	"k6",
	"k7",
	"k8",
	"k9",
	"k10",
	"k11",
	"k12",
	"k13",
	"k14",
	"k15",
	"k16",
	"k17",
	"k18",
	"k19",
	"k20",
	"k21",
	"k22",
	"k23",
	"k24",
	"k25",
	"k26",
	"k27",
	"k28",
	"k29",
	"a0",
	"a1",
	"a2",
	"a3",
	"a4",
	"a5",
	"a6",
	"a7",
	"a8",
	"a9",
	"a10",
	"a11",
	"a12",
	"a13",
	"a14",
	"a15",
	"a16",
	"a17",
	"a18",
	"a19",
	"a20",
	"a21",
	"a22",
	"a23",
	"a24",
	"a25",
	"a26",
	"a27",
	"a28",
	"a29",
	"g0",
	"g1",
	"g2",
	"g3",
	"g4",
	"g5",
	"g6",
	"g7",
	"g8",
	"g9",
	"g10",
	"g11",
	"g12",
	"g13",
	"g14",
	"g15",
	"g16",
	"g17",
	"g18",
	"g19",
	"g20",
	"g21",
	"g22",
	"g23",
	"g24",
	"g25",
	"g26",
	"g27",
	"g28",
	"g29",
	"window_subject",
	"file_text",
	"size_text",
	"auth_text",
	"note_text",
	"id_head_compact",
	"id_file_compact",
	"id_size_compact",
	"id_auth_compact",
	"id_note_compact",
	"pal_no",
	"strikes",
	"char_set_number",
	"eye90_blinded",
	"zap90",
	"eye90_frame",
	"eye91_blinded",
	"zap91",
	"eye91_frame",
	"bag_open",
	"bridge_a_on",
	"bridge_b_on",
	"bridge_c_on",
	"bridge_d_on",
	"bridge_e_on",
	"bridge_f_on",
	"bridge_g_on",
	"bridge_h_on",
	"green_slab",
	"red_slab",
	"foster_slab",
	"circle_slab",
	"slab1_mouse",
	"slab2_mouse",
	"slab3_mouse",
	"slab4_mouse",
	"slab5_mouse",
	"at_guardian",
	"guardian_there",
	"crystal_shattered",
	"virus_taken",
	"fs_command",
	"enter_digits",
	"next_page",
	"linc_digit_0",
	"linc_digit_1",
	"linc_digit_2",
	"linc_digit_3",
	"linc_digit_4",
	"linc_digit_5",
	"linc_digit_6",
	"linc_digit_7",
	"linc_digit_8",
	"linc_digit_9",
	"ref_std_on",
	"ref_std_exit_left_on",
	"ref_std_exit_right_on",
	"ref_advisor_188",
	"ref_shout_action",
	"ref_mega_click",
	"ref_mega_action",
	"ref_walter_speech",
	"ref_joey_medic",
	"ref_joey_med_logic",
	"ref_joey_med_mission72",
	"ref_ken_logic",
	"ref_ken_speech",
	"ref_ken_mission_hand",
	"ref_sc70_iris_opened",
	"ref_sc70_iris_closed",
	"ref_foster_enter_boardroom",
	"ref_father_speech",
	"ref_foster_enter_new_boardroom",
	"ref_hobbins_speech",
	"ref_sc82_jobs_sss",
	"brickwork",
	"door_67_68_flag",
	"crowbar_in_clot",
	"clot_ruptured",
	"clot_repaired",
	"walt_text",
	"walt_loc1",
	"walt_loc2",
	"walt_loc3",
	"walt_count",
	"medic_text",
	"seen_room_72",
	"seen_tap",
	"joey_med_seen72",
	"seen_secure_door",
	"ask_secure_door",
	"sc70_iris_flag",
	"sc70_iris_frame",
	"foster_on_sc70_iris",
	"sc70_grill_flag",
	"sc71_charging_flag",
	"sc72_slime_flag",
	"sc72_witness_sees_foster",
	"sc72_witness_killed",
	"sc73_gallagher_killed",
	"sc73_removed_board",
	"sc73_searched_corpse",
	"door_73_75_flag",
	"sc74_sitting_flag",
	"sc75_crashed_flag",
	"sc75_tissue_infected",
	"sc75_tongs_flag",
	"sc76_cabinet1_flag",
	"sc76_cabinet2_flag",
	"sc76_cabinet3_flag",
	"sc76_board_flag",
	"sc76_ken_prog_flag",
	"sc76_and2_up_flag",
	"ken_text",
	"ken_door_flag",
	"sc77_foster_hand_flag",
	"sc77_ken_hand_flag",
	"door_77_78_flag",
	"sc80_exit_flag",
	"ref_danielle_speech",
	"ref_danielle_go_home",
	"ref_spunky_go_home",
	"ref_henri_speech",
	"ref_buzzer_speech",
	"ref_foster_visit_dani",
	"ref_danielle_logic",
	"ref_jukebox_speech",
	"ref_vincent_speech",
	"ref_eddie_speech",
	"ref_blunt_speech",
	"ref_dani_answer_phone",
	"ref_spunky_see_video",
	"ref_spunky_bark_at_foster",
	"ref_spunky_smells_food",
	"ref_barry_speech",
	"ref_colston_speech",
	"ref_gallagher_speech",
	"ref_babs_speech",
	"ref_chutney_speech",
	"ref_foster_enter_court",
	"dani_text",
	"dani_loc1",
	"dani_loc2",
	"dani_loc3",
	"dani_buff",
	"dani_huff",
	"mother_hobart",
	"foster_id_flag",
	"knows_spunky",
	"dog_fleas",
	"op_flag",
	"chat_up",
	"buzz_loc1",
	"buzz_loc2",
	"blunt_text",
	"blun_loc1",
	"blun_loc2",
	"blun_loc3",
	"blunt_dan_info",
	"vincent_text",
	"vinc_loc1",
	"vinc_loc2",
	"vinc_loc3",
	"eddie_text",
	"eddi_loc1",
	"eddi_loc2",
	"eddi_loc3",
	"knows_dandelions",
	"barry_text",
	"bazz_loc1",
	"bazz_loc2",
	"bazz_loc3",
	"seen_cellar_door",
	"babs_text",
	"babs_loc1",
	"babs_loc2",
	"babs_loc3",
	"colston_text",
	"cols_loc1",
	"cols_loc2",
	"cols_loc3",
	"jukebox",
	"knows_soaking",
	"knows_complaint",
	"dog_bite",
	"new_prints",
	"knows_virus",
	"been_to_court",
	"danielle_target",
	"spunky_target",
	"henri_forward",
	"sc31_lift_flag",
	"sc31_food_on_plank",
	"sc31_spunky_at_plank",
	"dog_in_lake",
	"sc32_lift_flag",
	"sc33_shed_door_flag",
	"gardener_up",
	"babs_x",
	"babs_y",
	"foster_caching",
	"colston_caching",
	"band_playing",
	"colston_at_table",
	"sc36_next_dealer",
	"sc36_door_flag",
	"sc37_door_flag",
	"sc37_lid_loosened",
	"sc37_lid_used",
	"sc37_standing_on_box",
	"sc37_box_broken",
	"sc37_grill_state",
	"got_dog_biscuits",
	"sc38_video_playing",
	"dani_on_phone",
	"sc40_locker_1_flag",
	"sc40_locker_2_flag",
	"sc40_locker_3_flag",
	"sc40_locker_4_flag",
	"sc40_locker_5_flag",
	"seen_anita_corpse",
	"spunky_at_lift",
	"court_text",
	"blunt_knew_jobs",
	"credit_1_text",
	"credit_2_text",
	"id_credit_1",
	"id_credit_2",
	"glass_stolen",
	"foster_at_plank",
	"foster_at_guard",
	"man_talk",
	"man_loc1",
	"man_loc2",
	"man_loc3",
};

void SkyDebug::fetchCompact(uint32 a) {
	uint32 sectionNum = (a & 0xf000) >> 12;
	uint32 compactNum = (a & 0x0fff);

	if (sectionNum == 0)
		debug(8, "Loading Compact %d (%s) from section %d", compactNum, section_0_compacts[compactNum], sectionNum);
	else
		debug(8, "Loading Compact %d from section %d", compactNum, sectionNum);
}

void SkyDebug::logic(uint32 logic) {
	debug(6, "LOGIC: %s", logic_table_names[logic]);
}

void SkyDebug::script(uint32 command, uint16 *scriptData) {
	debug(6, "SCRIPT: %s", opcodes[command]);
	if (command == 0 || command == 6)
		debug(6, " %s", scriptVars[READ_LE_UINT16(scriptData)/4]);
	else {
		int i;
		for (i = 0; i < opcode_par[command]; i++) {
			debug(6, " %d", READ_LE_UINT16(scriptData + i));
		}
	}
	debug(6, "");
}

void SkyDebug::mcode(uint32 mcode, uint32 a, uint32 b, uint32 c) {
	debug(6, "MCODE: %s(%d, %d, %d)", mcodes[mcode], a, b, c);
}

