import hildon
import hildondesktop
import gtk
import gobject

class TimeOutPlugin(hildondesktop.HomePluginItem):
    __gtype_name__ = 'TimeOutPlugin'

    def __init__(self):
        hildondesktop.HomePluginItem.__init__(self)
        self.build_ui()
        
    def build_ui(self):
        contents = gtk.VBox(0, False)
        label = gtk.Label("Time out applet.")
        action = hildon.PickerButton(hildon.SIZE_FINGER_HEIGHT,
                                     hildon.BUTTON_ARRANGEMENT_VERTICAL)

        action_selector = hildon.hildon_touch_selector_new_text()
        action.set_title("Action")
        action_selector.append_text("Blank Screen")
        action_selector.append_text("Suspend")
        action_selector.append_text("Turn Off")

        action.set_selector(action_selector)
        action.set_active(0)


        time = hildon.TimeButton(hildon.SIZE_FINGER_HEIGHT,
                                 hildon.BUTTON_ARRANGEMENT_VERTICAL)
        time.set_time(22, 00)

        buttons = gtk.HBox(0, True)
        buttons.add(action)
        buttons.add(time)

        contents.pack_start(label, False, False, 0)
        contents.pack_end(buttons, False, False, 0)

        contents.show_all()

        self.add(contents)

def hd_plugin_get_object():
    return gobject.new(TimeOutPlugin, plugin_id="TimeOutPlugin")

if __name__ == "__main__":
    obj = hd_plugin_get_object()
    obj.show_all()
    gtk.main()



