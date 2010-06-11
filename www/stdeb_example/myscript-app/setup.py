
from distutils.core import setup


setup(
    name='myscript',
    author='Lauro Moura',
    author_email='lauro.neto@donotspam.org',
    scripts=['myscript'],
    data_files=[('share/applications/hildon', ['myscript.desktop']),
                ('share/pixmaps', ['myscript.png'])],
)
