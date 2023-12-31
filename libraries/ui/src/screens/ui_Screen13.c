// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_Screen13_screen_init(void)
{
ui_Screen13 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen13, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen13, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen13, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ImgButton4 = lv_imgbtn_create(ui_Screen13);
lv_imgbtn_set_src(ui_ImgButton4, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_1882376574, NULL);
lv_obj_set_width( ui_ImgButton4, 53);
lv_obj_set_height( ui_ImgButton4, 53);
lv_obj_set_x( ui_ImgButton4, 189 );
lv_obj_set_y( ui_ImgButton4, -116 );
lv_obj_set_align( ui_ImgButton4, LV_ALIGN_CENTER );

ui_Label29 = lv_label_create(ui_Screen13);
lv_obj_set_width( ui_Label29, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label29, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label29, 10 );
lv_obj_set_y( ui_Label29, -54 );
lv_obj_set_align( ui_Label29, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label29,"to\nchange\nbtc\nfee");
lv_obj_add_state( ui_Label29, LV_STATE_PRESSED );     /// States
lv_obj_set_style_text_color(ui_Label29, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label29, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label29, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Button16 = lv_btn_create(ui_Screen13);
lv_obj_set_height( ui_Button16, 65);
lv_obj_set_width( ui_Button16, lv_pct(81));
lv_obj_set_x( ui_Button16, 1 );
lv_obj_set_y( ui_Button16, 98 );
lv_obj_set_align( ui_Button16, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Button16, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button16, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Button16, lv_color_hex(0xFF7129), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Button16, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_Button16, 45, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_bg_color(ui_Button16, lv_color_hex(0x702828), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_bg_opa(ui_Button16, 255, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_bg_grad_color(ui_Button16, lv_color_hex(0x6D0E0E), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_bg_main_stop(ui_Button16, 0, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_bg_grad_stop(ui_Button16, 255, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_bg_grad_dir(ui_Button16, LV_GRAD_DIR_VER, LV_PART_MAIN| LV_STATE_PRESSED);

ui_Label32 = lv_label_create(ui_Button16);
lv_obj_set_width( ui_Label32, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label32, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label32, 0 );
lv_obj_set_y( ui_Label32, -1 );
lv_obj_set_align( ui_Label32, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label32,"Sign and export");
lv_obj_add_state( ui_Label32, LV_STATE_PRESSED );     /// States
lv_obj_set_style_text_color(ui_Label32, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label32, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label32, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_ImgButton4, ui_event_ImgButton4, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Button16, ui_event_Button16, LV_EVENT_ALL, NULL);

}
