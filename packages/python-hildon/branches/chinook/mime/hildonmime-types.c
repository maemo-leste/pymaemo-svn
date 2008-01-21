
#include "hildonmime-types.h"
/* Generated data (by glib-mkenums) */


/* enumerations from "/usr/include/hildon-mime.h" */
GType
hildon_mime_category_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { HILDON_MIME_CATEGORY_BOOKMARKS, "HILDON_MIME_CATEGORY_BOOKMARKS", "bookmarks" },
      { HILDON_MIME_CATEGORY_CONTACTS, "HILDON_MIME_CATEGORY_CONTACTS", "contacts" },
      { HILDON_MIME_CATEGORY_DOCUMENTS, "HILDON_MIME_CATEGORY_DOCUMENTS", "documents" },
      { HILDON_MIME_CATEGORY_EMAILS, "HILDON_MIME_CATEGORY_EMAILS", "emails" },
      { HILDON_MIME_CATEGORY_IMAGES, "HILDON_MIME_CATEGORY_IMAGES", "images" },
      { HILDON_MIME_CATEGORY_AUDIO, "HILDON_MIME_CATEGORY_AUDIO", "audio" },
      { HILDON_MIME_CATEGORY_VIDEO, "HILDON_MIME_CATEGORY_VIDEO", "video" },
      { HILDON_MIME_CATEGORY_OTHER, "HILDON_MIME_CATEGORY_OTHER", "other" },
      { HILDON_MIME_CATEGORY_ALL, "HILDON_MIME_CATEGORY_ALL", "all" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("HildonMimeCategory", values);
  }
  return etype;
}

/* Generated data ends here */

