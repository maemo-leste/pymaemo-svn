import fileinput

html_pages = ['index',
              'pict1',
              'pict2',
              'pict3',
              'pict4',
              'pict5',
              'pict6',
              'pymaemo25_releasenotes']

def inject_page (dest_file, page):
    src_file = open(page + '.html', 'r')

    line = src_file.readline()
    while len(line) != 0:
        dest_file.write(line)
        line = src_file.readline()
    dest_file.write('\n')

def build_page (page):
    dest_file = open('../' + page + '.html', 'w')

    for line in fileinput.input("template.html"):
        if line.find("<!-- Actual content must be injected here [DO NOT CHANGE THIS LINE!] -->") != -1:
            inject_page(dest_file, page)
        else:
            dest_file.write(line)


for page in html_pages:
    build_page (page)