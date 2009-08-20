/* -*- Mode: C; c-basic-offset: 4 -*-
 * python-mafw - Python bindings for the MAFW library.
 *
 *   mafwmodule.c: module wrapping the MAFW library.
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

#include <Python.h>

#include <pygobject.h>
#include <libmafw/mafw-metadata.h>

void pymafw_register_classes(PyObject *d);
extern void pymafw_add_constants(PyObject *module, const gchar *strip_prefix);
extern PyMethodDef pymafw_functions[];

DL_EXPORT(void)
initmafw(void)
{
    PyObject *m, *d;

    m = Py_InitModule("mafw", pymafw_functions);
    d = PyModule_GetDict(m);

    init_pygobject();

    PyModule_AddStringConstant(m, "METADATA_KEY_ADDED",  MAFW_METADATA_KEY_ADDED);
    PyModule_AddStringConstant(m, "METADATA_KEY_MODIFIED",  MAFW_METADATA_KEY_MODIFIED);
    PyModule_AddStringConstant(m, "METADATA_KEY_ALBUM",  MAFW_METADATA_KEY_ALBUM);
    PyModule_AddStringConstant(m, "METADATA_KEY_ALBUM_INFO_URI",  MAFW_METADATA_KEY_ALBUM_INFO_URI);
    PyModule_AddStringConstant(m, "METADATA_KEY_ALBUM_ART",  MAFW_METADATA_KEY_ALBUM_ART);
    PyModule_AddStringConstant(m, "METADATA_KEY_ALBUM_ART_URI",  MAFW_METADATA_KEY_ALBUM_ART_URI);
    PyModule_AddStringConstant(m, "METADATA_KEY_ALBUM_ART_LARGE_URI",  MAFW_METADATA_KEY_ALBUM_ART_LARGE_URI);
    PyModule_AddStringConstant(m, "METADATA_KEY_ALBUM_ART_MEDIUM_URI",  MAFW_METADATA_KEY_ALBUM_ART_MEDIUM_URI);
    PyModule_AddStringConstant(m, "METADATA_KEY_ALBUM_ART_SMALL_URI",  MAFW_METADATA_KEY_ALBUM_ART_SMALL_URI);
    PyModule_AddStringConstant(m, "METADATA_KEY_RENDERER_ART_URI",  MAFW_METADATA_KEY_RENDERER_ART_URI);
    PyModule_AddStringConstant(m, "METADATA_KEY_ORGANIZATION",  MAFW_METADATA_KEY_ORGANIZATION);
    PyModule_AddStringConstant(m, "METADATA_KEY_PAUSED_POSITION",  MAFW_METADATA_KEY_PAUSED_POSITION);
    PyModule_AddStringConstant(m, "METADATA_KEY_PAUSED_THUMBNAIL_URI",  MAFW_METADATA_KEY_PAUSED_THUMBNAIL_URI);
    PyModule_AddStringConstant(m, "METADATA_KEY_VIDEO_SOURCE",  MAFW_METADATA_KEY_VIDEO_SOURCE);
    PyModule_AddStringConstant(m, "METADATA_KEY_ARTIST",  MAFW_METADATA_KEY_ARTIST);
    PyModule_AddStringConstant(m, "METADATA_KEY_ARTIST_INFO_URI",  MAFW_METADATA_KEY_ARTIST_INFO_URI);
    PyModule_AddStringConstant(m, "METADATA_KEY_AUDIO_BITRATE",  MAFW_METADATA_KEY_AUDIO_BITRATE);
    PyModule_AddStringConstant(m, "METADATA_KEY_AUDIO_CODEC",  MAFW_METADATA_KEY_AUDIO_CODEC);
    PyModule_AddStringConstant(m, "METADATA_KEY_BITRATE",  MAFW_METADATA_KEY_BITRATE);
    PyModule_AddStringConstant(m, "METADATA_KEY_BPP",  MAFW_METADATA_KEY_BPP);
    PyModule_AddStringConstant(m, "METADATA_KEY_CHILDCOUNT_1",  MAFW_METADATA_KEY_CHILDCOUNT_1);
    PyModule_AddStringConstant(m, "METADATA_KEY_CHILDCOUNT_2",  MAFW_METADATA_KEY_CHILDCOUNT_2);
    PyModule_AddStringConstant(m, "METADATA_KEY_CHILDCOUNT_3",  MAFW_METADATA_KEY_CHILDCOUNT_3);
    PyModule_AddStringConstant(m, "METADATA_KEY_CHILDCOUNT_4",  MAFW_METADATA_KEY_CHILDCOUNT_4);
    PyModule_AddStringConstant(m, "METADATA_KEY_CHILDCOUNT_5",  MAFW_METADATA_KEY_CHILDCOUNT_5);
    PyModule_AddStringConstant(m, "METADATA_KEY_CHILDCOUNT_6",  MAFW_METADATA_KEY_CHILDCOUNT_6);
    PyModule_AddStringConstant(m, "METADATA_KEY_CHILDCOUNT_7",  MAFW_METADATA_KEY_CHILDCOUNT_7);
    PyModule_AddStringConstant(m, "METADATA_KEY_CHILDCOUNT_8",  MAFW_METADATA_KEY_CHILDCOUNT_8);
    PyModule_AddStringConstant(m, "METADATA_KEY_CHILDCOUNT_9",  MAFW_METADATA_KEY_CHILDCOUNT_9);
    PyModule_AddStringConstant(m, "METADATA_KEY_COMMENT",  MAFW_METADATA_KEY_COMMENT);
    PyModule_AddStringConstant(m, "METADATA_KEY_COMPOSER",  MAFW_METADATA_KEY_COMPOSER);
    PyModule_AddStringConstant(m, "METADATA_KEY_COPYRIGHT",  MAFW_METADATA_KEY_COPYRIGHT);
    PyModule_AddStringConstant(m, "METADATA_KEY_COUNT",  MAFW_METADATA_KEY_COUNT);
    PyModule_AddStringConstant(m, "METADATA_KEY_DESCRIPTION",  MAFW_METADATA_KEY_DESCRIPTION);
    PyModule_AddStringConstant(m, "METADATA_KEY_DIDL",  MAFW_METADATA_KEY_DIDL);
    PyModule_AddStringConstant(m, "METADATA_KEY_DURATION",  MAFW_METADATA_KEY_DURATION);
    PyModule_AddStringConstant(m, "METADATA_KEY_ENCODING",  MAFW_METADATA_KEY_ENCODING);
    PyModule_AddStringConstant(m, "METADATA_KEY_EXIF_XML",  MAFW_METADATA_KEY_EXIF_XML);
    PyModule_AddStringConstant(m, "METADATA_KEY_FILENAME",  MAFW_METADATA_KEY_FILENAME);
    PyModule_AddStringConstant(m, "METADATA_KEY_FILESIZE",  MAFW_METADATA_KEY_FILESIZE);
    PyModule_AddStringConstant(m, "METADATA_KEY_GENRE",  MAFW_METADATA_KEY_GENRE);
    PyModule_AddStringConstant(m, "METADATA_KEY_ICON",  MAFW_METADATA_KEY_ICON);
    PyModule_AddStringConstant(m, "METADATA_KEY_ICON_URI",  MAFW_METADATA_KEY_ICON_URI);
    PyModule_AddStringConstant(m, "METADATA_KEY_IS_SEEKABLE",  MAFW_METADATA_KEY_IS_SEEKABLE);
    PyModule_AddStringConstant(m, "METADATA_KEY_LAST_PLAYED",  MAFW_METADATA_KEY_LAST_PLAYED);
    PyModule_AddStringConstant(m, "METADATA_KEY_LYRICS",  MAFW_METADATA_KEY_LYRICS);
    PyModule_AddStringConstant(m, "METADATA_KEY_LYRICS_URI",  MAFW_METADATA_KEY_LYRICS_URI);
    PyModule_AddStringConstant(m, "METADATA_KEY_PLAY_COUNT",  MAFW_METADATA_KEY_PLAY_COUNT);
    PyModule_AddStringConstant(m, "METADATA_KEY_PROTOCOL_INFO",  MAFW_METADATA_KEY_PROTOCOL_INFO);
    PyModule_AddStringConstant(m, "METADATA_KEY_RATING",  MAFW_METADATA_KEY_RATING);
    PyModule_AddStringConstant(m, "METADATA_KEY_RES_X",  MAFW_METADATA_KEY_RES_X);
    PyModule_AddStringConstant(m, "METADATA_KEY_RES_Y",  MAFW_METADATA_KEY_RES_Y);
    PyModule_AddStringConstant(m, "METADATA_KEY_TAGS",  MAFW_METADATA_KEY_TAGS);
    PyModule_AddStringConstant(m, "METADATA_KEY_THUMBNAIL",  MAFW_METADATA_KEY_THUMBNAIL);
    PyModule_AddStringConstant(m, "METADATA_KEY_THUMBNAIL_URI",  MAFW_METADATA_KEY_THUMBNAIL_URI);
    PyModule_AddStringConstant(m, "METADATA_KEY_TITLE",  MAFW_METADATA_KEY_TITLE);
    PyModule_AddStringConstant(m, "METADATA_KEY_TRACK",  MAFW_METADATA_KEY_TRACK);
    PyModule_AddStringConstant(m, "METADATA_KEY_VIDEO_BITRATE",  MAFW_METADATA_KEY_VIDEO_BITRATE);
    PyModule_AddStringConstant(m, "METADATA_KEY_VIDEO_CODEC",  MAFW_METADATA_KEY_VIDEO_CODEC);
    PyModule_AddStringConstant(m, "METADATA_KEY_VIDEO_FRAMERATE",  MAFW_METADATA_KEY_VIDEO_FRAMERATE);
    PyModule_AddStringConstant(m, "METADATA_KEY_YEAR",  MAFW_METADATA_KEY_YEAR);
    PyModule_AddStringConstant(m, "METADATA_KEY_MIME",  MAFW_METADATA_KEY_MIME);
    PyModule_AddStringConstant(m, "METADATA_KEY_URI",  MAFW_METADATA_KEY_URI);
    PyModule_AddStringConstant(m, "METADATA_VALUE_MIME_CONTAINER",  MAFW_METADATA_VALUE_MIME_CONTAINER);
    
    pymafw_register_classes(d);
    pymafw_add_constants(m, "MAFW_");
}
