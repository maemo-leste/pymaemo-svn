#!/usr/bin/env python2.5

import unittest
import hildonmime
import gtk

class TestHildonMime(unittest.TestCase):
    def setUp(self):
        self.categories = [x for x in dir(hildonmime)
                             if x.startswith("MIME_CATE") and
                                not (x.endswith("_ALL") or
                                     x.endswith("_OTHER"))]

    def tearDown(self):
        pass

    def testTypesAndCategories(self):

        types = hildonmime.get_mime_types_for_category(
                        hildonmime.MIME_CATEGORY_OTHER)
        self.assertEqual(types, [])

        self.assertRaises(TypeError, hildonmime.get_mime_types_for_category,
                          None)

        for category in self.categories:
            types = hildonmime.get_mime_types_for_category(getattr(hildonmime, category))

            for type in types:
                category2 = hildonmime.get_category_for_mime_type(type)
                print category2
                self.assertEqual(category, category2)

    def testCategoryName(self):
        for category in self.categories:
            cat = getattr(hildonmime, category)
            name = hildonmime.get_category_name(cat)
            self.assertNotEqual(name, None)
            category2 = hildonmime.get_category_from_name(name)
            self.assertEqual(cat, category2)

    def testApplicationMimeTypes(self):
        pass

if __name__ == "__main__":
    unittest.main()
