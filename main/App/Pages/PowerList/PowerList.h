#ifndef __PowerList_PRESENTER_H
#define __PowerList_PRESENTER_H

#include "PowerListView.h"
#include "PowerListModel.h"

namespace Page
{

class PowerList : public PageBase
{
public:

public:
    PowerList();
    virtual ~PowerList();

    virtual void onCustomAttrConfig();
    virtual void onViewLoad();
    virtual void onViewDidLoad();
    virtual void onViewWillAppear();
    virtual void onViewDidAppear();
    virtual void onViewWillDisappear();
    virtual void onViewDidDisappear();
    virtual void onViewDidUnload();

private:
    void Update();
    void AttachEvent(lv_obj_t *obj);
    void ViewUpdatePos(lv_event_t *event);
    static void onTimer(lv_timer_t* timer);
    static void onEvent(lv_event_t* event);

private:
    PowerListView View;
    PowerListModel Model;
};

}

#endif
