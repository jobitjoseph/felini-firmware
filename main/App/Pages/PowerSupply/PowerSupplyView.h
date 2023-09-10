#ifndef __PowerSupply_VIEW_H
#define __PowerSupply_VIEW_H

#include "../Page.h"

namespace Page
{

class PowerSupplyView
{
public:
    void Create(lv_obj_t* root);
    void Delete();
    void FocusEditLabel(lv_obj_t *set, lv_obj_t *label, uint8_t state, int *div);
    void OutFocusLabel(lv_obj_t *label);

public:
public:
    typedef struct
    {
        lv_obj_t *set;
        lv_obj_t *button;
        lv_obj_t *label;
        const char *name;
    } item_t;

    struct
    {
        item_t voltage;
        item_t current;
        item_t power;
        // item_t confirm;
        // item_t slider;
        item_t spin;
    } ui;

private:
};

}

#endif // !__VIEW_H
