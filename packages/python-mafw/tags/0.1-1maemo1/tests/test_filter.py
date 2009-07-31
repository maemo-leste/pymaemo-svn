
import unittest

import mafw

class FilterParse(unittest.TestCase):
    def testBasic(self):
        fi = mafw.Filter.parse('(artist=belga')

        self.assertEqual(fi.type(), mafw.F_EQ)
        self.assertEqual(fi.key(), 'artist')
        self.assertEqual(fi.value(), 'belga')

        fi = mafw.Filter('(publication-year<1999)')
        self.assertEqual(fi.type(), mafw.F_LT)
        self.assertEqual(fi.key(), 'publication-year')
        self.assertEqual(fi.value(), '1999')

    def testNoValue(self):
        fi = mafw.Filter.parse('(album?)')
        self.assertEqual(fi.type(), mafw.F_EXISTS)
        self.assertEqual(fi.key(), 'album')
        self.assertEqual(fi.value(), '')

    def testInvalid(self):
        self.assertRaises(ValueError, mafw.Filter.parse, '=belga)')
        self.assertRaises(ValueError, mafw.Filter.parse, '(&(foo=bar()(xxx>yyy')
        self.assertRaises(ValueError, mafw.Filter.parse, '(title!=something)')
        self.assertRaises(ValueError, mafw.Filter.parse, '(!=titlesomething)')
        self.assertRaises(ValueError, mafw.Filter.parse, '!(title=something)')
        self.assertRaises(ValueError, mafw.Filter.parse, '((title=something))')

    def testComplexNot(self):
        fi = mafw.Filter.parse('(!(year>2004))')

        self.assertEqual(fi.type(), mafw.F_NOT)
        for part in fi.parts:
            self.assert_(isinstance(part, mafw.Filter))
        self.assertEqual(fi.parts[0].type(), mafw.F_GT)
        self.assertEqual(fi.parts[0].key(), 'year')
        self.assertEqual(fi.parts[0].value(), '2004')

    def testComplexNotSingleExpression(self):
        self.assertRaises(ValueError, mafw.Filter.parse,
                '(!(year>2004)(foo=bar))')

class TestConstructor(unittest.TestCase):
    def testNoArg(self):
        self.assertRaises(TypeError, mafw.Filter)

    def testJustType(self):
        fi = mafw.Filter(mafw.F_EQ)
        self.assert_(isinstance(fi, mafw.Filter))
        self.assertEqual(fi.type(), mafw.F_EQ)
        self.assertEqual(fi.key(), '')
        self.assertEqual(fi.value(), '')

    def testWithKey(self):
        fi = mafw.Filter(mafw.F_EQ, 'key')
        self.assert_(isinstance(fi, mafw.Filter))
        self.assertEqual(fi.type(), mafw.F_EQ)
        self.assertEqual(fi.key(), 'key')
        self.assertEqual(fi.value(), '')

    def testWithPair(self):
        fi = mafw.Filter(mafw.F_EQ, 'key', 'value')
        self.assert_(isinstance(fi, mafw.Filter))
        self.assertEqual(fi.type(), mafw.F_EQ)
        self.assertEqual(fi.key(), 'key')
        self.assertEqual(fi.value(), 'value')

class TestAddChildren(unittest.TestCase):
    def testSimple(self):
        fi = mafw.Filter(mafw.F_AND)
        self.assertEqual(len(fi.parts), 0)

        fi.add_children(mafw.Filter(mafw.F_EQ, 'att', 'vvv'))
        self.assertEqual(len(fi.parts), 1)

        fi.add_children(mafw.Filter(mafw.F_LT, 'yyy', 'xxx'))
        self.assertEqual(len(fi.parts), 2)

        self.assertEqual(fi.parts[0].key(), 'att')
        self.assertEqual(fi.parts[0].value(), 'vvv')

        self.assertEqual(fi.parts[1].type(), mafw.F_LT)
        self.assertEqual(fi.parts[1].key(), 'yyy')
        self.assertEqual(fi.parts[1].value(), 'xxx')


if __name__ == '__main__':
    unittest.main()
