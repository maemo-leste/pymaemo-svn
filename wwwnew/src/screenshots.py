from docutils import nodes, utils

def setup(app):
    def screenshots_role(role, rawtext, text, lineno, inliner, options={},
                      content=[]):
        thumbnail = text.replace("_thumb", "")
        htmlcode = "<a href=\"%s\" class=\"highslide\" onclick=\"return hs.expand(this);\"><img src=\"%s\" title=\"Click to enlarge\" /></a>\n" % (thumbnail, text)

        node = nodes.raw('', htmlcode, format='html')
        return [node], []
    app.add_role('screenshots', screenshots_role)
