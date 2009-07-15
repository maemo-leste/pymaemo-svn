
/* Generated data (by glib-mkenums) */

/* -*- Mode: C; c-basic-offset: 4 -*-
 * python-mafw - Python bindings for the MAFW library.
 *
 * mafw-types: definitions that should be in mafw
 *               itself but are not yet.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

#include "mafw-types.h"

/* enumerations from "/usr/include/mafw-1.0/libmafw/mafw-renderer.h" */

GType
mafw_renderer_error_policy_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { MAFW_RENDERER_ERROR_POLICY_CONTINUE, "MAFW_RENDERER_ERROR_POLICY_CONTINUE", "continue" },
            { MAFW_RENDERER_ERROR_POLICY_STOP, "MAFW_RENDERER_ERROR_POLICY_STOP", "stop" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("MafwRendererErrorPolicy", values);
    }
    return etype;
}

GType
mafw_play_state_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { Stopped, "Stopped", "stopped" },
            { Playing, "Playing", "playing" },
            { Paused, "Paused", "paused" },
            { Transitioning, "Transitioning", "transitioning" },
            { _LastMafwPlayState, "_LastMafwPlayState", "-lastmafwplaystate" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("MafwPlayState", values);
    }
    return etype;
}

GType
mafw_renderer_seek_mode_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { SeekAbsolute, "SeekAbsolute", "absolute" },
            { SeekRelative, "SeekRelative", "relative" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("MafwRendererSeekMode", values);
    }
    return etype;
}


/* enumerations from "/usr/include/mafw-1.0/libmafw/mafw-filter.h" */

GType
mafw_filter_type_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { MAFW_F_INVALID, "MAFW_F_INVALID", "mafw-f-invalid" },
            { mafw_f_and, "mafw_f_and", "mafw-f-and" },
            { mafw_f_or, "mafw_f_or", "mafw-f-or" },
            { mafw_f_not, "mafw_f_not", "mafw-f-not" },
            { MAFW_F_COMPLEX, "MAFW_F_COMPLEX", "mafw-f-complex" },
            { mafw_f_exists, "mafw_f_exists", "mafw-f-exists" },
            { mafw_f_eq, "mafw_f_eq", "mafw-f-eq" },
            { mafw_f_lt, "mafw_f_lt", "mafw-f-lt" },
            { mafw_f_gt, "mafw_f_gt", "mafw-f-gt" },
            { mafw_f_approx, "mafw_f_approx", "mafw-f-approx" },
            { MAFW_F_LAST, "MAFW_F_LAST", "mafw-f-last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("MafwFilterType", values);
    }
    return etype;
}


/* enumerations from "/usr/include/mafw-1.0/libmafw/mafw-errors.h" */

GType
mafw_error_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { MAFW_ERROR_PLUGINS_NOT_SUPPORTED, "MAFW_ERROR_PLUGINS_NOT_SUPPORTED", "plugins-not-supported" },
            { MAFW_ERROR_PLUGIN_LOAD_FAILED, "MAFW_ERROR_PLUGIN_LOAD_FAILED", "plugin-load-failed" },
            { MAFW_ERROR_PLUGIN_INIT_FAILED, "MAFW_ERROR_PLUGIN_INIT_FAILED", "plugin-init-failed" },
            { MAFW_ERROR_PLUGIN_NAME_CONFLICT, "MAFW_ERROR_PLUGIN_NAME_CONFLICT", "plugin-name-conflict" },
            { MAFW_ERROR_PLUGIN_NOT_LOADED, "MAFW_ERROR_PLUGIN_NOT_LOADED", "plugin-not-loaded" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("MafwError", values);
    }
    return etype;
}

GType
mafw_extension_error_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { MAFW_EXTENSION_ERROR_EXTENSION_NOT_AVAILABLE, "MAFW_EXTENSION_ERROR_EXTENSION_NOT_AVAILABLE", "extension-not-available" },
            { MAFW_EXTENSION_ERROR_UNSUPPORTED_OPERATION, "MAFW_EXTENSION_ERROR_UNSUPPORTED_OPERATION", "unsupported-operation" },
            { MAFW_EXTENSION_ERROR_NETWORK_DOWN, "MAFW_EXTENSION_ERROR_NETWORK_DOWN", "network-down" },
            { MAFW_EXTENSION_ERROR_SERVICE_NOT_RESPONDING, "MAFW_EXTENSION_ERROR_SERVICE_NOT_RESPONDING", "service-not-responding" },
            { MAFW_EXTENSION_ERROR_EXTENSION_NOT_RESPONDING, "MAFW_EXTENSION_ERROR_EXTENSION_NOT_RESPONDING", "extension-not-responding" },
            { MAFW_EXTENSION_ERROR_INVALID_PROPERTY, "MAFW_EXTENSION_ERROR_INVALID_PROPERTY", "invalid-property" },
            { MAFW_EXTENSION_ERROR_SET_PROPERTY, "MAFW_EXTENSION_ERROR_SET_PROPERTY", "set-property" },
            { MAFW_EXTENSION_ERROR_GET_PROPERTY, "MAFW_EXTENSION_ERROR_GET_PROPERTY", "get-property" },
            { MAFW_EXTENSION_ERROR_ACCESS_DENIED, "MAFW_EXTENSION_ERROR_ACCESS_DENIED", "access-denied" },
            { MAFW_EXTENSION_ERROR_INVALID_PARAMS, "MAFW_EXTENSION_ERROR_INVALID_PARAMS", "invalid-params" },
            { MAFW_EXTENSION_ERROR_OUT_OF_MEMORY, "MAFW_EXTENSION_ERROR_OUT_OF_MEMORY", "out-of-memory" },
            { MAFW_EXTENSION_ERROR_FAILED, "MAFW_EXTENSION_ERROR_FAILED", "failed" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("MafwExtensionError", values);
    }
    return etype;
}

GType
mafw_playlist_error_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { MAFW_PLAYLIST_ERROR_DATABASE, "MAFW_PLAYLIST_ERROR_DATABASE", "database" },
            { MAFW_PLAYLIST_ERROR_INVALID_NAME, "MAFW_PLAYLIST_ERROR_INVALID_NAME", "invalid-name" },
            { MAFW_PLAYLIST_ERROR_INVALID_INDEX, "MAFW_PLAYLIST_ERROR_INVALID_INDEX", "invalid-index" },
            { MAFW_PLAYLIST_ERROR_PLAYLIST_NOT_FOUND, "MAFW_PLAYLIST_ERROR_PLAYLIST_NOT_FOUND", "playlist-not-found" },
            { MAFW_PLAYLIST_ERROR_IMPORT_FAILED, "MAFW_PLAYLIST_ERROR_IMPORT_FAILED", "import-failed" },
            { MAFW_PLAYLIST_ERROR_INVALID_IMPORT_ID, "MAFW_PLAYLIST_ERROR_INVALID_IMPORT_ID", "invalid-import-id" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("MafwPlaylistError", values);
    }
    return etype;
}

GType
mafw_renderer_error_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { MAFW_RENDERER_ERROR_NO_MEDIA, "MAFW_RENDERER_ERROR_NO_MEDIA", "no-media" },
            { MAFW_RENDERER_ERROR_URI_NOT_AVAILABLE, "MAFW_RENDERER_ERROR_URI_NOT_AVAILABLE", "uri-not-available" },
            { MAFW_RENDERER_ERROR_INVALID_URI, "MAFW_RENDERER_ERROR_INVALID_URI", "invalid-uri" },
            { MAFW_RENDERER_ERROR_MEDIA_NOT_FOUND, "MAFW_RENDERER_ERROR_MEDIA_NOT_FOUND", "media-not-found" },
            { MAFW_RENDERER_ERROR_STREAM_DISCONNECTED, "MAFW_RENDERER_ERROR_STREAM_DISCONNECTED", "stream-disconnected" },
            { MAFW_RENDERER_ERROR_TYPE_NOT_AVAILABLE, "MAFW_RENDERER_ERROR_TYPE_NOT_AVAILABLE", "type-not-available" },
            { MAFW_RENDERER_ERROR_UNSUPPORTED_TYPE, "MAFW_RENDERER_ERROR_UNSUPPORTED_TYPE", "unsupported-type" },
            { MAFW_RENDERER_ERROR_DRM, "MAFW_RENDERER_ERROR_DRM", "drm" },
            { MAFW_RENDERER_ERROR_DEVICE_UNAVAILABLE, "MAFW_RENDERER_ERROR_DEVICE_UNAVAILABLE", "device-unavailable" },
            { MAFW_RENDERER_ERROR_CORRUPTED_FILE, "MAFW_RENDERER_ERROR_CORRUPTED_FILE", "corrupted-file" },
            { MAFW_RENDERER_ERROR_PLAYLIST_PARSING, "MAFW_RENDERER_ERROR_PLAYLIST_PARSING", "playlist-parsing" },
            { MAFW_RENDERER_ERROR_CODEC_NOT_FOUND, "MAFW_RENDERER_ERROR_CODEC_NOT_FOUND", "codec-not-found" },
            { MAFW_RENDERER_ERROR_NO_PLAYLIST, "MAFW_RENDERER_ERROR_NO_PLAYLIST", "no-playlist" },
            { MAFW_RENDERER_ERROR_INDEX_OUT_OF_BOUNDS, "MAFW_RENDERER_ERROR_INDEX_OUT_OF_BOUNDS", "index-out-of-bounds" },
            { MAFW_RENDERER_ERROR_CANNOT_PLAY, "MAFW_RENDERER_ERROR_CANNOT_PLAY", "cannot-play" },
            { MAFW_RENDERER_ERROR_CANNOT_STOP, "MAFW_RENDERER_ERROR_CANNOT_STOP", "cannot-stop" },
            { MAFW_RENDERER_ERROR_CANNOT_PAUSE, "MAFW_RENDERER_ERROR_CANNOT_PAUSE", "cannot-pause" },
            { MAFW_RENDERER_ERROR_CANNOT_SET_POSITION, "MAFW_RENDERER_ERROR_CANNOT_SET_POSITION", "cannot-set-position" },
            { MAFW_RENDERER_ERROR_CANNOT_GET_POSITION, "MAFW_RENDERER_ERROR_CANNOT_GET_POSITION", "cannot-get-position" },
            { MAFW_RENDERER_ERROR_CANNOT_GET_STATUS, "MAFW_RENDERER_ERROR_CANNOT_GET_STATUS", "cannot-get-status" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("MafwRendererError", values);
    }
    return etype;
}

GType
mafw_source_error_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { MAFW_SOURCE_ERROR_INVALID_OBJECT_ID, "MAFW_SOURCE_ERROR_INVALID_OBJECT_ID", "invalid-object-id" },
            { MAFW_SOURCE_ERROR_OBJECT_ID_NOT_AVAILABLE, "MAFW_SOURCE_ERROR_OBJECT_ID_NOT_AVAILABLE", "object-id-not-available" },
            { MAFW_SOURCE_ERROR_INVALID_SEARCH_STRING, "MAFW_SOURCE_ERROR_INVALID_SEARCH_STRING", "invalid-search-string" },
            { MAFW_SOURCE_ERROR_INVALID_SORT_STRING, "MAFW_SOURCE_ERROR_INVALID_SORT_STRING", "invalid-sort-string" },
            { MAFW_SOURCE_ERROR_INVALID_BROWSE_ID, "MAFW_SOURCE_ERROR_INVALID_BROWSE_ID", "invalid-browse-id" },
            { MAFW_SOURCE_ERROR_PEER, "MAFW_SOURCE_ERROR_PEER", "peer" },
            { MAFW_SOURCE_ERROR_BROWSE_RESULT_FAILED, "MAFW_SOURCE_ERROR_BROWSE_RESULT_FAILED", "browse-result-failed" },
            { MAFW_SOURCE_ERROR_GET_METADATA_RESULT_FAILED, "MAFW_SOURCE_ERROR_GET_METADATA_RESULT_FAILED", "get-metadata-result-failed" },
            { MAFW_SOURCE_ERROR_UNSUPPORTED_METADATA_KEY, "MAFW_SOURCE_ERROR_UNSUPPORTED_METADATA_KEY", "unsupported-metadata-key" },
            { MAFW_SOURCE_ERROR_DESTROY_OBJECT_FAILED, "MAFW_SOURCE_ERROR_DESTROY_OBJECT_FAILED", "destroy-object-failed" },
            { MAFW_SOURCE_ERROR_PLAYLIST_PARSING_FAILED, "MAFW_SOURCE_ERROR_PLAYLIST_PARSING_FAILED", "playlist-parsing-failed" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("MafwSourceError", values);
    }
    return etype;
}


/* Generated data ends here */

