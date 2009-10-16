
'''Helper classes and functions for handling modules'''

class ClassInfo(object):
    '''Container of class information.
    
    Currently just the name and a sequence of member strings.
    '''

    def __init__(self, name):
        self.name = name
        self.members = []

    def __eq__(self, other):
        try:
            return self.name == other.name
        except AttributeError:
            return False

    def __hash__(self):
        return hash(self.name)

    def __repr__(self):
        return self.name


if __name__ == '__main__':
    a = ClassInfo('fff')
    a.members.append('aaaa')


    b = ClassInfo('fff')
    a.members.append('bbbb')

    a.freeze()
    b.freeze()

    print hash(a)
    print hash(b)

    print a == b

    print set([a]) & set([b])
