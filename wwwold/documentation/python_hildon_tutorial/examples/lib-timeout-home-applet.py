import hildon
import hildondesktop
import gtk


class ExampleStatusPlugin(hildondesktop.StatusMenuItem):
    __gtype_name__ = 'Example'

    def __init__(self):
        hildondesktop.StatusMenuItem.__init__(self)
        self.build_ui()
        

    def build_ui(self):
        STATUS_AREA_EXAMPLE_ICON_SIZE = 64

        icon_theme = gtk.icon_theme_get_default()
        pixbuf = icon_theme.load_icon("general_email",
                                      STATUS_AREA_EXAMPLE_ICON_SIZE,
                                      gtk.ICON_LOOKUP_NO_SVG)

        self.set_status_area_icon(pixbuf)

        b = gtk.Label("Example message")
        b.show_all()

        self.add(b)
        self.show()

def hd_plugin_get_object():
    return gobject.new(ExampleStatusPlugin, plugin_id="Example")

if __name__ == "__main__":
    obj = hd_plugin_get_object()
    obj.show_all()
    gtk.main()



