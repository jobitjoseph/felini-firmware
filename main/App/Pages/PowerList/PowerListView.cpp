#include "PowerListView.h"
#include <cstdio>

using namespace Page;

#define CELL_SIZE 80

void PowerListView::Create(lv_obj_t *root)
{
    lv_obj_set_style_border_width(root, 0, LV_PART_MAIN);
    /*Change the active screen's background color*/
    lv_obj_set_style_bg_color(root, lv_color_hex(0), LV_PART_MAIN);
    // tile view

    lv_obj_t *ui_tileView = lv_tileview_create(root);

    lv_obj_set_width(ui_tileView, 280);
    lv_obj_set_height(ui_tileView, 240);
    lv_obj_center(ui_tileView);

    lv_obj_set_align(ui_tileView, LV_ALIGN_CENTER);

    lv_obj_set_scrollbar_mode(ui_tileView, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_radius(ui_tileView, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_tileView, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_tileView, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_tileView, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    /*Tile1: startMenu*/
    lv_obj_t *ui_tileStart = lv_tileview_add_tile(ui_tileView, 0, 0, LV_DIR_RIGHT);

    static lv_coord_t col_dsc[] = {CELL_SIZE, CELL_SIZE, CELL_SIZE, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE, LV_GRID_TEMPLATE_LAST};

    /*Create a container with grid*/
    lv_obj_t *cont = lv_obj_create(ui_tileStart);

    lv_obj_set_style_radius(cont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(cont, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(cont, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(cont, ResourcePool::GetImage("wall"), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);

    // lv_obj_set_style_pad_all(cont, 20, LV_PART_MAIN);
    lv_obj_set_style_pad_left(cont, 12, LV_PART_MAIN);
    lv_obj_set_style_pad_right(cont, 10, LV_PART_MAIN);
    lv_obj_set_style_pad_column(cont, 8, LV_PART_MAIN);
    lv_obj_set_style_pad_row(cont, 8, LV_PART_MAIN);
    lv_obj_set_style_grid_column_dsc_array(cont, col_dsc, 0);
    lv_obj_set_style_grid_row_dsc_array(cont, row_dsc, 0);
    lv_obj_set_size(cont, 280, 240);
    lv_obj_center(cont);
    lv_obj_set_layout(cont, LV_LAYOUT_GRID);

    index_item = 0;

    CreateItemCell(3.3, cont, "", 0x6d6ed8, 0, 0, 2);
    CreateItemCell(3.7, cont, "", 0x6d6ed8, 2, 0, 1);
    CreateItemCell(4.2, cont, "", 0x43b3db, 0, 1, 1);
    CreateItemCell(4.8, cont, "", 0x94339c, 1, 1, 1);
    CreateItemCell(5.0, cont, "", 0x2c78a0,  2, 1, 1);
    CreateItemCell(5.5, cont, "", 0x16b0a0, 0, 2, 1);
    CreateItemCell(6.4, cont, "", 0x16b0a0, 1, 2, 2);
    CreateItemCell(7.4, cont, "", 0x43b3db, 0, 3, 2);
    CreateItemCell(8.4, cont, "", 0x2c78a0, 2, 3, 1);
    CreateItemCell(10.6, cont, "", 0x16b0a0, 0, 4, 1);
    CreateItemCell(11.1, cont, "", 0x16b0a0, 1, 4, 2);
    CreateItemCell(13.2, cont, "", 0x6d6ed8, 0, 5, 1);
    CreateItemCell(14.2, cont, "", 0x6d6ed8, 1, 5, 1);
    CreateItemCell(16.8, cont, "", 0x43b3db, 2, 5, 1);
    CreateItemCell(16.8, cont, "", 0x94339c, 2, 5, 1);
}

void PowerListView::CreateItemCell(float voltage, lv_obj_t *parent, const char *name, uint32_t color, int col, int row, int size)
{
    lv_obj_t *label;
    lv_obj_t *obj;
    lv_obj_t *icon;
    ui.item[index_item].volt = voltage;

    // printf("app src %s\r\n", app_src);
    obj = lv_btn_create(parent);
    ui.item[index_item].btn_cell = obj;
    ui.item[index_item].state = false;
    ui.item[index_item].color = color;
    lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(color), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, col, size, LV_GRID_ALIGN_STRETCH, row, 1);

    label = lv_label_create(obj);
    ui.item[index_item].label = label;
    lv_label_set_text_fmt(label, "%.1f", voltage);
    lv_obj_set_style_text_font(label, ResourcePool::GetFont("sf_compact_medium_24"), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(label, LV_SIZE_CONTENT);
    lv_obj_set_height(label, LV_SIZE_CONTENT);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_obj_add_flag(label, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(label, LV_OBJ_FLAG_SCROLLABLE);
    
    index_item ++;

}

void PowerListView::Delete()
{
    printf("PowerListView::Delete()\n");
}

